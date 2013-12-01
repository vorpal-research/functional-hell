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

using namespace functional_hell::matchers::impl_;

template<class ...Elems>
using storage_t = match_result<Elems...>;

template<class ...Args>
storage_t<Args...> mkStorage(Args&&... args) {
	return storage_t{ std::forward_as_tuple<Args...>(args...); }
}

template<class Tuple, class ...Args>
struct applicate;

template<class Head, class ...Tail, class Arg0, class ...Args>
struct applicate< match_result<Head, Tail...>, Arg0, Args... > {
	using elements = Arg0::template elements<Head>;
	using type = merge_all_t<elements, typename applicate< match_result<Tail...>, Args... >::type >;
};

template<>
struct applicate< match_result<> > {
	using type = merge_all_t<>;
};

template<class Derived, class ...Args>
struct matcher {

	template<class V>
	using unapplied = decltype(Derived::unapply(std::declval<V>()));

	template<class V>
	using elements = typename applicate< unapplied<V>, Args... >;

	template<class T, class V>
	static bool unapply_impl(T& storage, V&& v) {
		auto ret = Derived::unapply(std::forward<V>(v));
		if(!ret) return false;

		// HOW?

		if(!Arg0::unapply_impl(storage, ret->first)) return false;
		if(!Arg1::unapply_impl(storage, ret->second)) return false;
		return true;
	}

	template<class V>
	map2result_t<elements<V>> match(V&& v) {
		rettype ret;

		if(!unapply_impl(ret, std::forward<V>(v))) return;

		return std::move(ret);
	}

};

template<size_t N>
struct placeholder {

	template<class V>
	using elements = int_type_map< map_entry< N, V >, nil_map >;

	template<class T, class V>
	bool unapply_impl(T& storage, V&& value) {
		if(!storage) storage.construct();

		// HOW?
		storage->set_0(std::forward<V>(value));
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
	bool unapply_impl(T& storage, V&& value) {
		return true;
	}
};

static ignore _;

template<class Arg0, class Arg1>
struct example_matcher: public matcher<Arg0, Arg1> {
	template<class A, class B>
	storage_t<A, B> unapply(const std::pair<A, B>& v) {
		return mkStorage(v.first, v.second);
	}
};

#endif /* MATCHERS_HPP_ */
