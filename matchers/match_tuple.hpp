/*
 * match_tuple.hpp
 */

#ifndef MATCH_TUPLE_HPP_
#define MATCH_TUPLE_HPP_

#include <utility>

#include "meta.hpp"

namespace functional_hell {
namespace matchers {
/*************************************************************************************************/

namespace impl_ {

struct void_ {};

} /* namespace impl_ */

/*************************************************************************************************/

// TODO: auto-generate all this garbage =(
template<class ...Args>
struct match_tuple;

template<>
struct match_tuple<>{};

#define FIELD(N) \
union { \
    Arg ## N _ ## N; \
    impl_::void_ void_ ## N; \
};\
template<class ...U> \
void set_ ## N(U&& ...v) { \
    new (&_ ## N) Arg ## N (std::forward<U>(v)...); \
    assigned |= (1 << N); \
} \
bool is_set_ ## N() const { \
    return !!(assigned & (1 << N)); \
} \
void destroy_ ## N() { \
    if(is_set_ ## N()) _ ## N . ~Arg ## N (); \
} \


template<class Arg1>
struct match_tuple<Arg1>{
    FIELD(1)

    match_tuple(): void_1{} {};
    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
    }
    match_tuple(match_tuple&& other) {
        if(other.is_set_1()) set_1(std::move(other._1));
    }
    ~match_tuple(){
        destroy_1();
    };
private:
    short assigned = 0;
};

template<class Arg1, class Arg2>
struct match_tuple<Arg1, Arg2>{
    FIELD(1)
    FIELD(2)

    match_tuple(): void_1{}, void_2{} {};
    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
    }
    match_tuple(match_tuple&& other) {
        if(other.is_set_1()) set_1(std::move(other._1));
        if(other.is_set_2()) set_2(std::move(other._2));
    }
    ~match_tuple(){
        destroy_1();
        destroy_2();
    };
private:
    short assigned = 0;
};

template<class Arg1, class Arg2, class Arg3>
struct match_tuple<Arg1, Arg2, Arg3>{
    FIELD(1)
    FIELD(2)
    FIELD(3)

    match_tuple(): void_1{}, void_2{}, void_3{} {};
    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
    }
    match_tuple(match_tuple&& other) {
        if(other.is_set_1()) set_1(std::move(other._1));
        if(other.is_set_2()) set_2(std::move(other._2));
        if(other.is_set_3()) set_3(std::move(other._3));
    }
    ~match_tuple(){
        destroy_1();
        destroy_2();
        destroy_3();
    };
private:
    short assigned = 0;
};

template<class Arg1, class Arg2, class Arg3, class Arg4>
struct match_tuple<Arg1, Arg2, Arg3, Arg4>{
    FIELD(1)
    FIELD(2)
    FIELD(3)
    FIELD(4)

    match_tuple(): void_1{}, void_2{}, void_3{}, void_4{} {};
    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
    }
    match_tuple(match_tuple&& other) {
        if(other.is_set_1()) set_1(std::move(other._1));
        if(other.is_set_2()) set_2(std::move(other._2));
        if(other.is_set_3()) set_3(std::move(other._3));
        if(other.is_set_4()) set_4(std::move(other._4));
    }
    ~match_tuple(){
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
    };
private:
    short assigned = 0;
};

template<class Arg1, class Arg2, class Arg3, class Arg4, class Arg5>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5>{
    FIELD(1)
    FIELD(2)
    FIELD(3)
    FIELD(4)
    FIELD(5)

    match_tuple(): void_1{}, void_2{}, void_3{}, void_5{} {};
    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
    }
    match_tuple(match_tuple&& other) {
        if(other.is_set_1()) set_1(std::move(other._1));
        if(other.is_set_2()) set_2(std::move(other._2));
        if(other.is_set_3()) set_3(std::move(other._3));
        if(other.is_set_4()) set_4(std::move(other._4));
        if(other.is_set_5()) set_5(std::move(other._5));
    }
    ~match_tuple(){
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
    };
private:
    short assigned = 0;
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
    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
    }
    match_tuple(match_tuple&& other) {
        if(other.is_set_1()) set_1(std::move(other._1));
        if(other.is_set_2()) set_2(std::move(other._2));
        if(other.is_set_3()) set_3(std::move(other._3));
        if(other.is_set_4()) set_4(std::move(other._4));
        if(other.is_set_5()) set_5(std::move(other._5));
        if(other.is_set_6()) set_6(std::move(other._6));
    }
    ~match_tuple(){
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
    };
private:
    short assigned = 0;
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
    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
        if(other.is_set_7()) set_7(other._7);
    }
    match_tuple(match_tuple&& other) {
        if(other.is_set_1()) set_1(std::move(other._1));
        if(other.is_set_2()) set_2(std::move(other._2));
        if(other.is_set_3()) set_3(std::move(other._3));
        if(other.is_set_4()) set_4(std::move(other._4));
        if(other.is_set_5()) set_5(std::move(other._5));
        if(other.is_set_6()) set_6(std::move(other._6));
        if(other.is_set_7()) set_7(std::move(other._7));
    }
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
    short assigned = 0;
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
    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
        if(other.is_set_7()) set_7(other._7);
        if(other.is_set_8()) set_8(other._8);
    }
    match_tuple(match_tuple&& other) {
        if(other.is_set_1()) set_1(std::move(other._1));
        if(other.is_set_2()) set_2(std::move(other._2));
        if(other.is_set_3()) set_3(std::move(other._3));
        if(other.is_set_4()) set_4(std::move(other._4));
        if(other.is_set_5()) set_5(std::move(other._5));
        if(other.is_set_6()) set_6(std::move(other._6));
        if(other.is_set_7()) set_7(std::move(other._7));
        if(other.is_set_8()) set_8(std::move(other._8));
    }
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
    short assigned = 0;
};

// poor man's option
template<class ...Args>
class match_result {
    union {
        impl_::void_ null;
        match_tuple<Args...> data;
    };
    bool success;
public:

    void construct() {
        new (&data) match_tuple<Args...>{};
        success = true;
    }

    template<class ...U>
    void construct(U&&... u) {
        new (&data) match_tuple<Args...>{std::forward<U>(u)...};
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

    const match_tuple<Args...>* operator->() const {
        return &data;
    }

    explicit operator bool() {
        return success;
    }

    match_result(): null{}, success{false} {};
    match_result(const match_result& other): null{}, success(other.success) {
        if(success) {
            construct(other.data);
        }
    }
    match_result(match_result&& other): null{}, success(other.success) {
        if(success) {
            construct(std::move(other.data));
        }
    }
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

    void construct() {
        val = true;
    }
};

/*************************************************************************************************/

template<class A, class B>
using match_pair = match_result<A, B>;
using match_bool = match_result<>;

/*************************************************************************************************/

template<std::size_t N, class Tup> struct type_at;
template<class Head, class ...Args>
struct type_at<0U, match_result<Head, Args...>> {
    using type = Head;
};

template<std::size_t N, class Head, class ...Args>
struct type_at<N, match_result<Head, Args...>> {
    using type = typename type_at<N-1, match_result<Args...>>::type;
};

template<std::size_t N, class Tup>
using type_at_t = typename type_at<N, Tup>::type;

/*************************************************************************************************/

namespace impl_ {

/*************************************************************************************************/    

template<class H, class T>
struct cons_match_result;

template<class H, class ...Els>
struct cons_match_result<H, match_result<Els...>> {
    using type = match_result<H, Els...>;
};


/*************************************************************************************************/

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

/*************************************************************************************************/

template<class Map>
using map2result_t = typename list2result<
                         typename impl_::map2list<Map>::type
                     >::type;

/*************************************************************************************************/

template<std::size_t N, class Res> struct getter;

#define GETTER_FOR(N) \
template<class ...T> \
struct getter<(N-1), match_result<T...>> { \
    static auto apply(match_result<T...>& res) -> decltype(res->_ ## N) { \
        return res->_ ## N; \
    }\
    static auto apply(const match_result<T...>& res) -> decltype(res->_ ## N) { \
        return res->_ ## N; \
    } \
};\

GETTER_FOR(1)
GETTER_FOR(2)
GETTER_FOR(3)
GETTER_FOR(4)
GETTER_FOR(5)
GETTER_FOR(6)
GETTER_FOR(7)
GETTER_FOR(8)

#undef GETTER_FOR

/*************************************************************************************************/

template<std::size_t N, class Res> struct setter;

#define SETTER_FOR(N) \
template<class ...T> \
struct setter<(N-1), match_result<T...>> { \
    template<class U> \
    static void apply(match_result<T...>& res, U&& val) { \
        res->set_ ## N(std::forward<U>(val)); \
    }\
};\

SETTER_FOR(1)
SETTER_FOR(2)
SETTER_FOR(3)
SETTER_FOR(4)
SETTER_FOR(5)
SETTER_FOR(6)
SETTER_FOR(7)
SETTER_FOR(8)

#undef SETTER_FOR

/*************************************************************************************************/

template<std::size_t N, class Res>
struct checker;

#define CHECKER_FOR(N) \
template<class ...T> \
struct checker<(N-1), match_result<T...>> { \
    static bool apply(const match_result<T...>& res) { \
        return res->is_set_ ## N(); \
    }\
};\

CHECKER_FOR(1)
CHECKER_FOR(2)
CHECKER_FOR(3)
CHECKER_FOR(4)
CHECKER_FOR(5)
CHECKER_FOR(6)
CHECKER_FOR(7)
CHECKER_FOR(8)

#undef CHECKER_FOR

} /* namespace impl_ */

/*************************************************************************************************/

template<std::size_t N, class MRes>
type_at_t<N, MRes> get(MRes& m) {
    return impl_::getter<N, MRes>::apply(m);
}

template<std::size_t N, class MRes>
type_at_t<N, MRes> get(const MRes& m) {
    return impl_::getter<N, MRes>::apply(m);
}

template<std::size_t N, class MRes, class U>
void set(MRes& m, U&& value) {
    return impl_::setter<N, MRes>::apply(m, std::forward<U>(value));
}

template<std::size_t N, class MRes>
bool is_set(const MRes& m) {
    return impl_::checker<N, MRes>::apply(m);
}

/*************************************************************************************************/

// poor man's reference wrapper
template<class T>
class match_reference {
    T* ref;

public:
    match_reference(T& ref): ref(&ref) {};
    match_reference(const match_reference&) = default;

    T& get() { return *ref; }
    operator T& () { return get(); }
    T& operator()() { return get(); }

    template<class U>
    T& operator= (U&& u)  {
        return *ref = std::forward<U>(u);
    }

};

namespace impl_ {

template<class T> struct wrapped { using type = T; };
template<class T> struct wrapped<T&> { using type = match_reference<T>; };
template<class T> using wrapped_t = typename wrapped<T>::type;

} /* namespace impl_ */

/*************************************************************************************************/

} /* namespace matchers */
} /* namespace functional_hell */

#endif /* MATCH_TUPLE_HPP_ */
