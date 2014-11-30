/*
 * matchers.hpp
 * author: Mikhail Beliaev
 *
 * ML-style pattern matching for C++
 * As ambitious as that
 * Ideas based on scala pattern matching and std::bind
 */

#ifndef MATCHERS_HPP_
#define MATCHERS_HPP_

#include <tuple>

#include "matchers/match_structures.hpp"
#include "matchers/meta.hpp"

namespace functional_hell {
namespace matchers {

// a type you should return from unapply()
template<class ...Elems> using storage_t = match_result<impl_::wrapped_t<Elems>...>;

template<class ...Elems>
storage_t<Elems...> make_storage(Elems&&... elems) {
    return storage_t<Elems...>{ std::forward<Elems>(elems)... };
}

/*************************************************************************************************/

namespace impl_ {

/*************************************************************************************************/

// calculate the magic tuple type by placeholders
template<class Tuple, class ...Args> struct applicate;
template<class Head, class ...Tail, class Arg0, class ...Args>
struct applicate< match_result<Head, Tail...>, Arg0, Args... > {
    using elements = typename Arg0::template elements<Head>;
    using type = merge_all_t<elements, typename applicate< match_result<Tail...>, Args... >::type >;
};
template<>
struct applicate< match_result<> > {
    using type = merge_all_t<>;
};
template<class Head, class ...Tail, class Arg0, class ...Args>
struct applicate< const match_result<Head, Tail...>, Arg0, Args... > {
    using elements = typename Arg0::template elements<Head>;
    using type = merge_all_t<elements, typename applicate< const match_result<Tail...>, Args... >::type >;
};
template<>
struct applicate< const match_result<> > {
    using type = merge_all_t<>;
};
template<class It, class Arg0, class ...Args>
struct applicate< match_sequence<It>, Arg0, Args... > {
    using single = decltype(*std::declval<It>());
    using elements = typename Arg0::template elements<impl_::wrapped_t<single>>;
    using type = merge_all_t<elements, typename applicate< match_sequence<It>, Args... >::type >;
};
template<class It>
struct applicate< match_sequence<It> > {
    using type = merge_all_t<>;
};


/*************************************************************************************************/

// call unapply_impl on all tree elements
template<std::size_t S, class Storage, class MatchRes, class ...Args>
struct unapplier {
    static constexpr std::size_t K = sizeof...(Args) - S;
    static bool doIt(const std::tuple<Args...>& matchers, Storage& storage, MatchRes&& mres) {
        if(!std::get<K>(matchers).unapply_impl(storage, get<K>(mres))) return false;
        return unapplier<S-1, Storage, MatchRes, Args...>
            ::doIt(matchers, storage, std::forward<MatchRes>(mres));
    }
};
template<class Storage, class MatchRes, class ...Args>
struct unapplier<0, Storage, MatchRes, Args...> {
    static bool doIt(const std::tuple<Args...>& matchers, Storage&, MatchRes&&) {
        return true;
    }
};

// call unapply_impl on all tree elements
template<std::size_t S, class Storage, class MatchIter, class ...Args>
struct seq_unapplier {
    static constexpr std::size_t K = sizeof...(Args) - S;
    static bool doIt(const std::tuple<Args...>& matchers, Storage& storage, MatchIter begin, MatchIter end) {
        if(begin == end) return false;
        if(!std::get<K>(matchers).unapply_impl(storage, *begin)) return false;
        return seq_unapplier<S-1, Storage, MatchIter, Args...>
            ::doIt(matchers, storage, ++begin, end);
    }
};
template<class Storage, class MatchIter, class ...Args>
struct seq_unapplier<0, Storage, MatchIter, Args...> {
    static bool doIt(const std::tuple<Args...>& matchers, Storage&, MatchIter begin, MatchIter end) {
        return begin == end;
    }
};
/*************************************************************************************************/

template<class T> struct no_ref_c { using type = T; };
template<class T> struct no_ref_c<T&> { using type = T; };
template<class T> struct no_ref_c<T&&> { using type = T; };
template<class T> struct no_ref_c<match_reference<T>> { using type = T; };
template<class T> struct no_ref_c<match_reference<T>&> { using type = T; };
template<class T> struct no_ref_c<const match_reference<T>&> { using type = T; };
template<class T> struct no_ref_c<match_reference<T>&&> { using type = T; };

template<class T> using no_ref = typename no_ref_c<T>::type;

template<class T> struct lower_ref { using type = T; };
template<class T> struct lower_ref<match_reference<T>> { using type = T&; };
template<class T> struct lower_ref<match_reference<T>&> { using type = T&; };
template<class T> struct lower_ref<match_reference<T>&&> { using type = T&; };

template<class T> using lower_ref_t = typename lower_ref<T>::type;

template< class T >
T& unwrap( T& t ) {
    return t;
}
template<class T>
T& unwrap(match_reference<T> ref) {
    return ref.get();
}

/*************************************************************************************************/

} /* namespace impl_ */

/*************************************************************************************************/

struct matcher {};

/*************************************************************************************************/

// matcher for constants: matching is essentially an equality check
template<class H>
struct constant_matcher: matcher {
    template<class V> using elements = impl_::nil_map;

    impl_::wrapped_t<H> data;

    constant_matcher(H h): data(h) {};

    template<class T, class V>
    bool unapply_impl(T&, V&& value) const{
        return data == std::forward<V>(value);
    }
};

namespace impl_ {

template<class T, class = void>
struct toMatcher;

template<class T>
struct toMatcher<T, typename std::enable_if<std::is_base_of<matcher, T>::value>::type> {
    using type = T;
};

template<class T>
struct toMatcher<T, typename std::enable_if<!std::is_base_of<matcher, T>::value>::type> {
    using type = constant_matcher<T>;
};

template<class T>
using toMatcher_t = typename toMatcher<T>::type;

} /* namespace impl_ */

/*************************************************************************************************/

template<class Matcher>
struct expand_matcher: matcher {
    Matcher base;

    expand_matcher(Matcher base): base(base) {};

};

/*************************************************************************************************/

// matcher for complex structures with unapply and such: matching boils down to breaking values
// with unapply and passing results to lower-level matchers
template<class Lam, class ...Args>
struct tree_matcher: matcher {

    Lam lam;
    std::tuple<impl_::toMatcher_t<Args>...> matchers;

    tree_matcher(Lam lam, Args... args): lam(lam), matchers{ args... } {}

    template<class V>
    using unapplied = decltype(
        lam.unapply(std::forward<impl_::lower_ref_t<V>>(std::declval<impl_::lower_ref_t<V>>()))
    );

    template<class V>
    using elements = typename impl_::applicate< unapplied<V>, impl_::toMatcher_t<Args>... >::type;

    template<class T, class V>
    bool unapply_impl(T& storage, V&& v) const {
        auto ret = lam.unapply(impl_::unwrap(v));
        if(!ret) return false;

        return impl_::unapplier<sizeof...(Args), T, decltype(ret), impl_::toMatcher_t<Args>...>
            ::doIt(matchers, storage, std::move(ret));
    }

    template<class V>
    impl_::map2result_t<elements<V>> match(V&& v) const{
        impl_::map2result_t<elements<V>> ret;
        ret.construct();

        if(!unapply_impl(ret, std::forward<V>(v))) return impl_::map2result_t<elements<V>>();

        return std::move(ret);
    }

    template<class V>
    impl_::map2result_t<elements<V>> operator >> (V&& v) const{
        return match(std::forward<V>(v));
    }

    expand_matcher<tree_matcher> operator*() const {
        return expand_matcher<tree_matcher>{*this};
    }

};


/*************************************************************************************************/

// matcher for sequences
template<class ...Args>
struct seq_matcher: matcher {

    std::tuple<impl_::toMatcher_t<Args>...> matchers;

    seq_matcher(Args... args): matchers{ args... } {}

    template<class V>
    using unapplied = decltype(
        std::begin(std::forward<impl_::lower_ref_t<V>>(std::declval<impl_::lower_ref_t<V>>()))
    );

    template<class V>
    using elements = typename impl_::applicate< match_sequence<unapplied<V>>, impl_::toMatcher_t<Args>... >::type;

    template<class T, class V>
    bool unapply_impl(T& storage, V&& v) const {

        return impl_::seq_unapplier<sizeof...(Args), T, unapplied<V>, impl_::toMatcher_t<Args>...>
            ::doIt(matchers, storage, std::begin(impl_::unwrap(v)), std::end(impl_::unwrap(v)));
    }

    template<class V>
    impl_::map2result_t<elements<V>> match(V&& v) const{
        impl_::map2result_t<elements<V>> ret;
        ret.construct();

        if(!unapply_impl(ret, std::forward<V>(v))) return impl_::map2result_t<elements<V>>();

        return std::move(ret);
    }

    template<class V>
    impl_::map2result_t<elements<V>> operator >> (V&& v) const{
        return match(std::forward<V>(v));
    }

    expand_matcher<seq_matcher> operator*() const {
        return expand_matcher<seq_matcher>{*this};
    }

};

namespace impl_ {

template<class SM, class A>
struct arg_append_c;
template<class A, class ...Args>
struct arg_append_c<seq_matcher<Args...>, A> {
    typedef seq_matcher<Args..., A> type;
};
template<class SM, class A> using arg_append = typename arg_append_c<SM, A>::type;

template<class Collected, class ...Args>
struct Breaker;
template<class Collected, class H, class ...Tail>
struct Breaker<Collected, H, Tail...> {
    using progress = Breaker<arg_append<Collected, H>, Tail...>;

    using Pre = typename progress::Pre;
    using Mid = typename progress::Mid;
    using Pos = typename progress::Pos;

    enum{ right = progress::right, found = progress::found };
};
template<class Collected, class Exp, class ...Tail>
struct Breaker<Collected, expand_matcher<Exp>, Tail...> {
    using Pre = Collected;
    using Mid = Exp;
    using Pos = seq_matcher<Tail...>;

    enum{ right = sizeof...(Tail), found = true };
};
template<class Collected>
struct Breaker<Collected>  {
    using Pre = Collected;
    using Mid = seq_matcher<>;
    using Pos = seq_matcher<>;

    enum{ right = 0, found = false };
};

template<class SM>
struct seq_matcher_maker_pre;

template<class ...SMArgs>
struct seq_matcher_maker_pre<seq_matcher<SMArgs...>> {
    template<class ...Args>
    static seq_matcher<SMArgs...> apply(SMArgs... smargs, Args&&... rest) {
        return seq_matcher<SMArgs...>{ smargs... };
    }
};

template<size_t N, class ...Args>
struct seq_matcher_maker_post;

template<>
struct seq_matcher_maker_post<0> {
    using type = seq_matcher<>;

    static type apply() {
        return type{};
    }
};

template<class H, class ...Args>
struct seq_matcher_maker_post<0, H, Args...> {
    using type = seq_matcher<H, Args...>;

    static type apply(H h, Args... args) {
        return type{ h, args... };
    }
};

template<size_t N, class H, class ...Args>
struct seq_matcher_maker_post<N, H, Args...> {
    using progress = seq_matcher_maker_post<N-1, Args...>;
    using type = typename progress::type;

    static type apply(H h, Args... args) {
        return progress::apply(args...);
    }
};


template<size_t N, class ...Args>
struct nthArg;
template<class H, class ...Args>
struct nthArg<0, H, Args...> {
    using type = H;
    static H get(H h, Args...) {
        return h;
    }
};
template<size_t N, class H, class ...Args>
struct nthArg<N, H, Args...> {
    using progress = nthArg<N-1, Args...>;
    using type = typename progress::type;

    static type get(H, Args... args) {
        return progress::get(args...);
    }
};

}// namespace impl_

template<class ...Args>
struct break_matcher: matcher {
    using divider = impl_::Breaker<seq_matcher<>, impl_::toMatcher_t<Args>...>;
    using Pre = typename divider::Pre;
    using Mid = typename divider::Mid;
    using Pos = typename divider::Pos;

    impl_::toMatcher_t<Pre> pre;
    impl_::toMatcher_t<Mid> mid ;
    impl_::toMatcher_t<Pos> pos;

    break_matcher(impl_::toMatcher_t<Args>... args): 
        pre(impl_::seq_matcher_maker_pre<Pre>::apply(args...)),
        mid(impl_::nthArg<sizeof...(Args)-divider::right-1, impl_::toMatcher_t<Args>...>::get(args...).base),
        pos(impl_::seq_matcher_maker_post<sizeof...(Args)-divider::right, impl_::toMatcher_t<Args>...>::apply(args...)) {

    }

    template<class V>
    using proxy = match_sequence< decltype(
        std::begin(std::forward<impl_::lower_ref_t<V>>(std::declval<impl_::lower_ref_t<V>>()))
    )>;


    template<class V>
    using elements = impl_::merge_all_t<
        typename Pre::template elements<proxy<V>>,
        typename Mid::template elements<proxy<V>>,
        typename Pos::template elements<proxy<V>>
    >;

    template<class T, class V>
    bool unapply_impl(T& storage, V&& v) const {
        auto start = std::begin(std::forward<V>(v));
        auto end = std::end(std::forward<V>(v));
        auto mid0 = std::next(start, sizeof...(Args) - divider::right - 1);
        auto mid1 = std::next(end, -divider::right);

        bool first = pre.unapply_impl(storage, proxy<V>{ start, mid0 });
        if(!first) return false;
        bool middle = mid.unapply_impl(storage, proxy<V>{ mid0, mid1 });
        if(!middle) return false;
        bool last = pos.unapply_impl(storage, proxy<V>{ mid1, end });
        return last;
    }

    template<class V>
    impl_::map2result_t<elements<V>> match(V&& v) const{
        impl_::map2result_t<elements<V>> ret;
        ret.construct();

        if(!unapply_impl(ret, std::forward<V>(v))) return impl_::map2result_t<elements<V>>();

        return std::move(ret);
    }

    template<class V>
    impl_::map2result_t<elements<V>> operator >> (V&& v) const{
        return match(std::forward<V>(v));
    }

    expand_matcher<break_matcher> operator*() const {
        return expand_matcher<break_matcher>{*this};
    }
};

template<class ...Args>
seq_matcher<Args...> Seq(const Args&... args) {
    return seq_matcher<Args...>{ args... };
}

template<class ...Args>
typename std::enable_if<
    impl_::Breaker<seq_matcher<>, impl_::toMatcher_t<Args>...>::found,
    break_matcher<Args...> 
>::type
BSeq(const Args&... args) {
    return break_matcher<Args...>{ args... };
}

template<class ...Args>
typename std::enable_if<
    !impl_::Breaker<seq_matcher<>, impl_::toMatcher_t<Args>...>::found,
    seq_matcher<Args...> 
>::type
BSeq(const Args&... args) {
    return seq_matcher<Args...>{ args... };
}

/*************************************************************************************************/

// or-matcher
template<class Lhv, class Rhv>
struct or_matcher: matcher {

    impl_::toMatcher_t<Lhv> lhv;
    impl_::toMatcher_t<Rhv> rhv;

    or_matcher(impl_::toMatcher_t<Lhv> lhv, impl_::toMatcher_t<Rhv> rhv): lhv(lhv), rhv(rhv) {}

    template<class V>
    using elements = typename Lhv::template elements<V>;

    template<class T, class V>
    bool unapply_impl(T& storage, V&& v) const {
        static_assert(std::is_same<
                      impl_::map2result_t<typename Rhv::template elements<V>>, 
                      impl_::map2result_t<typename Lhv::template elements<V>>
                      >::value, "Or patterns can only be used with an identical set of placeholders");

        bool left = lhv.unapply_impl(storage, v);
        if(left) return true;
        storage.destruct();
        storage.construct();
        bool right = rhv.unapply_impl(storage, v);
        if(right) return true;

        return false;
    }

    template<class V>
    impl_::map2result_t<elements<V>> match(V&& v) const{
        impl_::map2result_t<elements<V>> ret;
        ret.construct();

        if(!unapply_impl(ret, std::forward<V>(v))) return impl_::map2result_t<elements<V>>();

        return std::move(ret);
    }

    template<class V>
    impl_::map2result_t<elements<V>> operator >> (V&& v) const{
        return match(std::forward<V>(v));
    }

    expand_matcher<or_matcher> operator*() const {
        return expand_matcher<or_matcher>{*this};
    }
};

template<class L, class R>
or_matcher<L, R> operator | (const L& l, const R& r) {
    return or_matcher<L, R> (l, r);
}

/*************************************************************************************************/

// and-matcher
template<class Lhv, class Rhv>
struct and_matcher: matcher {

    impl_::toMatcher_t<Lhv> lhv;
    impl_::toMatcher_t<Rhv> rhv;

    and_matcher(impl_::toMatcher_t<Lhv> lhv, impl_::toMatcher_t<Rhv> rhv): lhv(lhv), rhv(rhv) {}

    template<class V>
    using elements = impl_::merge_maps_t<typename Lhv::template elements<V>, typename Rhv::template elements<V>>;

    template<class T, class V>
    bool unapply_impl(T& storage, V&& v) const {
        bool left = lhv.unapply_impl(storage, v);
        if(!left) return false;
        bool right = rhv.unapply_impl(storage, v);
        return right;
    }

    template<class V>
    impl_::map2result_t<elements<V>> match(V&& v) const{
        impl_::map2result_t<elements<V>> ret;
        ret.construct();

        if(!unapply_impl(ret, std::forward<V>(v))) return impl_::map2result_t<elements<V>>();

        return std::move(ret);
    }

    template<class V>
    impl_::map2result_t<elements<V>> operator >> (V&& v) const{
        return match(std::forward<V>(v));
    }

    expand_matcher<and_matcher> operator*() const {
        return expand_matcher<and_matcher>{*this};
    }

};

template<class L, class R>
and_matcher<L, R> operator & (const L& l, const R& r) {
    return and_matcher<L, R> (l, r);
}
/*************************************************************************************************/

// placeholder is not really a matcher: it matches anything and stores it into the match result object
template<std::size_t N>
struct placeholder : matcher {

    template<class V>
    using elements = impl_::int_type_map< impl_::map_entry< N, V >, impl_::nil_map >;

    template<class T, class V>
    bool unapply_impl(T& storage, V&& value) const{
        if(!storage) storage.construct();
        if(is_set<N>(storage)) {
            return get<N>(storage) == std::forward<V>(value);
        }
        set<N>(storage, std::forward<V>(value));
        return true;
    }

    expand_matcher<placeholder> operator*() const {
        return expand_matcher<placeholder>{*this};
    }
};

/*************************************************************************************************/

// ignore is not a matcher at all: it matches anything and does nothing about it, hence the name
struct ignore : matcher {

    template<class V> using elements = impl_::nil_map;

    template<class T, class V>
    bool unapply_impl(T&, V&&) const {
        return true;
    }

    expand_matcher<ignore> operator*() const {
        return expand_matcher<ignore>{*this};
    }
};

/*************************************************************************************************/

static placeholder<0> _1;
static placeholder<1> _2;
static placeholder<2> _3;
static placeholder<3> _4;
static placeholder<4> _5;
static placeholder<5> _6;
static placeholder<6> _7;
static placeholder<7> _8;
static ignore _;

/*************************************************************************************************/

} /* namespace matchers */
} /* namespace functional_hell */

#endif /* MATCHERS_HPP_ */
