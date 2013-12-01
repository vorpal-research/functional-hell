/*
 * match_tuple.hpp
 *
 *  Created on: Dec 2, 2013
 *      Author: belyaev
 */

#ifndef MATCH_TUPLE_HPP_
#define MATCH_TUPLE_HPP_

#include <utility>

#include "matchers/int_type_map.hpp"

namespace functional_hell {
namespace matchers {

struct void_ {};

template<class ...Args>
struct match_tuple;

template<>
struct match_tuple<>{};

#define FIELD(N) \
union { \
    Arg ## N _ ## N; \
    void_ void_ ## N; \
};\
template<class ...U> \
void set_ ## N(U&& ...v) { \
    new (&_ ## N) Arg ## N (std::forward<U>(v)...); \
    assigned |= (1 << N); \
} \
bool is_set_ ## N() { \
    return !!(assigned & (1 << N)); \
} \
void destroy_ ## N() { \
    if(is_set_ ## N()) _ ## N . ~Arg ## N (); \
} \


template<class Arg1>
struct match_tuple<Arg1>{
    FIELD(1)

    match_tuple(): void_1{} {};
    ~match_tuple(){
        destroy_1();
    };
private:
    short assigned;
};

template<class Arg1, class Arg2>
struct match_tuple<Arg1, Arg2>{
    FIELD(1)
    FIELD(2)

    match_tuple(): void_1{}, void_2{} {};
    ~match_tuple(){
        destroy_1();
        destroy_2();
    };
private:
    short assigned;
};

template<class Arg1, class Arg2, class Arg3>
struct match_tuple<Arg1, Arg2, Arg3>{
    FIELD(1)
    FIELD(2)
    FIELD(3)

    match_tuple(): void_1{}, void_2{}, void_3{} {};
    ~match_tuple(){
        destroy_1();
        destroy_2();
        destroy_3();
    };
private:
    short assigned;
};

template<class Arg1, class Arg2, class Arg3, class Arg4>
struct match_tuple<Arg1, Arg2, Arg3, Arg4>{
    FIELD(1)
    FIELD(2)
    FIELD(3)
    FIELD(4)

    match_tuple(): void_1{}, void_2{}, void_3{}, void_4{} {};
    ~match_tuple(){
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
    };
private:
    short assigned;
};

template<class Arg1, class Arg2, class Arg3, class Arg4, class Arg5>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5>{
    FIELD(1)
    FIELD(2)
    FIELD(3)
    FIELD(4)
    FIELD(5)

    match_tuple(): void_1{}, void_2{}, void_3{}, void_5{} {};
    ~match_tuple(){
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
    };
private:
    short assigned;
};

template<class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>{
    FIELD(1)
    FIELD(2)
    FIELD(3)
    FIELD(4)
    FIELD(5)
    FIELD(6)

    match_tuple(): void_1{}, void_2{}, void_3{}, void_5{}, void_6{} {};
    ~match_tuple(){
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
    };
private:
    short assigned;
};

template<class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7>{
    FIELD(1)
    FIELD(2)
    FIELD(3)
    FIELD(4)
    FIELD(5)
    FIELD(6)
    FIELD(7)

    match_tuple(): void_1{}, void_2{}, void_3{}, void_5{}, void_6{}, void_7{} {};
    ~match_tuple(){
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
        destroy_7();
    };
private:
    short assigned;
};

template<class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8>{
    FIELD(1)
    FIELD(2)
    FIELD(3)
    FIELD(4)
    FIELD(5)
    FIELD(6)
    FIELD(7)
    FIELD(8)

    match_tuple(): void_1{}, void_2{}, void_3{}, void_5{}, void_6{}, void_7{}, void_8{} {};
    ~match_tuple(){
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
        destroy_7();
        destroy_8();
    };
private:
    short assigned;
};

// poor man's option
template<class ...Args>
class match_result {
    union {
        void_ null;
        match_tuple<Args...> data;
    };
    bool success;
public:

    void construct() {
        new (&data) match_tuple<Args...>{};
        success = true;
    }

    void destruct() {
        if(success) {
            data.~match_tuple<Args...>();
            success = false;
        }
    }

    match_tuple<Args...>* operator->() {
        return &data;
    }

    explicit operator bool() {
        return success;
    }

    match_result(): null{}, success{false} {};
    ~match_result(){ destruct(); }
};

template<>
class match_result<> {
    bool val;
public:
    match_result(): val(false) {};
    match_result(bool v): val(v) {};
    operator bool() {
        return val;
    }
};

using match_bool = match_result<>;

template<size_t N, class Tup>
struct type_at;

template<class Head, class ...Args>
struct type_at<0U, match_result<Head, Args...>> {
    using type = Head;
};

template<size_t N, class Head, class ...Args>
struct type_at<N, match_result<Head, Args...>> {
    using type = typename type_at<N-1, match_result<Args...>>::type;
};

template<size_t N, class Tup>
using type_at_t = typename type_at<N, Tup>::type;

template<class H, class T>
struct cons_match_result;

template<class H, class ...Els>
struct cons_match_result<H, match_result<Els...>> {
    using type = match_result<H, Els...>;
};

template<class L>
struct list2result;

template<class H, class T>
struct list2result<type_list<H, T>> {
    using type = typename cons_match_result<
                    H,
                    typename list2result<T>::type
                 >::type;
};

template<>
struct list2result<nil> {
    using type = match_result<>;
};

template<class Map>
using map2result_t = typename list2result<
                         typename map2list<Map>::type
                     >::type;

}
}

#endif /* MATCH_TUPLE_HPP_ */
