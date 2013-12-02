/*
 * matchers.hpp
 *
 *  Created on: Nov 29, 2013
 *      Author: belyaev
 */

#ifndef MATCHERS_HPP_
#define MATCHERS_HPP_

#include "matchers/match_tuple.hpp"
#include "matchers/int_type_map.hpp"

////////////////////////

using namespace functional_hell::matchers;

template<class ...Elems>
using storage_t = match_result<Elems...>;

template<class Tuple, class ...Args>
struct applicate;

template<class Head, class ...Tail, class Arg0, class ...Args>
struct applicate< match_result<Head, Tail...>, Arg0, Args... > {
	using elements = typename Arg0::template elements<Head>;
	using type = merge_all_t<elements, typename applicate< match_result<Tail...>, Args... >::type >;
};

template<>
struct applicate< match_result<> > {
	using type = merge_all_t<>;
};

template<size_t S, class Storage, class MatchRes, class ...Args>
struct unapplier {
	static constexpr size_t K = sizeof...(Args) - S;
	static bool doIt(Storage& storage, MatchRes&& mres) {
		if(!type_at_t<K, match_result<Args...>>::template unapply_impl(storage, get<K>(mres))) return false;
		return unapplier<S-1, Storage, MatchRes, Args...>::doIt(storage, std::forward<MatchRes>(mres));
	}
};

template<class Storage, class MatchRes, class ...Args>
struct unapplier<0, Storage, MatchRes, Args...> {
	static bool doIt(Storage&, MatchRes&&) {
		return true;
	}
};

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

template<class Lam, class ...Args>
struct matcher {

	template<class V>
	using unapplied = decltype(Lam::unapply(std::forward<lower_ref_t<V>>(std::declval<lower_ref_t<V>>())));

	template<class V>
	using elements = typename applicate< unapplied<V>, Args... >::type;

	template<class T, class V>
	static bool unapply_impl(T& storage, V&& v) {
		auto ret = Lam :: unapply(unwrap(v));
		if(!ret) return false;

		return unapplier<sizeof...(Args), T, decltype(ret), Args...>::doIt(storage, std::move(ret));
	}

	template<class V>
	map2result_t<elements<V>> match(V&& v) {
		map2result_t<elements<V>> ret;

		if(!unapply_impl(ret, std::forward<V>(v))) return map2result_t<elements<V>>();

		return std::move(ret);
	}

	template<class V>
	map2result_t<elements<V>> operator >> (V&& v) {
		return match(std::forward<V>(v));
	}

};

template<size_t N>
struct placeholder {

	template<class V>
	using elements = int_type_map< map_entry< N, V >, nil_map >;

	template<class T, class V>
	static bool unapply_impl(T& storage, V&& value) {
		if(!storage) storage.construct();
		if(is_set<N>(storage)) {
			return get<N>(storage) == std::forward<V>(value);
		}
		set<N>(storage, std::forward<V>(value));
		return true;
	}
};

static placeholder<0> _1;
static placeholder<1> _2;
static placeholder<2> _3;
static placeholder<3> _4;
static placeholder<4> _5;
static placeholder<5> _6;
static placeholder<6> _7;
static placeholder<7> _8;

struct ignore {

	template<class V>
	using elements = nil_map;

	template<class T, class V>
	static bool unapply_impl(T&, V&&) {
		return true;
	}
};

static ignore _;

template<class Arg0, class Arg1>
struct example_matcher {

	template<class A, class B>
	static storage_t<match_reference<A>, match_reference<B>> unapply(std::pair<A, B>& v) {
		storage_t<match_reference<A>, match_reference<B>> ret;
		ret.construct();
		ret->set_1(v.first);
		ret->set_2(v.second);
		return ret;
	}

};

#endif /* MATCHERS_HPP_ */
