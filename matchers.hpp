/*
 * matchers.hpp
 *
 *  Created on: Nov 29, 2013
 *      Author: belyaev
 */

#ifndef MATCHERS_HPP_
#define MATCHERS_HPP_

#include <tuple>

#include "matchers/match_tuple.hpp"
#include "matchers/meta.hpp"

namespace functional_hell {
namespace matchers {

template<class ...Elems> using storage_t = match_result<impl_::wrapped_t<Elems>...>;

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

/*************************************************************************************************/

template<class T> struct no_ref_c { using type = T; };
template<class T> struct no_ref_c<T&> { using type = T; };
template<class T> struct no_ref_c<T&&> { using type = T; };
template<class T> struct no_ref_c<match_reference<T>> { using type = T; };
template<class T> struct no_ref_c<match_reference<T>&> { using type = T; };
template<class T> struct no_ref_c<const match_reference<T>&> { using type = T; };
template<class T> struct no_ref_c<match_reference<T>&&> { using type = T; };

template<class T>
using no_ref = typename no_ref_c<T>::type;

template<class T> struct lower_ref { using type = T; };
template<class T> struct lower_ref<match_reference<T>> { using type = T&; };
template<class T> struct lower_ref<match_reference<T>&> { using type = T&; };
template<class T> struct lower_ref<match_reference<T>&&> { using type = T&; };

template<class T>
using lower_ref_t = typename lower_ref<T>::type;

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
    impl_::map2result_t<elements<V>> match(V&& v) {
        impl_::map2result_t<elements<V>> ret;

        if(!unapply_impl(ret, std::forward<V>(v))) return impl_::map2result_t<elements<V>>();

        return std::move(ret);
    }

    template<class V>
    impl_::map2result_t<elements<V>> operator >> (V&& v) {
        return match(std::forward<V>(v));
    }

};


/*************************************************************************************************/

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
};

/*************************************************************************************************/

struct ignore : matcher {

    template<class V>
    using elements = impl_::nil_map;

    template<class T, class V>
    bool unapply_impl(T&, V&&) const {
        return true;
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
