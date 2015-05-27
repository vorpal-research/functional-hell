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
#include <functional>

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
    static bool doIt(const std::tuple<Args...>&, Storage&, MatchRes&&) {
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
    static bool doIt(const std::tuple<Args...>&, Storage&, MatchIter begin, MatchIter end) {
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

template<class T, class = void>
struct compare_trait {
   // static_assert(sizeof(T) <= 0, "You cannot use two similar placeholders for type that do not define eithe `==` or custom functional_hell::matchers::compare_trait");
    template<class U, class V>
    bool operator()(U&&, V&&) const {
        return false;
    }
};

template<class T>
struct compare_trait<T, impl_::enable_if_t<impl_::has_equality<T>>> {
    template<class U, class V>
    bool operator()(U&& lhv, V&& rhv) const {
        return lhv == rhv;
    }
};

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
        auto cmp = compare_trait<impl_::no_ref<V>>{};
        return cmp(std::forward<V>(value), data);
    }
};

namespace impl_ {

template<class T, class = void>
struct toMatcher;

template<class T>
using toMatcher_t = typename toMatcher<T>::type;

} /* namespace impl_ */

/*************************************************************************************************/

template<class Matcher>
struct expand_matcher: matcher {
    using base_t = Matcher;

    Matcher base;

    expand_matcher(const Matcher& base): base(base) {};

};

/*************************************************************************************************/

// matcher for complex structures with unapply and such: matching boils down to breaking values
// with unapply and passing results to lower-level matchers
template<class Lam, class ...Args>
struct tree_matcher: matcher {

    Lam lam;
    std::tuple<impl_::toMatcher_t<Args>...> matchers;

    tree_matcher(Lam lam, const Args&... args): lam(lam), matchers{ args... } {}

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

    seq_matcher(const Args&... args): matchers{ args... } {}

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

struct make_seq_matcher {
    template<class ...Args>
    seq_matcher<impl_::toMatcher_t<Args>...> operator()(Args&&... args) {
        return seq_matcher<impl_::toMatcher_t<Args>...>{ std::forward<Args>(args)... };
    }
};

template<class T>
struct IsExpandMatcher {
    static constexpr bool value = false;
};

template<class T>
struct IsExpandMatcher<expand_matcher<T>> {
    static constexpr bool value = true;
};

}// namespace impl_

template<class ...Args>
struct break_matcher: matcher {
    static constexpr size_t WHERE = impl_::find_first_arg<impl_::IsExpandMatcher, Args...>::value;
    static constexpr size_t TOTAL = sizeof...(Args);

    //using divider = impl_::Breaker<seq_matcher<>, impl_::toMatcher_t<Args>...>;
    //using Pre = typename divider::Pre;
    //using Mid = typename divider::Mid;
    //using Pos = typename divider::Pos;
    using TA = impl_::type_array<impl_::toMatcher_t<Args>...>;
    using Pre = impl_::take_and_apply_template_t<WHERE, seq_matcher, impl_::toMatcher_t<Args>...>;
    using Mid = typename impl_::nth_element_t<TA, WHERE>::base_t;
    using Pos = impl_::drop_and_apply_template_t<WHERE+1, seq_matcher, impl_::toMatcher_t<Args>...>;

    impl_::decay_t<impl_::toMatcher_t<Pre>> pre;
    impl_::decay_t<impl_::toMatcher_t<Mid>> mid ;
    impl_::decay_t<impl_::toMatcher_t<Pos>> pos;

    break_matcher(const Args&... args):
        pre(impl_::take_and_apply<WHERE>(impl_::make_seq_matcher{}, args...)),
        mid(impl_::nth_element<TA, WHERE>::apply(args...).base),
        pos(impl_::drop_and_apply<WHERE+1>(impl_::make_seq_matcher{}, args...)) {

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
        auto start = std::begin(impl_::unwrap(v));
        auto end = std::end(impl_::unwrap(v));
        auto mid0 = std::next(start, WHERE);
        auto mid1 = std::next(end, -(TOTAL - WHERE - 1));

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
seq_matcher<impl_::toMatcher_t<Args>...> Seq(Args&&... args) {
    return seq_matcher<impl_::toMatcher_t<Args>...>{ std::forward<Args>(args)... };
}

template<class ...Args>
typename std::enable_if<
    impl_::find_first_arg<impl_::IsExpandMatcher, impl_::toMatcher_t<Args>...>::value != ~0U,
    break_matcher<impl_::toMatcher_t<Args>...> 
>::type
BSeq(Args&&... args) {
    return break_matcher<impl_::toMatcher_t<Args>...>{ std::forward<Args>(args)... };
}

template<class ...Args>
typename std::enable_if<
    impl_::find_first_arg<impl_::IsExpandMatcher, impl_::toMatcher_t<Args>...>::value == ~0U,
    seq_matcher<impl_::toMatcher_t<Args>...> 
>::type
BSeq(Args&&... args) {
    return seq_matcher<impl_::toMatcher_t<Args>...>{ std::forward<Args>(args)... };
}

/*************************************************************************************************/

// or-matcher
template<class Lhv, class Rhv>
struct or_matcher: matcher {

    impl_::toMatcher_t<Lhv> lhv;
    impl_::toMatcher_t<Rhv> rhv;

    or_matcher(const Lhv& lhv, const Rhv& rhv): lhv(lhv), rhv(rhv) {}

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
or_matcher<impl_::toMatcher_t<L>, impl_::toMatcher_t<R>> operator | (const L& l, const R& r) {
    return or_matcher<impl_::toMatcher_t<L>, impl_::toMatcher_t<R>> (l, r);
}

/*************************************************************************************************/

// and-matcher
template<class Lhv, class Rhv>
struct and_matcher: matcher {

    impl_::toMatcher_t<Lhv> lhv;
    impl_::toMatcher_t<Rhv> rhv;

    and_matcher(const Lhv& lhv, const Rhv& rhv): lhv(lhv), rhv(rhv) {}

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
and_matcher<impl_::toMatcher_t<L>, impl_::toMatcher_t<R>> operator & (const L& l, const R& r) {
    return and_matcher<impl_::toMatcher_t<L>, impl_::toMatcher_t<R>>(l, r);
}
/*************************************************************************************************/

namespace impl_ {

    template<class U, class V>
    bool compare_equal(U&& lhv, V&& rhv) {
        using TT = typename std::common_type<no_ref<U>, no_ref<V>>::type;
        compare_trait<no_ref<TT>> cp;
        return cp(lhv, rhv);
    }

} /* namespace impl_ */

// placeholder is not really a matcher: it matches anything and stores it into the match result object
template<std::size_t N>
struct placeholder : matcher {

    placeholder() = default;
    placeholder(const placeholder&) = default;
    template<class U>
    placeholder(U&&) {}

    template<class V>
    using elements = impl_::int_type_map< impl_::map_entry< N, V >, impl_::nil_map >;

    template<class T, class V>
    bool unapply_impl(T& storage, V&& value) const{
        if(!storage) storage.construct();
        if(is_set<N>(storage)) {
            return impl_::compare_equal(get<N>(storage), value);
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

namespace placeholders{

static placeholder<0> _1;
static placeholder<1> _2;
static placeholder<2> _3;
static placeholder<3> _4;
static placeholder<4> _5;
static placeholder<5> _6;
static placeholder<6> _7;
static placeholder<7> _8;
static placeholder<8> _9;
static ignore _;

} /* namespace placeholders */

/*************************************************************************************************/

namespace impl_ {

template<class T>
using is_matcher = std::is_base_of<matcher, impl_::decay_t<T>>;

template<class T>
struct toMatcher<T, invoke<std::enable_if<is_matcher<T>::value>>> {
    using type = impl_::decay_t<T>;
};

template<class T>
struct toMatcher<T, invoke<std::enable_if<std::is_placeholder<T>::value && !is_matcher<T>::value>>> {
    using type = placeholder<std::is_placeholder<T>::value - 1>;
};

template<class T>
struct toMatcher<T, invoke<std::enable_if<!std::is_placeholder<T>::value && !is_matcher<T>::value>>> {
    using type = constant_matcher<T>;
};

} /* namespace impl_ */

} /* namespace matchers */
} /* namespace functional_hell */

namespace std {
    template<> struct is_placeholder<functional_hell::matchers::placeholder<0>> : public integral_constant<int, 1> {};
    template<> struct is_placeholder<functional_hell::matchers::placeholder<1>> : public integral_constant<int, 2> {};
    template<> struct is_placeholder<functional_hell::matchers::placeholder<2>> : public integral_constant<int, 3> {};
    template<> struct is_placeholder<functional_hell::matchers::placeholder<3>> : public integral_constant<int, 4> {};
    template<> struct is_placeholder<functional_hell::matchers::placeholder<4>> : public integral_constant<int, 5> {};
    template<> struct is_placeholder<functional_hell::matchers::placeholder<5>> : public integral_constant<int, 6> {};
    template<> struct is_placeholder<functional_hell::matchers::placeholder<6>> : public integral_constant<int, 7> {};
    template<> struct is_placeholder<functional_hell::matchers::placeholder<7>> : public integral_constant<int, 8> {};
    template<> struct is_placeholder<functional_hell::matchers::placeholder<8>> : public integral_constant<int, 9> {};
}

#endif /* MATCHERS_HPP_ */
