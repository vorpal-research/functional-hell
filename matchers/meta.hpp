/*
 * meta.hpp
 * author: Mikhail Beliaev
 */

#ifndef META_HPP
#define META_HPP

#include <type_traits>

namespace functional_hell {
namespace matchers {
namespace impl_ {

/*************************************************************************************************/

template<class T>
using invoke = typename T::type;

/*************************************************************************************************/
// placeholder class representing, well, nothing
struct none{
    explicit constexpr operator bool () const{ return false; }
};

/*************************************************************************************************/
// int-to-type map entry, essentially a pair of an int and a type
template<int Kx, class Vx>
struct map_entry {
    using V = Vx;
    enum{ K = Kx };
};

/*************************************************************************************************/
// int-to-type map itself
// empty map
struct nil_map;
// non-empty map
template<class HEntry, class Tail> struct int_type_map;

/*************************************************************************************************/

// ({K: V} Rest)
template<int K, class V, class Rest>
struct int_type_map< map_entry<K,V>, Rest > {};

// construct a map
template<class ...Entries>
struct mk_int_type_map;

// mk_int_type_map ... = ()
template<> struct mk_int_type_map<> { using type = nil_map; };
// mk_int_type_map HEntry Rest... = (HEntry `(mk_int_type_map Rest...))
template<class HEntry, class ...Rest>
struct mk_int_type_map<HEntry, Rest...> {
    using type = int_type_map<HEntry, typename mk_int_type_map<Rest...>::type >;
};

// sleek form
template<class ...Entries> using mk_int_type_map_t = typename mk_int_type_map<Entries...>::type;

/*************************************************************************************************/
template<class Map, int Ix>
struct get_at;

// get_at ({K: V} Rest) K = V
template<int K, class V, class Rest>
struct get_at< int_type_map< map_entry<K,V>, Rest >, K > {
    using type = V;
};

// get_at ({K: V} Rest) Ix = get_at Rest Ix
template<int Ix, int K, class V, class Rest>
struct get_at< int_type_map< map_entry<K,V>, Rest >, Ix > {
    using type = typename get_at<Rest, Ix>::type;
};

// get_at () Ix = none
template<int K>
struct get_at< nil_map, K > {
    using type = none;
};

// sleek form
template<class Map, int Ix>
using get_at_t = typename get_at<Map, Ix>::type;

/*************************************************************************************************/

template<class Map, int Ix, class V>
struct put_at;

// put_at () Ix V = ((Ix V))
template<int Ix, class V>
struct put_at<nil_map, Ix, V> {
    using type = mk_int_type_map_t< map_entry<Ix, V> >;
};

// put_at ({K: V} Rest) K NewV = ({K: NewV} Rest)
template<int K, class V, class NewV, class Rest>
struct put_at<int_type_map<map_entry<K, V>, Rest >, K, NewV> {
    using type = int_type_map< map_entry<K, NewV>, Rest >;
};

// put_at ({HK: HV} Rest) K V = ({HK: HV} `(put_at Rest K V))
template<int HK, int K, class HV, class V, class Rest>
struct put_at<int_type_map<map_entry<HK, HV>, Rest >, K, V> {
    using type = int_type_map<map_entry<HK, HV>, typename put_at<Rest, K, V>::type>;
};

// sleek form
template<class Map, int K, class V>
using put_at_t = typename put_at<Map, K, V>::type;

/*************************************************************************************************/

// remove_at
template<class Map, int Ix>
struct remove_at;

// remove_at () Ix = ()
template<int Ix>
struct remove_at<nil_map, Ix> {
    using type = nil_map;
};

// remove_at ({K: V} Rest) K = Rest
template<int K, class V, class Rest>
struct remove_at<int_type_map<map_entry<K, V>, Rest >, K> {
    using type = Rest;
};

// remove_at ({HK: HV} Rest) K = ({HK: HV} `(remove_at Rest K))
template<int HK, int K, class HV, class Rest>
struct remove_at<int_type_map<map_entry<HK, HV>, Rest >, K> {
    using type = int_type_map<map_entry<HK, HV>, typename remove_at<Rest, K>::type>;
};

// sleek form
template<class Map, int K>
using remove_at_t = typename remove_at<Map, K>::type;

/*************************************************************************************************/

// contains_at
template<class Map, int Ix>
struct contains_at;

// contains_at ({K: V} Rest) K = true
template<int K, class V, class Rest>
struct contains_at< int_type_map< map_entry<K,V>, Rest >, K > {
    static constexpr auto value = true;

    constexpr operator bool() const { return value; }
};

// contains_at ({K: V} Rest) Ix = contains_at Rest Ix
template<int Ix, int K, class V, class Rest>
struct contains_at< int_type_map< map_entry<K,V>, Rest >, Ix > {
    static constexpr auto value = contains_at<Rest, Ix>::value;

    constexpr operator bool() const { return value; }
};

// contains_at () Ix = false
template<int Ix>
struct contains_at< nil_map, Ix > {
    static constexpr auto value = false;

    constexpr operator bool() const { return value; }
};

/*************************************************************************************************/

// simple merge of two types -- produces common_type for them
// unless they are the same
// or one of them is none
template<class A, class B>
struct simple_merge {
    using type = typename std::decay<
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

// sleek form
template<class A, class B>
using simple_merge_t = typename simple_merge<A, B>::type;

/****************************************************************************************************/

template<class Map0, class Map1>
struct merge_maps;

// merge_maps () Map = Map
template<class Map>
struct merge_maps<nil_map, Map> {
    using type = Map;
};

// merge_maps () () = ()
template<>
struct merge_maps<nil_map, nil_map> {
    using type = nil_map;
};

// merge_maps ({K: V} Rest) Map1 = merge_maps Rest $ put_at K (merge V (get_at K Map1)) Map1
template<int K, class V, class Rest, class Map1>
struct merge_maps<int_type_map<map_entry<K, V>, Rest>, Map1> {
    using existing = get_at_t<Map1, K>;
    using type = typename merge_maps<
        Rest,
        put_at_t<Map1, K, simple_merge_t<existing, V>>
    >::type;
};

// sleek form
template<class Map0, class Map1>
using merge_maps_t = typename merge_maps<Map0, Map1>::type;

/****************************************************************************************************/

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

/*************************************************************************************************/

// quick and dirty type lists
template<class H, class T> struct type_list{};
struct nil{};

// type map -> type list
// the idea is to turn a map from index to type into a corresponding type array (here, type_list)
// filling all the missing indices with `none` type
// e.g.:
/*
 * { (0: A), (1: B) } -> [A, B]
 * { (2: A), (1: B), (3: C), (5: F) } -> [None, B, A, C, None, F]
 *
 * */
// we need a starting index to simplify recursion
template<class Map, size_t Start = 0> struct map2list;
// an empty map turns into an empty list, obviously
template<size_t N> struct map2list< nil_map, N > {
    using type = nil;
};
// map2list Map N = `(get_at Map N) :: `(map2list (remove_at Map N))
// XXX: this is a very naive implementation
template<class HEntry, class Rest, size_t N>
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

// sleek form
template<class Map>
using map2list_t = invoke<map2list<Map>>;

template<class... Elements> struct type_array{};

template<class H, class T> struct ta_cons;
template<class H, class ...Rest> 
struct ta_cons<H, type_array<Rest...>> {
    using type = type_array<H, Rest...>;
};

template<class TL> struct list2array;
template<>
struct list2array<nil> {
    using type = type_array<>;
};
template<class H, class T>
struct list2array<type_list<H, T>> {
    using type = ta_cons<H, invoke<list2array<T>>>;
};

template<class TL>
using list2array_t = invoke<list2array<TL>>;

template<class ...Args> struct mk_list;
template<>
struct mk_list<> {
    using type = nil;
};
template<class H, class ...Rest>
struct mk_list<H, Rest...> {
    using type = type_list<H, invoke<mk_list<Rest...>>>;
};
template<class ...Args> 
using mk_list_t = invoke<mk_list<Args...>>;

template<class TA> struct array2list;
template<class ...Elems>
struct array2list<type_array<Elems...>> {
    using type = mk_list_t<Elems...>;
};
template<class TA> 
using array2list_t = invoke<array2list<TA>>;

template<class TL, size_t N> struct nth_element;
template<size_t N>
struct nth_element<nil, N>{
    using type = none;
};
template<class H, class T>
struct nth_element<type_list<H, T>, 0>{
    using type = H;
};
template<size_t N, class H, class T>
struct nth_element<type_list<H, T>, N>{
    using type = invoke<nth_element<T, N-1>>;
};
template<size_t N>
struct nth_element<type_array<>, N>{
    using type = none;

    static none apply() {
        return none{};
    }
};
template<class H, class ...Rest>
struct nth_element<type_array<H, Rest...>, 0>{
    using type = H;

    static H&& apply(H&& h, Rest&&... rest) {
        return h;
    }
};
template<size_t N, class H, class ...Rest>
struct nth_element<type_array<H, Rest...>, N>{
    using progress = nth_element<type_array<Rest...>, N-1>;
    using type = invoke<progress>;

    static type&& apply(H&& h, Rest&&... rest) {
        return progress::apply(std::forward<Rest>(rest)...);
    }
};
template<size_t N>
struct nth_element<nil_map, N>{
    using type = none;
};
template<size_t N, class HE, class TE>
struct nth_element<int_type_map<HE, TE>, N>{
    using type = get_at_t<int_type_map<HE, TE>, N>;
};
template<class TL, size_t N> 
using nth_element_t = invoke<nth_element<TL, N>>;

template<size_t N, class...Args>
nth_element_t<type_array<Args...>, N>&& nth_element_func(Args&&... args) {
    return nth_element<type_array<Args...>, N>::apply(std::forward<Args>(args)...);
}

template<size_t N, class F>
struct drop_and_apply_impl;
template<class F>
struct drop_and_apply_impl<0, F> {

    template<class ...Args>
    static auto apply(F f, Args&&... args) -> decltype(f(std::forward<Args>(args)...)) {
        return f(std::forward<Args>(args)...);
    }
};
template<size_t N, class F>
struct drop_and_apply_impl {
    using progress = drop_and_apply_impl<N-1, F>;

    template<class H, class ...Args>
    static auto apply(F f, H&&, Args&&... args) -> decltype(progress::apply(f, std::forward<Args>(args)...)) {
        return progress::apply(f, std::forward<Args>(args)...);
    }
};

template<size_t N, class F, class ...Args>
auto drop_and_apply(F f, Args&&... args) -> decltype(drop_and_apply_impl<N, F>::apply(f, std::forward<Args>(args)...)) {
    return drop_and_apply_impl<N, F>::apply(f, std::forward<Args>(args)...);
}

template<size_t N, class ...Args>
struct take_n;
template<class ...Args>
struct take_n<0, Args...> {
    using type = type_array<>;
};
template<size_t N, class H, class ...Args>
struct take_n<N, H, Args...> {
    using progress = take_n<N-1, Args...>;
    using type = invoke<ta_cons<H, invoke<progress>>>;
};
template<size_t N, class ...Args>
using take_n_t = invoke<take_n<N, Args...>>;

template<class F, class Taken>
struct take_and_apply_impl;

template<class F, class ...TakenArgs>
struct take_and_apply_impl<F, type_array<TakenArgs...>> {
    template<class ...AdditionalArgs>
    static auto apply(F f, TakenArgs&&... args, AdditionalArgs&&...) -> decltype(f(std::forward<TakenArgs>(args)...)) {
        return f(std::forward<TakenArgs>(args)...);
    }
};

template<size_t N, class F, class ...Args>
auto take_and_apply(F f, Args&&... args) -> decltype(take_and_apply_impl<F, take_n_t<N, Args...>>::apply(f, std::forward<Args>(args)...)) {
    return take_and_apply_impl<F, take_n_t<N, Args...>>::apply(f, std::forward<Args>(args)...);
}

template<class Tup, class A>
struct tuple_append_c;
template<class A, class ...Args>
struct tuple_append_c<std::tuple<Args...>, A> {
    typedef std::tuple<Args..., A> type;
};
template<class Tup, class A> using tuple_append = typename tuple_append_c<Tup, A>::type;

} /* namespace impl_ */
} /* namespace matchers */
} /* namespace functional_hell */

#endif /* META_HPP */
