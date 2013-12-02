/*
 * int_type_map.hpp
 *
 *  Created on: Dec 2, 2013
 *      Author: belyaev
 */

#ifndef INT_TYPE_MAP_HPP_
#define INT_TYPE_MAP_HPP_

#include <type_traits>

namespace functional_hell {
namespace matchers {

template<int Kx, class Vx>
struct map_entry {
	using V = Vx;
	enum{ K = Kx };
};

template<class HEntry, class Tail>
struct int_type_map;
struct nil_map;

template<int K, class V, class Rest>
struct int_type_map< map_entry<K,V>, Rest > {};

template<class ...Entries>
struct mk_int_type_map;

template<>
struct mk_int_type_map<> {
	using type = nil_map;
};

template<class HEntry, class ...Rest>
struct mk_int_type_map<HEntry, Rest...> {
	using type = int_type_map<HEntry, typename mk_int_type_map<Rest...>::type >;
};

template<class ...Entries>
using mk_int_type_map_t = typename mk_int_type_map<Entries...>::type;

template<class Map, int Ix>
struct get_at;

struct none{};

template<int K, class V, class Rest>
struct get_at< int_type_map< map_entry<K,V>, Rest >, K > {
	using type = V;
};

template<int Ix, int K, class V, class Rest>
struct get_at< int_type_map< map_entry<K,V>, Rest >, Ix > {
	using type = typename get_at<Rest, Ix>::type;
};

template<int K>
struct get_at< nil_map, K > {
	using type = none;
};

template<class Map, int Ix>
using get_at_t = typename get_at<Map, Ix>::type;

template<class Map, int Ix, class V>
struct put_at;

template<int Ix, class V>
struct put_at<nil_map, Ix, V> {
	using type = mk_int_type_map_t< map_entry<Ix, V> >;
};

template<int K, class V, class NewV, class Rest>
struct put_at<int_type_map<map_entry<K, V>, Rest >, K, NewV> {
	using type = int_type_map< map_entry<K, NewV>, Rest >;
};

template<int HK, int K, class HV, class V, class Rest>
struct put_at<int_type_map<map_entry<HK, HV>, Rest >, K, V> {
	using type = int_type_map<map_entry<HK, HV>, typename put_at<Rest, K, V>::type>;
};

template<class Map, int K, class V>
using put_at_t = typename put_at<Map, K, V>::type;

template<class Map, int Ix>
struct remove_at;

template<int Ix>
struct remove_at<nil_map, Ix> {
	using type = nil_map;
};

template<int K, class V, class Rest>
struct remove_at<int_type_map<map_entry<K, V>, Rest >, K> {
	using type = Rest;
};

template<int HK, int K, class HV, class Rest>
struct remove_at<int_type_map<map_entry<HK, HV>, Rest >, K> {
	using type = int_type_map<map_entry<HK, HV>, typename remove_at<Rest, K>::type>;
};

template<class Map, int K>
using remove_at_t = typename remove_at<Map, K>::type;

template<class Map, int Ix>
struct contains_at;

template<int K, class V, class Rest>
struct contains_at< int_type_map< map_entry<K,V>, Rest >, K > {
	static constexpr auto value = true;

	constexpr operator bool() { return value; }
};

template<int Ix, int K, class V, class Rest>
struct contains_at< int_type_map< map_entry<K,V>, Rest >, Ix > {
	static constexpr auto value = contains_at<Rest, Ix>::value;

	constexpr operator bool() { return value; }
};

template<int Ix>
struct contains_at< nil_map, Ix > {
	static constexpr auto value = false;

	constexpr operator bool() { return value; }
};

template<class H, class T>
struct type_list{};
struct nil{};

template<class Map, int Start = 0>
struct map2list;
template<int N>
struct map2list< nil_map, N > {
	using type = nil;
};
template<class HEntry, class Rest, int N>
struct map2list< int_type_map<HEntry, Rest>, N> {
	using arg = int_type_map<HEntry, Rest>;
	using current = get_at_t<arg, N>;


	using type = type_list<
		get_at_t<arg, N>,
		typename map2list<
			remove_at_t<arg, N>,
			N+1
		>::type
	>;
};

template<class Map>
using map2list_t = typename map2list<Map>::type;

template<class Map0, class Map1>
struct merge_maps;

template<class Map>
struct merge_maps<nil_map, Map> {
	using type = Map;
};

template<>
struct merge_maps<nil_map, nil_map> {
	using type = nil_map;
};

template<class A, class B>
struct simple_merge {
	using type = typename std::remove_reference<
		typename std::common_type<A, B>::type
	>::type;
};

template<class A>
struct simple_merge<A, A> {
	using type = A;
};

template<class A>
struct simple_merge<A, none> {
	using type = A;
};

template<class A>
struct simple_merge<none, A> {
	using type = A;
};

template<class A, class B>
using simple_merge_t = typename simple_merge<A, B>::type;

template<int K, class V, class Rest, class Map1>
struct merge_maps<int_type_map<map_entry<K, V>, Rest>, Map1> {
	using existing = get_at_t<Map1, K>;
	using type = typename merge_maps<
		Rest,
		put_at_t<Map1, K, simple_merge_t<existing, V>>
	>::type;
};

template<class Map0, class Map1>
using merge_maps_t = typename merge_maps<Map0, Map1>::type;


template<class ...Maps>
struct merge_all;

template<class Map, class ...Maps>
struct merge_all<Map, Maps...> {
	using type = merge_maps_t<Map, typename merge_all<Maps...>::type>;
};

template<>
struct merge_all<> {
	using type = nil_map;
};

template<class ...Maps>
using merge_all_t = typename merge_all<Maps...>::type;


}
}



#endif /* INT_TYPE_MAP_HPP_ */
