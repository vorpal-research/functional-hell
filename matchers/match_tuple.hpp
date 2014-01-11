/*
    This file is generated from match_tuple.m4
    To regenerate it, run 
    $ m4 match_tuple.m4 >match_tuple.hpp
    You can manually supply the maximum size of tuple (defaults to 16) using
    $ m4 -DMAX_TUPLE_SIZE=62
    where 62 is the new max size
    Be careful though, as this file turns out to be ~11K lines of code for max size of 32

    Current max tuple size is 24
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
/* basic tuple definition */
template<class ...Args> struct match_tuple;
/* empty tuple is, hum, empty */
template<> struct match_tuple<>{};

/*************************************************************************************************/
/* match_tuple of size 1 */
template<
    class Arg1
>
struct match_tuple<Arg1> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }


    match_tuple() : void_1{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
    } 

    template<
       class U1
    > 
    match_tuple(U1&& u1) {
        set_1(std::forward<U1>(u1));
    } 

    match_tuple(match_tuple&& other) {
        if(other.is_set_1()) set_1(std::move(other._1));
    } 

    ~match_tuple() {
        destroy_1();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 2 */
template<
    class Arg1, class Arg2
>
struct match_tuple<Arg1, Arg2> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }


    match_tuple() : void_1{}, void_2{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
    } 

    template<
       class U1, class U2
    > 
    match_tuple(U1&& u1, U2&& u2) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
    } 

    match_tuple(match_tuple&& other) {
        if(other.is_set_1()) set_1(std::move(other._1));
        if(other.is_set_2()) set_2(std::move(other._2));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 3 */
template<
    class Arg1, class Arg2, class Arg3
>
struct match_tuple<Arg1, Arg2, Arg3> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }


    match_tuple() : void_1{}, void_2{}, void_3{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
    } 

    template<
       class U1, class U2, class U3
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
    } 

    match_tuple(match_tuple&& other) {
        if(other.is_set_1()) set_1(std::move(other._1));
        if(other.is_set_2()) set_2(std::move(other._2));
        if(other.is_set_3()) set_3(std::move(other._3));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 4 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
    } 

    template<
       class U1, class U2, class U3, class U4
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
    } 

    match_tuple(match_tuple&& other) {
        if(other.is_set_1()) set_1(std::move(other._1));
        if(other.is_set_2()) set_2(std::move(other._2));
        if(other.is_set_3()) set_3(std::move(other._3));
        if(other.is_set_4()) set_4(std::move(other._4));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 5 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4, class Arg5
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }

    union {
        Arg5 _5;
        impl_::void_ void_5;
    };
    template<class ...U>
    void set_5(U&& ...v) {
        new (&_5) Arg5(std::forward<U>(v)...);
        assigned |= (1 << 5);
    }
    bool is_set_5() const {
        return !!(assigned & (1 << 5));
    }
    void destroy_5() {
        if(is_set_5()) _5.~Arg5();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{}, void_5{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
    } 

    template<
       class U1, class U2, class U3, class U4, class U5
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
        set_5(std::forward<U5>(u5));
    } 

    match_tuple(match_tuple&& other) {
        if(other.is_set_1()) set_1(std::move(other._1));
        if(other.is_set_2()) set_2(std::move(other._2));
        if(other.is_set_3()) set_3(std::move(other._3));
        if(other.is_set_4()) set_4(std::move(other._4));
        if(other.is_set_5()) set_5(std::move(other._5));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 6 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }

    union {
        Arg5 _5;
        impl_::void_ void_5;
    };
    template<class ...U>
    void set_5(U&& ...v) {
        new (&_5) Arg5(std::forward<U>(v)...);
        assigned |= (1 << 5);
    }
    bool is_set_5() const {
        return !!(assigned & (1 << 5));
    }
    void destroy_5() {
        if(is_set_5()) _5.~Arg5();
    }

    union {
        Arg6 _6;
        impl_::void_ void_6;
    };
    template<class ...U>
    void set_6(U&& ...v) {
        new (&_6) Arg6(std::forward<U>(v)...);
        assigned |= (1 << 6);
    }
    bool is_set_6() const {
        return !!(assigned & (1 << 6));
    }
    void destroy_6() {
        if(is_set_6()) _6.~Arg6();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{}, void_5{}, void_6{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
    } 

    template<
       class U1, class U2, class U3, class U4, class U5, class U6
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
        set_5(std::forward<U5>(u5));
        set_6(std::forward<U6>(u6));
    } 

    match_tuple(match_tuple&& other) {
        if(other.is_set_1()) set_1(std::move(other._1));
        if(other.is_set_2()) set_2(std::move(other._2));
        if(other.is_set_3()) set_3(std::move(other._3));
        if(other.is_set_4()) set_4(std::move(other._4));
        if(other.is_set_5()) set_5(std::move(other._5));
        if(other.is_set_6()) set_6(std::move(other._6));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 7 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }

    union {
        Arg5 _5;
        impl_::void_ void_5;
    };
    template<class ...U>
    void set_5(U&& ...v) {
        new (&_5) Arg5(std::forward<U>(v)...);
        assigned |= (1 << 5);
    }
    bool is_set_5() const {
        return !!(assigned & (1 << 5));
    }
    void destroy_5() {
        if(is_set_5()) _5.~Arg5();
    }

    union {
        Arg6 _6;
        impl_::void_ void_6;
    };
    template<class ...U>
    void set_6(U&& ...v) {
        new (&_6) Arg6(std::forward<U>(v)...);
        assigned |= (1 << 6);
    }
    bool is_set_6() const {
        return !!(assigned & (1 << 6));
    }
    void destroy_6() {
        if(is_set_6()) _6.~Arg6();
    }

    union {
        Arg7 _7;
        impl_::void_ void_7;
    };
    template<class ...U>
    void set_7(U&& ...v) {
        new (&_7) Arg7(std::forward<U>(v)...);
        assigned |= (1 << 7);
    }
    bool is_set_7() const {
        return !!(assigned & (1 << 7));
    }
    void destroy_7() {
        if(is_set_7()) _7.~Arg7();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{}, void_5{}, void_6{}, void_7{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
        if(other.is_set_7()) set_7(other._7);
    } 

    template<
       class U1, class U2, class U3, class U4, class U5, class U6, class U7
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
        set_5(std::forward<U5>(u5));
        set_6(std::forward<U6>(u6));
        set_7(std::forward<U7>(u7));
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

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
        destroy_7();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 8 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7,
        class Arg8
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }

    union {
        Arg5 _5;
        impl_::void_ void_5;
    };
    template<class ...U>
    void set_5(U&& ...v) {
        new (&_5) Arg5(std::forward<U>(v)...);
        assigned |= (1 << 5);
    }
    bool is_set_5() const {
        return !!(assigned & (1 << 5));
    }
    void destroy_5() {
        if(is_set_5()) _5.~Arg5();
    }

    union {
        Arg6 _6;
        impl_::void_ void_6;
    };
    template<class ...U>
    void set_6(U&& ...v) {
        new (&_6) Arg6(std::forward<U>(v)...);
        assigned |= (1 << 6);
    }
    bool is_set_6() const {
        return !!(assigned & (1 << 6));
    }
    void destroy_6() {
        if(is_set_6()) _6.~Arg6();
    }

    union {
        Arg7 _7;
        impl_::void_ void_7;
    };
    template<class ...U>
    void set_7(U&& ...v) {
        new (&_7) Arg7(std::forward<U>(v)...);
        assigned |= (1 << 7);
    }
    bool is_set_7() const {
        return !!(assigned & (1 << 7));
    }
    void destroy_7() {
        if(is_set_7()) _7.~Arg7();
    }

    union {
        Arg8 _8;
        impl_::void_ void_8;
    };
    template<class ...U>
    void set_8(U&& ...v) {
        new (&_8) Arg8(std::forward<U>(v)...);
        assigned |= (1 << 8);
    }
    bool is_set_8() const {
        return !!(assigned & (1 << 8));
    }
    void destroy_8() {
        if(is_set_8()) _8.~Arg8();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{}, void_5{}, void_6{}, void_7{}, void_8{} {}

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

    template<
       class U1, class U2, class U3, class U4, class U5, class U6, class U7,
        class U8
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
        set_5(std::forward<U5>(u5));
        set_6(std::forward<U6>(u6));
        set_7(std::forward<U7>(u7));
        set_8(std::forward<U8>(u8));
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

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
        destroy_7();
        destroy_8();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 9 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7,
        class Arg8, class Arg9
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }

    union {
        Arg5 _5;
        impl_::void_ void_5;
    };
    template<class ...U>
    void set_5(U&& ...v) {
        new (&_5) Arg5(std::forward<U>(v)...);
        assigned |= (1 << 5);
    }
    bool is_set_5() const {
        return !!(assigned & (1 << 5));
    }
    void destroy_5() {
        if(is_set_5()) _5.~Arg5();
    }

    union {
        Arg6 _6;
        impl_::void_ void_6;
    };
    template<class ...U>
    void set_6(U&& ...v) {
        new (&_6) Arg6(std::forward<U>(v)...);
        assigned |= (1 << 6);
    }
    bool is_set_6() const {
        return !!(assigned & (1 << 6));
    }
    void destroy_6() {
        if(is_set_6()) _6.~Arg6();
    }

    union {
        Arg7 _7;
        impl_::void_ void_7;
    };
    template<class ...U>
    void set_7(U&& ...v) {
        new (&_7) Arg7(std::forward<U>(v)...);
        assigned |= (1 << 7);
    }
    bool is_set_7() const {
        return !!(assigned & (1 << 7));
    }
    void destroy_7() {
        if(is_set_7()) _7.~Arg7();
    }

    union {
        Arg8 _8;
        impl_::void_ void_8;
    };
    template<class ...U>
    void set_8(U&& ...v) {
        new (&_8) Arg8(std::forward<U>(v)...);
        assigned |= (1 << 8);
    }
    bool is_set_8() const {
        return !!(assigned & (1 << 8));
    }
    void destroy_8() {
        if(is_set_8()) _8.~Arg8();
    }

    union {
        Arg9 _9;
        impl_::void_ void_9;
    };
    template<class ...U>
    void set_9(U&& ...v) {
        new (&_9) Arg9(std::forward<U>(v)...);
        assigned |= (1 << 9);
    }
    bool is_set_9() const {
        return !!(assigned & (1 << 9));
    }
    void destroy_9() {
        if(is_set_9()) _9.~Arg9();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{}, void_5{}, void_6{}, void_7{}, void_8{},
        void_9{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
        if(other.is_set_7()) set_7(other._7);
        if(other.is_set_8()) set_8(other._8);
        if(other.is_set_9()) set_9(other._9);
    } 

    template<
       class U1, class U2, class U3, class U4, class U5, class U6, class U7,
        class U8, class U9
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8,
        U9&& u9) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
        set_5(std::forward<U5>(u5));
        set_6(std::forward<U6>(u6));
        set_7(std::forward<U7>(u7));
        set_8(std::forward<U8>(u8));
        set_9(std::forward<U9>(u9));
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
        if(other.is_set_9()) set_9(std::move(other._9));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
        destroy_7();
        destroy_8();
        destroy_9();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 10 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7,
        class Arg8, class Arg9, class Arg10
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }

    union {
        Arg5 _5;
        impl_::void_ void_5;
    };
    template<class ...U>
    void set_5(U&& ...v) {
        new (&_5) Arg5(std::forward<U>(v)...);
        assigned |= (1 << 5);
    }
    bool is_set_5() const {
        return !!(assigned & (1 << 5));
    }
    void destroy_5() {
        if(is_set_5()) _5.~Arg5();
    }

    union {
        Arg6 _6;
        impl_::void_ void_6;
    };
    template<class ...U>
    void set_6(U&& ...v) {
        new (&_6) Arg6(std::forward<U>(v)...);
        assigned |= (1 << 6);
    }
    bool is_set_6() const {
        return !!(assigned & (1 << 6));
    }
    void destroy_6() {
        if(is_set_6()) _6.~Arg6();
    }

    union {
        Arg7 _7;
        impl_::void_ void_7;
    };
    template<class ...U>
    void set_7(U&& ...v) {
        new (&_7) Arg7(std::forward<U>(v)...);
        assigned |= (1 << 7);
    }
    bool is_set_7() const {
        return !!(assigned & (1 << 7));
    }
    void destroy_7() {
        if(is_set_7()) _7.~Arg7();
    }

    union {
        Arg8 _8;
        impl_::void_ void_8;
    };
    template<class ...U>
    void set_8(U&& ...v) {
        new (&_8) Arg8(std::forward<U>(v)...);
        assigned |= (1 << 8);
    }
    bool is_set_8() const {
        return !!(assigned & (1 << 8));
    }
    void destroy_8() {
        if(is_set_8()) _8.~Arg8();
    }

    union {
        Arg9 _9;
        impl_::void_ void_9;
    };
    template<class ...U>
    void set_9(U&& ...v) {
        new (&_9) Arg9(std::forward<U>(v)...);
        assigned |= (1 << 9);
    }
    bool is_set_9() const {
        return !!(assigned & (1 << 9));
    }
    void destroy_9() {
        if(is_set_9()) _9.~Arg9();
    }

    union {
        Arg10 _10;
        impl_::void_ void_10;
    };
    template<class ...U>
    void set_10(U&& ...v) {
        new (&_10) Arg10(std::forward<U>(v)...);
        assigned |= (1 << 10);
    }
    bool is_set_10() const {
        return !!(assigned & (1 << 10));
    }
    void destroy_10() {
        if(is_set_10()) _10.~Arg10();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{}, void_5{}, void_6{}, void_7{}, void_8{},
        void_9{}, void_10{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
        if(other.is_set_7()) set_7(other._7);
        if(other.is_set_8()) set_8(other._8);
        if(other.is_set_9()) set_9(other._9);
        if(other.is_set_10()) set_10(other._10);
    } 

    template<
       class U1, class U2, class U3, class U4, class U5, class U6, class U7,
        class U8, class U9, class U10
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8,
        U9&& u9, U10&& u10) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
        set_5(std::forward<U5>(u5));
        set_6(std::forward<U6>(u6));
        set_7(std::forward<U7>(u7));
        set_8(std::forward<U8>(u8));
        set_9(std::forward<U9>(u9));
        set_10(std::forward<U10>(u10));
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
        if(other.is_set_9()) set_9(std::move(other._9));
        if(other.is_set_10()) set_10(std::move(other._10));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
        destroy_7();
        destroy_8();
        destroy_9();
        destroy_10();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 11 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7,
        class Arg8, class Arg9, class Arg10, class Arg11
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }

    union {
        Arg5 _5;
        impl_::void_ void_5;
    };
    template<class ...U>
    void set_5(U&& ...v) {
        new (&_5) Arg5(std::forward<U>(v)...);
        assigned |= (1 << 5);
    }
    bool is_set_5() const {
        return !!(assigned & (1 << 5));
    }
    void destroy_5() {
        if(is_set_5()) _5.~Arg5();
    }

    union {
        Arg6 _6;
        impl_::void_ void_6;
    };
    template<class ...U>
    void set_6(U&& ...v) {
        new (&_6) Arg6(std::forward<U>(v)...);
        assigned |= (1 << 6);
    }
    bool is_set_6() const {
        return !!(assigned & (1 << 6));
    }
    void destroy_6() {
        if(is_set_6()) _6.~Arg6();
    }

    union {
        Arg7 _7;
        impl_::void_ void_7;
    };
    template<class ...U>
    void set_7(U&& ...v) {
        new (&_7) Arg7(std::forward<U>(v)...);
        assigned |= (1 << 7);
    }
    bool is_set_7() const {
        return !!(assigned & (1 << 7));
    }
    void destroy_7() {
        if(is_set_7()) _7.~Arg7();
    }

    union {
        Arg8 _8;
        impl_::void_ void_8;
    };
    template<class ...U>
    void set_8(U&& ...v) {
        new (&_8) Arg8(std::forward<U>(v)...);
        assigned |= (1 << 8);
    }
    bool is_set_8() const {
        return !!(assigned & (1 << 8));
    }
    void destroy_8() {
        if(is_set_8()) _8.~Arg8();
    }

    union {
        Arg9 _9;
        impl_::void_ void_9;
    };
    template<class ...U>
    void set_9(U&& ...v) {
        new (&_9) Arg9(std::forward<U>(v)...);
        assigned |= (1 << 9);
    }
    bool is_set_9() const {
        return !!(assigned & (1 << 9));
    }
    void destroy_9() {
        if(is_set_9()) _9.~Arg9();
    }

    union {
        Arg10 _10;
        impl_::void_ void_10;
    };
    template<class ...U>
    void set_10(U&& ...v) {
        new (&_10) Arg10(std::forward<U>(v)...);
        assigned |= (1 << 10);
    }
    bool is_set_10() const {
        return !!(assigned & (1 << 10));
    }
    void destroy_10() {
        if(is_set_10()) _10.~Arg10();
    }

    union {
        Arg11 _11;
        impl_::void_ void_11;
    };
    template<class ...U>
    void set_11(U&& ...v) {
        new (&_11) Arg11(std::forward<U>(v)...);
        assigned |= (1 << 11);
    }
    bool is_set_11() const {
        return !!(assigned & (1 << 11));
    }
    void destroy_11() {
        if(is_set_11()) _11.~Arg11();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{}, void_5{}, void_6{}, void_7{}, void_8{},
        void_9{}, void_10{}, void_11{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
        if(other.is_set_7()) set_7(other._7);
        if(other.is_set_8()) set_8(other._8);
        if(other.is_set_9()) set_9(other._9);
        if(other.is_set_10()) set_10(other._10);
        if(other.is_set_11()) set_11(other._11);
    } 

    template<
       class U1, class U2, class U3, class U4, class U5, class U6, class U7,
        class U8, class U9, class U10, class U11
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8,
        U9&& u9, U10&& u10, U11&& u11) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
        set_5(std::forward<U5>(u5));
        set_6(std::forward<U6>(u6));
        set_7(std::forward<U7>(u7));
        set_8(std::forward<U8>(u8));
        set_9(std::forward<U9>(u9));
        set_10(std::forward<U10>(u10));
        set_11(std::forward<U11>(u11));
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
        if(other.is_set_9()) set_9(std::move(other._9));
        if(other.is_set_10()) set_10(std::move(other._10));
        if(other.is_set_11()) set_11(std::move(other._11));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
        destroy_7();
        destroy_8();
        destroy_9();
        destroy_10();
        destroy_11();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 12 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7,
        class Arg8, class Arg9, class Arg10, class Arg11, class Arg12
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }

    union {
        Arg5 _5;
        impl_::void_ void_5;
    };
    template<class ...U>
    void set_5(U&& ...v) {
        new (&_5) Arg5(std::forward<U>(v)...);
        assigned |= (1 << 5);
    }
    bool is_set_5() const {
        return !!(assigned & (1 << 5));
    }
    void destroy_5() {
        if(is_set_5()) _5.~Arg5();
    }

    union {
        Arg6 _6;
        impl_::void_ void_6;
    };
    template<class ...U>
    void set_6(U&& ...v) {
        new (&_6) Arg6(std::forward<U>(v)...);
        assigned |= (1 << 6);
    }
    bool is_set_6() const {
        return !!(assigned & (1 << 6));
    }
    void destroy_6() {
        if(is_set_6()) _6.~Arg6();
    }

    union {
        Arg7 _7;
        impl_::void_ void_7;
    };
    template<class ...U>
    void set_7(U&& ...v) {
        new (&_7) Arg7(std::forward<U>(v)...);
        assigned |= (1 << 7);
    }
    bool is_set_7() const {
        return !!(assigned & (1 << 7));
    }
    void destroy_7() {
        if(is_set_7()) _7.~Arg7();
    }

    union {
        Arg8 _8;
        impl_::void_ void_8;
    };
    template<class ...U>
    void set_8(U&& ...v) {
        new (&_8) Arg8(std::forward<U>(v)...);
        assigned |= (1 << 8);
    }
    bool is_set_8() const {
        return !!(assigned & (1 << 8));
    }
    void destroy_8() {
        if(is_set_8()) _8.~Arg8();
    }

    union {
        Arg9 _9;
        impl_::void_ void_9;
    };
    template<class ...U>
    void set_9(U&& ...v) {
        new (&_9) Arg9(std::forward<U>(v)...);
        assigned |= (1 << 9);
    }
    bool is_set_9() const {
        return !!(assigned & (1 << 9));
    }
    void destroy_9() {
        if(is_set_9()) _9.~Arg9();
    }

    union {
        Arg10 _10;
        impl_::void_ void_10;
    };
    template<class ...U>
    void set_10(U&& ...v) {
        new (&_10) Arg10(std::forward<U>(v)...);
        assigned |= (1 << 10);
    }
    bool is_set_10() const {
        return !!(assigned & (1 << 10));
    }
    void destroy_10() {
        if(is_set_10()) _10.~Arg10();
    }

    union {
        Arg11 _11;
        impl_::void_ void_11;
    };
    template<class ...U>
    void set_11(U&& ...v) {
        new (&_11) Arg11(std::forward<U>(v)...);
        assigned |= (1 << 11);
    }
    bool is_set_11() const {
        return !!(assigned & (1 << 11));
    }
    void destroy_11() {
        if(is_set_11()) _11.~Arg11();
    }

    union {
        Arg12 _12;
        impl_::void_ void_12;
    };
    template<class ...U>
    void set_12(U&& ...v) {
        new (&_12) Arg12(std::forward<U>(v)...);
        assigned |= (1 << 12);
    }
    bool is_set_12() const {
        return !!(assigned & (1 << 12));
    }
    void destroy_12() {
        if(is_set_12()) _12.~Arg12();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{}, void_5{}, void_6{}, void_7{}, void_8{},
        void_9{}, void_10{}, void_11{}, void_12{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
        if(other.is_set_7()) set_7(other._7);
        if(other.is_set_8()) set_8(other._8);
        if(other.is_set_9()) set_9(other._9);
        if(other.is_set_10()) set_10(other._10);
        if(other.is_set_11()) set_11(other._11);
        if(other.is_set_12()) set_12(other._12);
    } 

    template<
       class U1, class U2, class U3, class U4, class U5, class U6, class U7,
        class U8, class U9, class U10, class U11, class U12
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8,
        U9&& u9, U10&& u10, U11&& u11, U12&& u12) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
        set_5(std::forward<U5>(u5));
        set_6(std::forward<U6>(u6));
        set_7(std::forward<U7>(u7));
        set_8(std::forward<U8>(u8));
        set_9(std::forward<U9>(u9));
        set_10(std::forward<U10>(u10));
        set_11(std::forward<U11>(u11));
        set_12(std::forward<U12>(u12));
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
        if(other.is_set_9()) set_9(std::move(other._9));
        if(other.is_set_10()) set_10(std::move(other._10));
        if(other.is_set_11()) set_11(std::move(other._11));
        if(other.is_set_12()) set_12(std::move(other._12));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
        destroy_7();
        destroy_8();
        destroy_9();
        destroy_10();
        destroy_11();
        destroy_12();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 13 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7,
        class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12,
        Arg13> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }

    union {
        Arg5 _5;
        impl_::void_ void_5;
    };
    template<class ...U>
    void set_5(U&& ...v) {
        new (&_5) Arg5(std::forward<U>(v)...);
        assigned |= (1 << 5);
    }
    bool is_set_5() const {
        return !!(assigned & (1 << 5));
    }
    void destroy_5() {
        if(is_set_5()) _5.~Arg5();
    }

    union {
        Arg6 _6;
        impl_::void_ void_6;
    };
    template<class ...U>
    void set_6(U&& ...v) {
        new (&_6) Arg6(std::forward<U>(v)...);
        assigned |= (1 << 6);
    }
    bool is_set_6() const {
        return !!(assigned & (1 << 6));
    }
    void destroy_6() {
        if(is_set_6()) _6.~Arg6();
    }

    union {
        Arg7 _7;
        impl_::void_ void_7;
    };
    template<class ...U>
    void set_7(U&& ...v) {
        new (&_7) Arg7(std::forward<U>(v)...);
        assigned |= (1 << 7);
    }
    bool is_set_7() const {
        return !!(assigned & (1 << 7));
    }
    void destroy_7() {
        if(is_set_7()) _7.~Arg7();
    }

    union {
        Arg8 _8;
        impl_::void_ void_8;
    };
    template<class ...U>
    void set_8(U&& ...v) {
        new (&_8) Arg8(std::forward<U>(v)...);
        assigned |= (1 << 8);
    }
    bool is_set_8() const {
        return !!(assigned & (1 << 8));
    }
    void destroy_8() {
        if(is_set_8()) _8.~Arg8();
    }

    union {
        Arg9 _9;
        impl_::void_ void_9;
    };
    template<class ...U>
    void set_9(U&& ...v) {
        new (&_9) Arg9(std::forward<U>(v)...);
        assigned |= (1 << 9);
    }
    bool is_set_9() const {
        return !!(assigned & (1 << 9));
    }
    void destroy_9() {
        if(is_set_9()) _9.~Arg9();
    }

    union {
        Arg10 _10;
        impl_::void_ void_10;
    };
    template<class ...U>
    void set_10(U&& ...v) {
        new (&_10) Arg10(std::forward<U>(v)...);
        assigned |= (1 << 10);
    }
    bool is_set_10() const {
        return !!(assigned & (1 << 10));
    }
    void destroy_10() {
        if(is_set_10()) _10.~Arg10();
    }

    union {
        Arg11 _11;
        impl_::void_ void_11;
    };
    template<class ...U>
    void set_11(U&& ...v) {
        new (&_11) Arg11(std::forward<U>(v)...);
        assigned |= (1 << 11);
    }
    bool is_set_11() const {
        return !!(assigned & (1 << 11));
    }
    void destroy_11() {
        if(is_set_11()) _11.~Arg11();
    }

    union {
        Arg12 _12;
        impl_::void_ void_12;
    };
    template<class ...U>
    void set_12(U&& ...v) {
        new (&_12) Arg12(std::forward<U>(v)...);
        assigned |= (1 << 12);
    }
    bool is_set_12() const {
        return !!(assigned & (1 << 12));
    }
    void destroy_12() {
        if(is_set_12()) _12.~Arg12();
    }

    union {
        Arg13 _13;
        impl_::void_ void_13;
    };
    template<class ...U>
    void set_13(U&& ...v) {
        new (&_13) Arg13(std::forward<U>(v)...);
        assigned |= (1 << 13);
    }
    bool is_set_13() const {
        return !!(assigned & (1 << 13));
    }
    void destroy_13() {
        if(is_set_13()) _13.~Arg13();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{}, void_5{}, void_6{}, void_7{}, void_8{},
        void_9{}, void_10{}, void_11{}, void_12{}, void_13{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
        if(other.is_set_7()) set_7(other._7);
        if(other.is_set_8()) set_8(other._8);
        if(other.is_set_9()) set_9(other._9);
        if(other.is_set_10()) set_10(other._10);
        if(other.is_set_11()) set_11(other._11);
        if(other.is_set_12()) set_12(other._12);
        if(other.is_set_13()) set_13(other._13);
    } 

    template<
       class U1, class U2, class U3, class U4, class U5, class U6, class U7,
        class U8, class U9, class U10, class U11, class U12, class U13
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8,
        U9&& u9, U10&& u10, U11&& u11, U12&& u12, U13&& u13) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
        set_5(std::forward<U5>(u5));
        set_6(std::forward<U6>(u6));
        set_7(std::forward<U7>(u7));
        set_8(std::forward<U8>(u8));
        set_9(std::forward<U9>(u9));
        set_10(std::forward<U10>(u10));
        set_11(std::forward<U11>(u11));
        set_12(std::forward<U12>(u12));
        set_13(std::forward<U13>(u13));
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
        if(other.is_set_9()) set_9(std::move(other._9));
        if(other.is_set_10()) set_10(std::move(other._10));
        if(other.is_set_11()) set_11(std::move(other._11));
        if(other.is_set_12()) set_12(std::move(other._12));
        if(other.is_set_13()) set_13(std::move(other._13));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
        destroy_7();
        destroy_8();
        destroy_9();
        destroy_10();
        destroy_11();
        destroy_12();
        destroy_13();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 14 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7,
        class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12,
        Arg13, Arg14> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }

    union {
        Arg5 _5;
        impl_::void_ void_5;
    };
    template<class ...U>
    void set_5(U&& ...v) {
        new (&_5) Arg5(std::forward<U>(v)...);
        assigned |= (1 << 5);
    }
    bool is_set_5() const {
        return !!(assigned & (1 << 5));
    }
    void destroy_5() {
        if(is_set_5()) _5.~Arg5();
    }

    union {
        Arg6 _6;
        impl_::void_ void_6;
    };
    template<class ...U>
    void set_6(U&& ...v) {
        new (&_6) Arg6(std::forward<U>(v)...);
        assigned |= (1 << 6);
    }
    bool is_set_6() const {
        return !!(assigned & (1 << 6));
    }
    void destroy_6() {
        if(is_set_6()) _6.~Arg6();
    }

    union {
        Arg7 _7;
        impl_::void_ void_7;
    };
    template<class ...U>
    void set_7(U&& ...v) {
        new (&_7) Arg7(std::forward<U>(v)...);
        assigned |= (1 << 7);
    }
    bool is_set_7() const {
        return !!(assigned & (1 << 7));
    }
    void destroy_7() {
        if(is_set_7()) _7.~Arg7();
    }

    union {
        Arg8 _8;
        impl_::void_ void_8;
    };
    template<class ...U>
    void set_8(U&& ...v) {
        new (&_8) Arg8(std::forward<U>(v)...);
        assigned |= (1 << 8);
    }
    bool is_set_8() const {
        return !!(assigned & (1 << 8));
    }
    void destroy_8() {
        if(is_set_8()) _8.~Arg8();
    }

    union {
        Arg9 _9;
        impl_::void_ void_9;
    };
    template<class ...U>
    void set_9(U&& ...v) {
        new (&_9) Arg9(std::forward<U>(v)...);
        assigned |= (1 << 9);
    }
    bool is_set_9() const {
        return !!(assigned & (1 << 9));
    }
    void destroy_9() {
        if(is_set_9()) _9.~Arg9();
    }

    union {
        Arg10 _10;
        impl_::void_ void_10;
    };
    template<class ...U>
    void set_10(U&& ...v) {
        new (&_10) Arg10(std::forward<U>(v)...);
        assigned |= (1 << 10);
    }
    bool is_set_10() const {
        return !!(assigned & (1 << 10));
    }
    void destroy_10() {
        if(is_set_10()) _10.~Arg10();
    }

    union {
        Arg11 _11;
        impl_::void_ void_11;
    };
    template<class ...U>
    void set_11(U&& ...v) {
        new (&_11) Arg11(std::forward<U>(v)...);
        assigned |= (1 << 11);
    }
    bool is_set_11() const {
        return !!(assigned & (1 << 11));
    }
    void destroy_11() {
        if(is_set_11()) _11.~Arg11();
    }

    union {
        Arg12 _12;
        impl_::void_ void_12;
    };
    template<class ...U>
    void set_12(U&& ...v) {
        new (&_12) Arg12(std::forward<U>(v)...);
        assigned |= (1 << 12);
    }
    bool is_set_12() const {
        return !!(assigned & (1 << 12));
    }
    void destroy_12() {
        if(is_set_12()) _12.~Arg12();
    }

    union {
        Arg13 _13;
        impl_::void_ void_13;
    };
    template<class ...U>
    void set_13(U&& ...v) {
        new (&_13) Arg13(std::forward<U>(v)...);
        assigned |= (1 << 13);
    }
    bool is_set_13() const {
        return !!(assigned & (1 << 13));
    }
    void destroy_13() {
        if(is_set_13()) _13.~Arg13();
    }

    union {
        Arg14 _14;
        impl_::void_ void_14;
    };
    template<class ...U>
    void set_14(U&& ...v) {
        new (&_14) Arg14(std::forward<U>(v)...);
        assigned |= (1 << 14);
    }
    bool is_set_14() const {
        return !!(assigned & (1 << 14));
    }
    void destroy_14() {
        if(is_set_14()) _14.~Arg14();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{}, void_5{}, void_6{}, void_7{}, void_8{},
        void_9{}, void_10{}, void_11{}, void_12{}, void_13{}, void_14{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
        if(other.is_set_7()) set_7(other._7);
        if(other.is_set_8()) set_8(other._8);
        if(other.is_set_9()) set_9(other._9);
        if(other.is_set_10()) set_10(other._10);
        if(other.is_set_11()) set_11(other._11);
        if(other.is_set_12()) set_12(other._12);
        if(other.is_set_13()) set_13(other._13);
        if(other.is_set_14()) set_14(other._14);
    } 

    template<
       class U1, class U2, class U3, class U4, class U5, class U6, class U7,
        class U8, class U9, class U10, class U11, class U12, class U13, class U14
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8,
        U9&& u9, U10&& u10, U11&& u11, U12&& u12, U13&& u13, U14&& u14) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
        set_5(std::forward<U5>(u5));
        set_6(std::forward<U6>(u6));
        set_7(std::forward<U7>(u7));
        set_8(std::forward<U8>(u8));
        set_9(std::forward<U9>(u9));
        set_10(std::forward<U10>(u10));
        set_11(std::forward<U11>(u11));
        set_12(std::forward<U12>(u12));
        set_13(std::forward<U13>(u13));
        set_14(std::forward<U14>(u14));
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
        if(other.is_set_9()) set_9(std::move(other._9));
        if(other.is_set_10()) set_10(std::move(other._10));
        if(other.is_set_11()) set_11(std::move(other._11));
        if(other.is_set_12()) set_12(std::move(other._12));
        if(other.is_set_13()) set_13(std::move(other._13));
        if(other.is_set_14()) set_14(std::move(other._14));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
        destroy_7();
        destroy_8();
        destroy_9();
        destroy_10();
        destroy_11();
        destroy_12();
        destroy_13();
        destroy_14();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 15 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7,
        class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14,
        class Arg15
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12,
        Arg13, Arg14, Arg15> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }

    union {
        Arg5 _5;
        impl_::void_ void_5;
    };
    template<class ...U>
    void set_5(U&& ...v) {
        new (&_5) Arg5(std::forward<U>(v)...);
        assigned |= (1 << 5);
    }
    bool is_set_5() const {
        return !!(assigned & (1 << 5));
    }
    void destroy_5() {
        if(is_set_5()) _5.~Arg5();
    }

    union {
        Arg6 _6;
        impl_::void_ void_6;
    };
    template<class ...U>
    void set_6(U&& ...v) {
        new (&_6) Arg6(std::forward<U>(v)...);
        assigned |= (1 << 6);
    }
    bool is_set_6() const {
        return !!(assigned & (1 << 6));
    }
    void destroy_6() {
        if(is_set_6()) _6.~Arg6();
    }

    union {
        Arg7 _7;
        impl_::void_ void_7;
    };
    template<class ...U>
    void set_7(U&& ...v) {
        new (&_7) Arg7(std::forward<U>(v)...);
        assigned |= (1 << 7);
    }
    bool is_set_7() const {
        return !!(assigned & (1 << 7));
    }
    void destroy_7() {
        if(is_set_7()) _7.~Arg7();
    }

    union {
        Arg8 _8;
        impl_::void_ void_8;
    };
    template<class ...U>
    void set_8(U&& ...v) {
        new (&_8) Arg8(std::forward<U>(v)...);
        assigned |= (1 << 8);
    }
    bool is_set_8() const {
        return !!(assigned & (1 << 8));
    }
    void destroy_8() {
        if(is_set_8()) _8.~Arg8();
    }

    union {
        Arg9 _9;
        impl_::void_ void_9;
    };
    template<class ...U>
    void set_9(U&& ...v) {
        new (&_9) Arg9(std::forward<U>(v)...);
        assigned |= (1 << 9);
    }
    bool is_set_9() const {
        return !!(assigned & (1 << 9));
    }
    void destroy_9() {
        if(is_set_9()) _9.~Arg9();
    }

    union {
        Arg10 _10;
        impl_::void_ void_10;
    };
    template<class ...U>
    void set_10(U&& ...v) {
        new (&_10) Arg10(std::forward<U>(v)...);
        assigned |= (1 << 10);
    }
    bool is_set_10() const {
        return !!(assigned & (1 << 10));
    }
    void destroy_10() {
        if(is_set_10()) _10.~Arg10();
    }

    union {
        Arg11 _11;
        impl_::void_ void_11;
    };
    template<class ...U>
    void set_11(U&& ...v) {
        new (&_11) Arg11(std::forward<U>(v)...);
        assigned |= (1 << 11);
    }
    bool is_set_11() const {
        return !!(assigned & (1 << 11));
    }
    void destroy_11() {
        if(is_set_11()) _11.~Arg11();
    }

    union {
        Arg12 _12;
        impl_::void_ void_12;
    };
    template<class ...U>
    void set_12(U&& ...v) {
        new (&_12) Arg12(std::forward<U>(v)...);
        assigned |= (1 << 12);
    }
    bool is_set_12() const {
        return !!(assigned & (1 << 12));
    }
    void destroy_12() {
        if(is_set_12()) _12.~Arg12();
    }

    union {
        Arg13 _13;
        impl_::void_ void_13;
    };
    template<class ...U>
    void set_13(U&& ...v) {
        new (&_13) Arg13(std::forward<U>(v)...);
        assigned |= (1 << 13);
    }
    bool is_set_13() const {
        return !!(assigned & (1 << 13));
    }
    void destroy_13() {
        if(is_set_13()) _13.~Arg13();
    }

    union {
        Arg14 _14;
        impl_::void_ void_14;
    };
    template<class ...U>
    void set_14(U&& ...v) {
        new (&_14) Arg14(std::forward<U>(v)...);
        assigned |= (1 << 14);
    }
    bool is_set_14() const {
        return !!(assigned & (1 << 14));
    }
    void destroy_14() {
        if(is_set_14()) _14.~Arg14();
    }

    union {
        Arg15 _15;
        impl_::void_ void_15;
    };
    template<class ...U>
    void set_15(U&& ...v) {
        new (&_15) Arg15(std::forward<U>(v)...);
        assigned |= (1 << 15);
    }
    bool is_set_15() const {
        return !!(assigned & (1 << 15));
    }
    void destroy_15() {
        if(is_set_15()) _15.~Arg15();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{}, void_5{}, void_6{}, void_7{}, void_8{},
        void_9{}, void_10{}, void_11{}, void_12{}, void_13{}, void_14{}, void_15{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
        if(other.is_set_7()) set_7(other._7);
        if(other.is_set_8()) set_8(other._8);
        if(other.is_set_9()) set_9(other._9);
        if(other.is_set_10()) set_10(other._10);
        if(other.is_set_11()) set_11(other._11);
        if(other.is_set_12()) set_12(other._12);
        if(other.is_set_13()) set_13(other._13);
        if(other.is_set_14()) set_14(other._14);
        if(other.is_set_15()) set_15(other._15);
    } 

    template<
       class U1, class U2, class U3, class U4, class U5, class U6, class U7,
        class U8, class U9, class U10, class U11, class U12, class U13, class U14,
        class U15
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8,
        U9&& u9, U10&& u10, U11&& u11, U12&& u12, U13&& u13, U14&& u14, U15&& u15) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
        set_5(std::forward<U5>(u5));
        set_6(std::forward<U6>(u6));
        set_7(std::forward<U7>(u7));
        set_8(std::forward<U8>(u8));
        set_9(std::forward<U9>(u9));
        set_10(std::forward<U10>(u10));
        set_11(std::forward<U11>(u11));
        set_12(std::forward<U12>(u12));
        set_13(std::forward<U13>(u13));
        set_14(std::forward<U14>(u14));
        set_15(std::forward<U15>(u15));
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
        if(other.is_set_9()) set_9(std::move(other._9));
        if(other.is_set_10()) set_10(std::move(other._10));
        if(other.is_set_11()) set_11(std::move(other._11));
        if(other.is_set_12()) set_12(std::move(other._12));
        if(other.is_set_13()) set_13(std::move(other._13));
        if(other.is_set_14()) set_14(std::move(other._14));
        if(other.is_set_15()) set_15(std::move(other._15));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
        destroy_7();
        destroy_8();
        destroy_9();
        destroy_10();
        destroy_11();
        destroy_12();
        destroy_13();
        destroy_14();
        destroy_15();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 16 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7,
        class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14,
        class Arg15, class Arg16
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12,
        Arg13, Arg14, Arg15, Arg16> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }

    union {
        Arg5 _5;
        impl_::void_ void_5;
    };
    template<class ...U>
    void set_5(U&& ...v) {
        new (&_5) Arg5(std::forward<U>(v)...);
        assigned |= (1 << 5);
    }
    bool is_set_5() const {
        return !!(assigned & (1 << 5));
    }
    void destroy_5() {
        if(is_set_5()) _5.~Arg5();
    }

    union {
        Arg6 _6;
        impl_::void_ void_6;
    };
    template<class ...U>
    void set_6(U&& ...v) {
        new (&_6) Arg6(std::forward<U>(v)...);
        assigned |= (1 << 6);
    }
    bool is_set_6() const {
        return !!(assigned & (1 << 6));
    }
    void destroy_6() {
        if(is_set_6()) _6.~Arg6();
    }

    union {
        Arg7 _7;
        impl_::void_ void_7;
    };
    template<class ...U>
    void set_7(U&& ...v) {
        new (&_7) Arg7(std::forward<U>(v)...);
        assigned |= (1 << 7);
    }
    bool is_set_7() const {
        return !!(assigned & (1 << 7));
    }
    void destroy_7() {
        if(is_set_7()) _7.~Arg7();
    }

    union {
        Arg8 _8;
        impl_::void_ void_8;
    };
    template<class ...U>
    void set_8(U&& ...v) {
        new (&_8) Arg8(std::forward<U>(v)...);
        assigned |= (1 << 8);
    }
    bool is_set_8() const {
        return !!(assigned & (1 << 8));
    }
    void destroy_8() {
        if(is_set_8()) _8.~Arg8();
    }

    union {
        Arg9 _9;
        impl_::void_ void_9;
    };
    template<class ...U>
    void set_9(U&& ...v) {
        new (&_9) Arg9(std::forward<U>(v)...);
        assigned |= (1 << 9);
    }
    bool is_set_9() const {
        return !!(assigned & (1 << 9));
    }
    void destroy_9() {
        if(is_set_9()) _9.~Arg9();
    }

    union {
        Arg10 _10;
        impl_::void_ void_10;
    };
    template<class ...U>
    void set_10(U&& ...v) {
        new (&_10) Arg10(std::forward<U>(v)...);
        assigned |= (1 << 10);
    }
    bool is_set_10() const {
        return !!(assigned & (1 << 10));
    }
    void destroy_10() {
        if(is_set_10()) _10.~Arg10();
    }

    union {
        Arg11 _11;
        impl_::void_ void_11;
    };
    template<class ...U>
    void set_11(U&& ...v) {
        new (&_11) Arg11(std::forward<U>(v)...);
        assigned |= (1 << 11);
    }
    bool is_set_11() const {
        return !!(assigned & (1 << 11));
    }
    void destroy_11() {
        if(is_set_11()) _11.~Arg11();
    }

    union {
        Arg12 _12;
        impl_::void_ void_12;
    };
    template<class ...U>
    void set_12(U&& ...v) {
        new (&_12) Arg12(std::forward<U>(v)...);
        assigned |= (1 << 12);
    }
    bool is_set_12() const {
        return !!(assigned & (1 << 12));
    }
    void destroy_12() {
        if(is_set_12()) _12.~Arg12();
    }

    union {
        Arg13 _13;
        impl_::void_ void_13;
    };
    template<class ...U>
    void set_13(U&& ...v) {
        new (&_13) Arg13(std::forward<U>(v)...);
        assigned |= (1 << 13);
    }
    bool is_set_13() const {
        return !!(assigned & (1 << 13));
    }
    void destroy_13() {
        if(is_set_13()) _13.~Arg13();
    }

    union {
        Arg14 _14;
        impl_::void_ void_14;
    };
    template<class ...U>
    void set_14(U&& ...v) {
        new (&_14) Arg14(std::forward<U>(v)...);
        assigned |= (1 << 14);
    }
    bool is_set_14() const {
        return !!(assigned & (1 << 14));
    }
    void destroy_14() {
        if(is_set_14()) _14.~Arg14();
    }

    union {
        Arg15 _15;
        impl_::void_ void_15;
    };
    template<class ...U>
    void set_15(U&& ...v) {
        new (&_15) Arg15(std::forward<U>(v)...);
        assigned |= (1 << 15);
    }
    bool is_set_15() const {
        return !!(assigned & (1 << 15));
    }
    void destroy_15() {
        if(is_set_15()) _15.~Arg15();
    }

    union {
        Arg16 _16;
        impl_::void_ void_16;
    };
    template<class ...U>
    void set_16(U&& ...v) {
        new (&_16) Arg16(std::forward<U>(v)...);
        assigned |= (1 << 16);
    }
    bool is_set_16() const {
        return !!(assigned & (1 << 16));
    }
    void destroy_16() {
        if(is_set_16()) _16.~Arg16();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{}, void_5{}, void_6{}, void_7{}, void_8{},
        void_9{}, void_10{}, void_11{}, void_12{}, void_13{}, void_14{}, void_15{}, void_16{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
        if(other.is_set_7()) set_7(other._7);
        if(other.is_set_8()) set_8(other._8);
        if(other.is_set_9()) set_9(other._9);
        if(other.is_set_10()) set_10(other._10);
        if(other.is_set_11()) set_11(other._11);
        if(other.is_set_12()) set_12(other._12);
        if(other.is_set_13()) set_13(other._13);
        if(other.is_set_14()) set_14(other._14);
        if(other.is_set_15()) set_15(other._15);
        if(other.is_set_16()) set_16(other._16);
    } 

    template<
       class U1, class U2, class U3, class U4, class U5, class U6, class U7,
        class U8, class U9, class U10, class U11, class U12, class U13, class U14,
        class U15, class U16
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8,
        U9&& u9, U10&& u10, U11&& u11, U12&& u12, U13&& u13, U14&& u14, U15&& u15, U16&& u16) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
        set_5(std::forward<U5>(u5));
        set_6(std::forward<U6>(u6));
        set_7(std::forward<U7>(u7));
        set_8(std::forward<U8>(u8));
        set_9(std::forward<U9>(u9));
        set_10(std::forward<U10>(u10));
        set_11(std::forward<U11>(u11));
        set_12(std::forward<U12>(u12));
        set_13(std::forward<U13>(u13));
        set_14(std::forward<U14>(u14));
        set_15(std::forward<U15>(u15));
        set_16(std::forward<U16>(u16));
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
        if(other.is_set_9()) set_9(std::move(other._9));
        if(other.is_set_10()) set_10(std::move(other._10));
        if(other.is_set_11()) set_11(std::move(other._11));
        if(other.is_set_12()) set_12(std::move(other._12));
        if(other.is_set_13()) set_13(std::move(other._13));
        if(other.is_set_14()) set_14(std::move(other._14));
        if(other.is_set_15()) set_15(std::move(other._15));
        if(other.is_set_16()) set_16(std::move(other._16));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
        destroy_7();
        destroy_8();
        destroy_9();
        destroy_10();
        destroy_11();
        destroy_12();
        destroy_13();
        destroy_14();
        destroy_15();
        destroy_16();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 17 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7,
        class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14,
        class Arg15, class Arg16, class Arg17
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12,
        Arg13, Arg14, Arg15, Arg16, Arg17> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }

    union {
        Arg5 _5;
        impl_::void_ void_5;
    };
    template<class ...U>
    void set_5(U&& ...v) {
        new (&_5) Arg5(std::forward<U>(v)...);
        assigned |= (1 << 5);
    }
    bool is_set_5() const {
        return !!(assigned & (1 << 5));
    }
    void destroy_5() {
        if(is_set_5()) _5.~Arg5();
    }

    union {
        Arg6 _6;
        impl_::void_ void_6;
    };
    template<class ...U>
    void set_6(U&& ...v) {
        new (&_6) Arg6(std::forward<U>(v)...);
        assigned |= (1 << 6);
    }
    bool is_set_6() const {
        return !!(assigned & (1 << 6));
    }
    void destroy_6() {
        if(is_set_6()) _6.~Arg6();
    }

    union {
        Arg7 _7;
        impl_::void_ void_7;
    };
    template<class ...U>
    void set_7(U&& ...v) {
        new (&_7) Arg7(std::forward<U>(v)...);
        assigned |= (1 << 7);
    }
    bool is_set_7() const {
        return !!(assigned & (1 << 7));
    }
    void destroy_7() {
        if(is_set_7()) _7.~Arg7();
    }

    union {
        Arg8 _8;
        impl_::void_ void_8;
    };
    template<class ...U>
    void set_8(U&& ...v) {
        new (&_8) Arg8(std::forward<U>(v)...);
        assigned |= (1 << 8);
    }
    bool is_set_8() const {
        return !!(assigned & (1 << 8));
    }
    void destroy_8() {
        if(is_set_8()) _8.~Arg8();
    }

    union {
        Arg9 _9;
        impl_::void_ void_9;
    };
    template<class ...U>
    void set_9(U&& ...v) {
        new (&_9) Arg9(std::forward<U>(v)...);
        assigned |= (1 << 9);
    }
    bool is_set_9() const {
        return !!(assigned & (1 << 9));
    }
    void destroy_9() {
        if(is_set_9()) _9.~Arg9();
    }

    union {
        Arg10 _10;
        impl_::void_ void_10;
    };
    template<class ...U>
    void set_10(U&& ...v) {
        new (&_10) Arg10(std::forward<U>(v)...);
        assigned |= (1 << 10);
    }
    bool is_set_10() const {
        return !!(assigned & (1 << 10));
    }
    void destroy_10() {
        if(is_set_10()) _10.~Arg10();
    }

    union {
        Arg11 _11;
        impl_::void_ void_11;
    };
    template<class ...U>
    void set_11(U&& ...v) {
        new (&_11) Arg11(std::forward<U>(v)...);
        assigned |= (1 << 11);
    }
    bool is_set_11() const {
        return !!(assigned & (1 << 11));
    }
    void destroy_11() {
        if(is_set_11()) _11.~Arg11();
    }

    union {
        Arg12 _12;
        impl_::void_ void_12;
    };
    template<class ...U>
    void set_12(U&& ...v) {
        new (&_12) Arg12(std::forward<U>(v)...);
        assigned |= (1 << 12);
    }
    bool is_set_12() const {
        return !!(assigned & (1 << 12));
    }
    void destroy_12() {
        if(is_set_12()) _12.~Arg12();
    }

    union {
        Arg13 _13;
        impl_::void_ void_13;
    };
    template<class ...U>
    void set_13(U&& ...v) {
        new (&_13) Arg13(std::forward<U>(v)...);
        assigned |= (1 << 13);
    }
    bool is_set_13() const {
        return !!(assigned & (1 << 13));
    }
    void destroy_13() {
        if(is_set_13()) _13.~Arg13();
    }

    union {
        Arg14 _14;
        impl_::void_ void_14;
    };
    template<class ...U>
    void set_14(U&& ...v) {
        new (&_14) Arg14(std::forward<U>(v)...);
        assigned |= (1 << 14);
    }
    bool is_set_14() const {
        return !!(assigned & (1 << 14));
    }
    void destroy_14() {
        if(is_set_14()) _14.~Arg14();
    }

    union {
        Arg15 _15;
        impl_::void_ void_15;
    };
    template<class ...U>
    void set_15(U&& ...v) {
        new (&_15) Arg15(std::forward<U>(v)...);
        assigned |= (1 << 15);
    }
    bool is_set_15() const {
        return !!(assigned & (1 << 15));
    }
    void destroy_15() {
        if(is_set_15()) _15.~Arg15();
    }

    union {
        Arg16 _16;
        impl_::void_ void_16;
    };
    template<class ...U>
    void set_16(U&& ...v) {
        new (&_16) Arg16(std::forward<U>(v)...);
        assigned |= (1 << 16);
    }
    bool is_set_16() const {
        return !!(assigned & (1 << 16));
    }
    void destroy_16() {
        if(is_set_16()) _16.~Arg16();
    }

    union {
        Arg17 _17;
        impl_::void_ void_17;
    };
    template<class ...U>
    void set_17(U&& ...v) {
        new (&_17) Arg17(std::forward<U>(v)...);
        assigned |= (1 << 17);
    }
    bool is_set_17() const {
        return !!(assigned & (1 << 17));
    }
    void destroy_17() {
        if(is_set_17()) _17.~Arg17();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{}, void_5{}, void_6{}, void_7{}, void_8{},
        void_9{}, void_10{}, void_11{}, void_12{}, void_13{}, void_14{}, void_15{}, void_16{},
        void_17{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
        if(other.is_set_7()) set_7(other._7);
        if(other.is_set_8()) set_8(other._8);
        if(other.is_set_9()) set_9(other._9);
        if(other.is_set_10()) set_10(other._10);
        if(other.is_set_11()) set_11(other._11);
        if(other.is_set_12()) set_12(other._12);
        if(other.is_set_13()) set_13(other._13);
        if(other.is_set_14()) set_14(other._14);
        if(other.is_set_15()) set_15(other._15);
        if(other.is_set_16()) set_16(other._16);
        if(other.is_set_17()) set_17(other._17);
    } 

    template<
       class U1, class U2, class U3, class U4, class U5, class U6, class U7,
        class U8, class U9, class U10, class U11, class U12, class U13, class U14,
        class U15, class U16, class U17
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8,
        U9&& u9, U10&& u10, U11&& u11, U12&& u12, U13&& u13, U14&& u14, U15&& u15, U16&& u16,
        U17&& u17) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
        set_5(std::forward<U5>(u5));
        set_6(std::forward<U6>(u6));
        set_7(std::forward<U7>(u7));
        set_8(std::forward<U8>(u8));
        set_9(std::forward<U9>(u9));
        set_10(std::forward<U10>(u10));
        set_11(std::forward<U11>(u11));
        set_12(std::forward<U12>(u12));
        set_13(std::forward<U13>(u13));
        set_14(std::forward<U14>(u14));
        set_15(std::forward<U15>(u15));
        set_16(std::forward<U16>(u16));
        set_17(std::forward<U17>(u17));
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
        if(other.is_set_9()) set_9(std::move(other._9));
        if(other.is_set_10()) set_10(std::move(other._10));
        if(other.is_set_11()) set_11(std::move(other._11));
        if(other.is_set_12()) set_12(std::move(other._12));
        if(other.is_set_13()) set_13(std::move(other._13));
        if(other.is_set_14()) set_14(std::move(other._14));
        if(other.is_set_15()) set_15(std::move(other._15));
        if(other.is_set_16()) set_16(std::move(other._16));
        if(other.is_set_17()) set_17(std::move(other._17));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
        destroy_7();
        destroy_8();
        destroy_9();
        destroy_10();
        destroy_11();
        destroy_12();
        destroy_13();
        destroy_14();
        destroy_15();
        destroy_16();
        destroy_17();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 18 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7,
        class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14,
        class Arg15, class Arg16, class Arg17, class Arg18
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12,
        Arg13, Arg14, Arg15, Arg16, Arg17, Arg18> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }

    union {
        Arg5 _5;
        impl_::void_ void_5;
    };
    template<class ...U>
    void set_5(U&& ...v) {
        new (&_5) Arg5(std::forward<U>(v)...);
        assigned |= (1 << 5);
    }
    bool is_set_5() const {
        return !!(assigned & (1 << 5));
    }
    void destroy_5() {
        if(is_set_5()) _5.~Arg5();
    }

    union {
        Arg6 _6;
        impl_::void_ void_6;
    };
    template<class ...U>
    void set_6(U&& ...v) {
        new (&_6) Arg6(std::forward<U>(v)...);
        assigned |= (1 << 6);
    }
    bool is_set_6() const {
        return !!(assigned & (1 << 6));
    }
    void destroy_6() {
        if(is_set_6()) _6.~Arg6();
    }

    union {
        Arg7 _7;
        impl_::void_ void_7;
    };
    template<class ...U>
    void set_7(U&& ...v) {
        new (&_7) Arg7(std::forward<U>(v)...);
        assigned |= (1 << 7);
    }
    bool is_set_7() const {
        return !!(assigned & (1 << 7));
    }
    void destroy_7() {
        if(is_set_7()) _7.~Arg7();
    }

    union {
        Arg8 _8;
        impl_::void_ void_8;
    };
    template<class ...U>
    void set_8(U&& ...v) {
        new (&_8) Arg8(std::forward<U>(v)...);
        assigned |= (1 << 8);
    }
    bool is_set_8() const {
        return !!(assigned & (1 << 8));
    }
    void destroy_8() {
        if(is_set_8()) _8.~Arg8();
    }

    union {
        Arg9 _9;
        impl_::void_ void_9;
    };
    template<class ...U>
    void set_9(U&& ...v) {
        new (&_9) Arg9(std::forward<U>(v)...);
        assigned |= (1 << 9);
    }
    bool is_set_9() const {
        return !!(assigned & (1 << 9));
    }
    void destroy_9() {
        if(is_set_9()) _9.~Arg9();
    }

    union {
        Arg10 _10;
        impl_::void_ void_10;
    };
    template<class ...U>
    void set_10(U&& ...v) {
        new (&_10) Arg10(std::forward<U>(v)...);
        assigned |= (1 << 10);
    }
    bool is_set_10() const {
        return !!(assigned & (1 << 10));
    }
    void destroy_10() {
        if(is_set_10()) _10.~Arg10();
    }

    union {
        Arg11 _11;
        impl_::void_ void_11;
    };
    template<class ...U>
    void set_11(U&& ...v) {
        new (&_11) Arg11(std::forward<U>(v)...);
        assigned |= (1 << 11);
    }
    bool is_set_11() const {
        return !!(assigned & (1 << 11));
    }
    void destroy_11() {
        if(is_set_11()) _11.~Arg11();
    }

    union {
        Arg12 _12;
        impl_::void_ void_12;
    };
    template<class ...U>
    void set_12(U&& ...v) {
        new (&_12) Arg12(std::forward<U>(v)...);
        assigned |= (1 << 12);
    }
    bool is_set_12() const {
        return !!(assigned & (1 << 12));
    }
    void destroy_12() {
        if(is_set_12()) _12.~Arg12();
    }

    union {
        Arg13 _13;
        impl_::void_ void_13;
    };
    template<class ...U>
    void set_13(U&& ...v) {
        new (&_13) Arg13(std::forward<U>(v)...);
        assigned |= (1 << 13);
    }
    bool is_set_13() const {
        return !!(assigned & (1 << 13));
    }
    void destroy_13() {
        if(is_set_13()) _13.~Arg13();
    }

    union {
        Arg14 _14;
        impl_::void_ void_14;
    };
    template<class ...U>
    void set_14(U&& ...v) {
        new (&_14) Arg14(std::forward<U>(v)...);
        assigned |= (1 << 14);
    }
    bool is_set_14() const {
        return !!(assigned & (1 << 14));
    }
    void destroy_14() {
        if(is_set_14()) _14.~Arg14();
    }

    union {
        Arg15 _15;
        impl_::void_ void_15;
    };
    template<class ...U>
    void set_15(U&& ...v) {
        new (&_15) Arg15(std::forward<U>(v)...);
        assigned |= (1 << 15);
    }
    bool is_set_15() const {
        return !!(assigned & (1 << 15));
    }
    void destroy_15() {
        if(is_set_15()) _15.~Arg15();
    }

    union {
        Arg16 _16;
        impl_::void_ void_16;
    };
    template<class ...U>
    void set_16(U&& ...v) {
        new (&_16) Arg16(std::forward<U>(v)...);
        assigned |= (1 << 16);
    }
    bool is_set_16() const {
        return !!(assigned & (1 << 16));
    }
    void destroy_16() {
        if(is_set_16()) _16.~Arg16();
    }

    union {
        Arg17 _17;
        impl_::void_ void_17;
    };
    template<class ...U>
    void set_17(U&& ...v) {
        new (&_17) Arg17(std::forward<U>(v)...);
        assigned |= (1 << 17);
    }
    bool is_set_17() const {
        return !!(assigned & (1 << 17));
    }
    void destroy_17() {
        if(is_set_17()) _17.~Arg17();
    }

    union {
        Arg18 _18;
        impl_::void_ void_18;
    };
    template<class ...U>
    void set_18(U&& ...v) {
        new (&_18) Arg18(std::forward<U>(v)...);
        assigned |= (1 << 18);
    }
    bool is_set_18() const {
        return !!(assigned & (1 << 18));
    }
    void destroy_18() {
        if(is_set_18()) _18.~Arg18();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{}, void_5{}, void_6{}, void_7{}, void_8{},
        void_9{}, void_10{}, void_11{}, void_12{}, void_13{}, void_14{}, void_15{}, void_16{},
        void_17{}, void_18{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
        if(other.is_set_7()) set_7(other._7);
        if(other.is_set_8()) set_8(other._8);
        if(other.is_set_9()) set_9(other._9);
        if(other.is_set_10()) set_10(other._10);
        if(other.is_set_11()) set_11(other._11);
        if(other.is_set_12()) set_12(other._12);
        if(other.is_set_13()) set_13(other._13);
        if(other.is_set_14()) set_14(other._14);
        if(other.is_set_15()) set_15(other._15);
        if(other.is_set_16()) set_16(other._16);
        if(other.is_set_17()) set_17(other._17);
        if(other.is_set_18()) set_18(other._18);
    } 

    template<
       class U1, class U2, class U3, class U4, class U5, class U6, class U7,
        class U8, class U9, class U10, class U11, class U12, class U13, class U14,
        class U15, class U16, class U17, class U18
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8,
        U9&& u9, U10&& u10, U11&& u11, U12&& u12, U13&& u13, U14&& u14, U15&& u15, U16&& u16,
        U17&& u17, U18&& u18) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
        set_5(std::forward<U5>(u5));
        set_6(std::forward<U6>(u6));
        set_7(std::forward<U7>(u7));
        set_8(std::forward<U8>(u8));
        set_9(std::forward<U9>(u9));
        set_10(std::forward<U10>(u10));
        set_11(std::forward<U11>(u11));
        set_12(std::forward<U12>(u12));
        set_13(std::forward<U13>(u13));
        set_14(std::forward<U14>(u14));
        set_15(std::forward<U15>(u15));
        set_16(std::forward<U16>(u16));
        set_17(std::forward<U17>(u17));
        set_18(std::forward<U18>(u18));
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
        if(other.is_set_9()) set_9(std::move(other._9));
        if(other.is_set_10()) set_10(std::move(other._10));
        if(other.is_set_11()) set_11(std::move(other._11));
        if(other.is_set_12()) set_12(std::move(other._12));
        if(other.is_set_13()) set_13(std::move(other._13));
        if(other.is_set_14()) set_14(std::move(other._14));
        if(other.is_set_15()) set_15(std::move(other._15));
        if(other.is_set_16()) set_16(std::move(other._16));
        if(other.is_set_17()) set_17(std::move(other._17));
        if(other.is_set_18()) set_18(std::move(other._18));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
        destroy_7();
        destroy_8();
        destroy_9();
        destroy_10();
        destroy_11();
        destroy_12();
        destroy_13();
        destroy_14();
        destroy_15();
        destroy_16();
        destroy_17();
        destroy_18();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 19 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7,
        class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14,
        class Arg15, class Arg16, class Arg17, class Arg18, class Arg19
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12,
        Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }

    union {
        Arg5 _5;
        impl_::void_ void_5;
    };
    template<class ...U>
    void set_5(U&& ...v) {
        new (&_5) Arg5(std::forward<U>(v)...);
        assigned |= (1 << 5);
    }
    bool is_set_5() const {
        return !!(assigned & (1 << 5));
    }
    void destroy_5() {
        if(is_set_5()) _5.~Arg5();
    }

    union {
        Arg6 _6;
        impl_::void_ void_6;
    };
    template<class ...U>
    void set_6(U&& ...v) {
        new (&_6) Arg6(std::forward<U>(v)...);
        assigned |= (1 << 6);
    }
    bool is_set_6() const {
        return !!(assigned & (1 << 6));
    }
    void destroy_6() {
        if(is_set_6()) _6.~Arg6();
    }

    union {
        Arg7 _7;
        impl_::void_ void_7;
    };
    template<class ...U>
    void set_7(U&& ...v) {
        new (&_7) Arg7(std::forward<U>(v)...);
        assigned |= (1 << 7);
    }
    bool is_set_7() const {
        return !!(assigned & (1 << 7));
    }
    void destroy_7() {
        if(is_set_7()) _7.~Arg7();
    }

    union {
        Arg8 _8;
        impl_::void_ void_8;
    };
    template<class ...U>
    void set_8(U&& ...v) {
        new (&_8) Arg8(std::forward<U>(v)...);
        assigned |= (1 << 8);
    }
    bool is_set_8() const {
        return !!(assigned & (1 << 8));
    }
    void destroy_8() {
        if(is_set_8()) _8.~Arg8();
    }

    union {
        Arg9 _9;
        impl_::void_ void_9;
    };
    template<class ...U>
    void set_9(U&& ...v) {
        new (&_9) Arg9(std::forward<U>(v)...);
        assigned |= (1 << 9);
    }
    bool is_set_9() const {
        return !!(assigned & (1 << 9));
    }
    void destroy_9() {
        if(is_set_9()) _9.~Arg9();
    }

    union {
        Arg10 _10;
        impl_::void_ void_10;
    };
    template<class ...U>
    void set_10(U&& ...v) {
        new (&_10) Arg10(std::forward<U>(v)...);
        assigned |= (1 << 10);
    }
    bool is_set_10() const {
        return !!(assigned & (1 << 10));
    }
    void destroy_10() {
        if(is_set_10()) _10.~Arg10();
    }

    union {
        Arg11 _11;
        impl_::void_ void_11;
    };
    template<class ...U>
    void set_11(U&& ...v) {
        new (&_11) Arg11(std::forward<U>(v)...);
        assigned |= (1 << 11);
    }
    bool is_set_11() const {
        return !!(assigned & (1 << 11));
    }
    void destroy_11() {
        if(is_set_11()) _11.~Arg11();
    }

    union {
        Arg12 _12;
        impl_::void_ void_12;
    };
    template<class ...U>
    void set_12(U&& ...v) {
        new (&_12) Arg12(std::forward<U>(v)...);
        assigned |= (1 << 12);
    }
    bool is_set_12() const {
        return !!(assigned & (1 << 12));
    }
    void destroy_12() {
        if(is_set_12()) _12.~Arg12();
    }

    union {
        Arg13 _13;
        impl_::void_ void_13;
    };
    template<class ...U>
    void set_13(U&& ...v) {
        new (&_13) Arg13(std::forward<U>(v)...);
        assigned |= (1 << 13);
    }
    bool is_set_13() const {
        return !!(assigned & (1 << 13));
    }
    void destroy_13() {
        if(is_set_13()) _13.~Arg13();
    }

    union {
        Arg14 _14;
        impl_::void_ void_14;
    };
    template<class ...U>
    void set_14(U&& ...v) {
        new (&_14) Arg14(std::forward<U>(v)...);
        assigned |= (1 << 14);
    }
    bool is_set_14() const {
        return !!(assigned & (1 << 14));
    }
    void destroy_14() {
        if(is_set_14()) _14.~Arg14();
    }

    union {
        Arg15 _15;
        impl_::void_ void_15;
    };
    template<class ...U>
    void set_15(U&& ...v) {
        new (&_15) Arg15(std::forward<U>(v)...);
        assigned |= (1 << 15);
    }
    bool is_set_15() const {
        return !!(assigned & (1 << 15));
    }
    void destroy_15() {
        if(is_set_15()) _15.~Arg15();
    }

    union {
        Arg16 _16;
        impl_::void_ void_16;
    };
    template<class ...U>
    void set_16(U&& ...v) {
        new (&_16) Arg16(std::forward<U>(v)...);
        assigned |= (1 << 16);
    }
    bool is_set_16() const {
        return !!(assigned & (1 << 16));
    }
    void destroy_16() {
        if(is_set_16()) _16.~Arg16();
    }

    union {
        Arg17 _17;
        impl_::void_ void_17;
    };
    template<class ...U>
    void set_17(U&& ...v) {
        new (&_17) Arg17(std::forward<U>(v)...);
        assigned |= (1 << 17);
    }
    bool is_set_17() const {
        return !!(assigned & (1 << 17));
    }
    void destroy_17() {
        if(is_set_17()) _17.~Arg17();
    }

    union {
        Arg18 _18;
        impl_::void_ void_18;
    };
    template<class ...U>
    void set_18(U&& ...v) {
        new (&_18) Arg18(std::forward<U>(v)...);
        assigned |= (1 << 18);
    }
    bool is_set_18() const {
        return !!(assigned & (1 << 18));
    }
    void destroy_18() {
        if(is_set_18()) _18.~Arg18();
    }

    union {
        Arg19 _19;
        impl_::void_ void_19;
    };
    template<class ...U>
    void set_19(U&& ...v) {
        new (&_19) Arg19(std::forward<U>(v)...);
        assigned |= (1 << 19);
    }
    bool is_set_19() const {
        return !!(assigned & (1 << 19));
    }
    void destroy_19() {
        if(is_set_19()) _19.~Arg19();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{}, void_5{}, void_6{}, void_7{}, void_8{},
        void_9{}, void_10{}, void_11{}, void_12{}, void_13{}, void_14{}, void_15{}, void_16{},
        void_17{}, void_18{}, void_19{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
        if(other.is_set_7()) set_7(other._7);
        if(other.is_set_8()) set_8(other._8);
        if(other.is_set_9()) set_9(other._9);
        if(other.is_set_10()) set_10(other._10);
        if(other.is_set_11()) set_11(other._11);
        if(other.is_set_12()) set_12(other._12);
        if(other.is_set_13()) set_13(other._13);
        if(other.is_set_14()) set_14(other._14);
        if(other.is_set_15()) set_15(other._15);
        if(other.is_set_16()) set_16(other._16);
        if(other.is_set_17()) set_17(other._17);
        if(other.is_set_18()) set_18(other._18);
        if(other.is_set_19()) set_19(other._19);
    } 

    template<
       class U1, class U2, class U3, class U4, class U5, class U6, class U7,
        class U8, class U9, class U10, class U11, class U12, class U13, class U14,
        class U15, class U16, class U17, class U18, class U19
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8,
        U9&& u9, U10&& u10, U11&& u11, U12&& u12, U13&& u13, U14&& u14, U15&& u15, U16&& u16,
        U17&& u17, U18&& u18, U19&& u19) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
        set_5(std::forward<U5>(u5));
        set_6(std::forward<U6>(u6));
        set_7(std::forward<U7>(u7));
        set_8(std::forward<U8>(u8));
        set_9(std::forward<U9>(u9));
        set_10(std::forward<U10>(u10));
        set_11(std::forward<U11>(u11));
        set_12(std::forward<U12>(u12));
        set_13(std::forward<U13>(u13));
        set_14(std::forward<U14>(u14));
        set_15(std::forward<U15>(u15));
        set_16(std::forward<U16>(u16));
        set_17(std::forward<U17>(u17));
        set_18(std::forward<U18>(u18));
        set_19(std::forward<U19>(u19));
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
        if(other.is_set_9()) set_9(std::move(other._9));
        if(other.is_set_10()) set_10(std::move(other._10));
        if(other.is_set_11()) set_11(std::move(other._11));
        if(other.is_set_12()) set_12(std::move(other._12));
        if(other.is_set_13()) set_13(std::move(other._13));
        if(other.is_set_14()) set_14(std::move(other._14));
        if(other.is_set_15()) set_15(std::move(other._15));
        if(other.is_set_16()) set_16(std::move(other._16));
        if(other.is_set_17()) set_17(std::move(other._17));
        if(other.is_set_18()) set_18(std::move(other._18));
        if(other.is_set_19()) set_19(std::move(other._19));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
        destroy_7();
        destroy_8();
        destroy_9();
        destroy_10();
        destroy_11();
        destroy_12();
        destroy_13();
        destroy_14();
        destroy_15();
        destroy_16();
        destroy_17();
        destroy_18();
        destroy_19();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 20 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7,
        class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14,
        class Arg15, class Arg16, class Arg17, class Arg18, class Arg19, class Arg20
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12,
        Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19, Arg20> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }

    union {
        Arg5 _5;
        impl_::void_ void_5;
    };
    template<class ...U>
    void set_5(U&& ...v) {
        new (&_5) Arg5(std::forward<U>(v)...);
        assigned |= (1 << 5);
    }
    bool is_set_5() const {
        return !!(assigned & (1 << 5));
    }
    void destroy_5() {
        if(is_set_5()) _5.~Arg5();
    }

    union {
        Arg6 _6;
        impl_::void_ void_6;
    };
    template<class ...U>
    void set_6(U&& ...v) {
        new (&_6) Arg6(std::forward<U>(v)...);
        assigned |= (1 << 6);
    }
    bool is_set_6() const {
        return !!(assigned & (1 << 6));
    }
    void destroy_6() {
        if(is_set_6()) _6.~Arg6();
    }

    union {
        Arg7 _7;
        impl_::void_ void_7;
    };
    template<class ...U>
    void set_7(U&& ...v) {
        new (&_7) Arg7(std::forward<U>(v)...);
        assigned |= (1 << 7);
    }
    bool is_set_7() const {
        return !!(assigned & (1 << 7));
    }
    void destroy_7() {
        if(is_set_7()) _7.~Arg7();
    }

    union {
        Arg8 _8;
        impl_::void_ void_8;
    };
    template<class ...U>
    void set_8(U&& ...v) {
        new (&_8) Arg8(std::forward<U>(v)...);
        assigned |= (1 << 8);
    }
    bool is_set_8() const {
        return !!(assigned & (1 << 8));
    }
    void destroy_8() {
        if(is_set_8()) _8.~Arg8();
    }

    union {
        Arg9 _9;
        impl_::void_ void_9;
    };
    template<class ...U>
    void set_9(U&& ...v) {
        new (&_9) Arg9(std::forward<U>(v)...);
        assigned |= (1 << 9);
    }
    bool is_set_9() const {
        return !!(assigned & (1 << 9));
    }
    void destroy_9() {
        if(is_set_9()) _9.~Arg9();
    }

    union {
        Arg10 _10;
        impl_::void_ void_10;
    };
    template<class ...U>
    void set_10(U&& ...v) {
        new (&_10) Arg10(std::forward<U>(v)...);
        assigned |= (1 << 10);
    }
    bool is_set_10() const {
        return !!(assigned & (1 << 10));
    }
    void destroy_10() {
        if(is_set_10()) _10.~Arg10();
    }

    union {
        Arg11 _11;
        impl_::void_ void_11;
    };
    template<class ...U>
    void set_11(U&& ...v) {
        new (&_11) Arg11(std::forward<U>(v)...);
        assigned |= (1 << 11);
    }
    bool is_set_11() const {
        return !!(assigned & (1 << 11));
    }
    void destroy_11() {
        if(is_set_11()) _11.~Arg11();
    }

    union {
        Arg12 _12;
        impl_::void_ void_12;
    };
    template<class ...U>
    void set_12(U&& ...v) {
        new (&_12) Arg12(std::forward<U>(v)...);
        assigned |= (1 << 12);
    }
    bool is_set_12() const {
        return !!(assigned & (1 << 12));
    }
    void destroy_12() {
        if(is_set_12()) _12.~Arg12();
    }

    union {
        Arg13 _13;
        impl_::void_ void_13;
    };
    template<class ...U>
    void set_13(U&& ...v) {
        new (&_13) Arg13(std::forward<U>(v)...);
        assigned |= (1 << 13);
    }
    bool is_set_13() const {
        return !!(assigned & (1 << 13));
    }
    void destroy_13() {
        if(is_set_13()) _13.~Arg13();
    }

    union {
        Arg14 _14;
        impl_::void_ void_14;
    };
    template<class ...U>
    void set_14(U&& ...v) {
        new (&_14) Arg14(std::forward<U>(v)...);
        assigned |= (1 << 14);
    }
    bool is_set_14() const {
        return !!(assigned & (1 << 14));
    }
    void destroy_14() {
        if(is_set_14()) _14.~Arg14();
    }

    union {
        Arg15 _15;
        impl_::void_ void_15;
    };
    template<class ...U>
    void set_15(U&& ...v) {
        new (&_15) Arg15(std::forward<U>(v)...);
        assigned |= (1 << 15);
    }
    bool is_set_15() const {
        return !!(assigned & (1 << 15));
    }
    void destroy_15() {
        if(is_set_15()) _15.~Arg15();
    }

    union {
        Arg16 _16;
        impl_::void_ void_16;
    };
    template<class ...U>
    void set_16(U&& ...v) {
        new (&_16) Arg16(std::forward<U>(v)...);
        assigned |= (1 << 16);
    }
    bool is_set_16() const {
        return !!(assigned & (1 << 16));
    }
    void destroy_16() {
        if(is_set_16()) _16.~Arg16();
    }

    union {
        Arg17 _17;
        impl_::void_ void_17;
    };
    template<class ...U>
    void set_17(U&& ...v) {
        new (&_17) Arg17(std::forward<U>(v)...);
        assigned |= (1 << 17);
    }
    bool is_set_17() const {
        return !!(assigned & (1 << 17));
    }
    void destroy_17() {
        if(is_set_17()) _17.~Arg17();
    }

    union {
        Arg18 _18;
        impl_::void_ void_18;
    };
    template<class ...U>
    void set_18(U&& ...v) {
        new (&_18) Arg18(std::forward<U>(v)...);
        assigned |= (1 << 18);
    }
    bool is_set_18() const {
        return !!(assigned & (1 << 18));
    }
    void destroy_18() {
        if(is_set_18()) _18.~Arg18();
    }

    union {
        Arg19 _19;
        impl_::void_ void_19;
    };
    template<class ...U>
    void set_19(U&& ...v) {
        new (&_19) Arg19(std::forward<U>(v)...);
        assigned |= (1 << 19);
    }
    bool is_set_19() const {
        return !!(assigned & (1 << 19));
    }
    void destroy_19() {
        if(is_set_19()) _19.~Arg19();
    }

    union {
        Arg20 _20;
        impl_::void_ void_20;
    };
    template<class ...U>
    void set_20(U&& ...v) {
        new (&_20) Arg20(std::forward<U>(v)...);
        assigned |= (1 << 20);
    }
    bool is_set_20() const {
        return !!(assigned & (1 << 20));
    }
    void destroy_20() {
        if(is_set_20()) _20.~Arg20();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{}, void_5{}, void_6{}, void_7{}, void_8{},
        void_9{}, void_10{}, void_11{}, void_12{}, void_13{}, void_14{}, void_15{}, void_16{},
        void_17{}, void_18{}, void_19{}, void_20{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
        if(other.is_set_7()) set_7(other._7);
        if(other.is_set_8()) set_8(other._8);
        if(other.is_set_9()) set_9(other._9);
        if(other.is_set_10()) set_10(other._10);
        if(other.is_set_11()) set_11(other._11);
        if(other.is_set_12()) set_12(other._12);
        if(other.is_set_13()) set_13(other._13);
        if(other.is_set_14()) set_14(other._14);
        if(other.is_set_15()) set_15(other._15);
        if(other.is_set_16()) set_16(other._16);
        if(other.is_set_17()) set_17(other._17);
        if(other.is_set_18()) set_18(other._18);
        if(other.is_set_19()) set_19(other._19);
        if(other.is_set_20()) set_20(other._20);
    } 

    template<
       class U1, class U2, class U3, class U4, class U5, class U6, class U7,
        class U8, class U9, class U10, class U11, class U12, class U13, class U14,
        class U15, class U16, class U17, class U18, class U19, class U20
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8,
        U9&& u9, U10&& u10, U11&& u11, U12&& u12, U13&& u13, U14&& u14, U15&& u15, U16&& u16,
        U17&& u17, U18&& u18, U19&& u19, U20&& u20) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
        set_5(std::forward<U5>(u5));
        set_6(std::forward<U6>(u6));
        set_7(std::forward<U7>(u7));
        set_8(std::forward<U8>(u8));
        set_9(std::forward<U9>(u9));
        set_10(std::forward<U10>(u10));
        set_11(std::forward<U11>(u11));
        set_12(std::forward<U12>(u12));
        set_13(std::forward<U13>(u13));
        set_14(std::forward<U14>(u14));
        set_15(std::forward<U15>(u15));
        set_16(std::forward<U16>(u16));
        set_17(std::forward<U17>(u17));
        set_18(std::forward<U18>(u18));
        set_19(std::forward<U19>(u19));
        set_20(std::forward<U20>(u20));
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
        if(other.is_set_9()) set_9(std::move(other._9));
        if(other.is_set_10()) set_10(std::move(other._10));
        if(other.is_set_11()) set_11(std::move(other._11));
        if(other.is_set_12()) set_12(std::move(other._12));
        if(other.is_set_13()) set_13(std::move(other._13));
        if(other.is_set_14()) set_14(std::move(other._14));
        if(other.is_set_15()) set_15(std::move(other._15));
        if(other.is_set_16()) set_16(std::move(other._16));
        if(other.is_set_17()) set_17(std::move(other._17));
        if(other.is_set_18()) set_18(std::move(other._18));
        if(other.is_set_19()) set_19(std::move(other._19));
        if(other.is_set_20()) set_20(std::move(other._20));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
        destroy_7();
        destroy_8();
        destroy_9();
        destroy_10();
        destroy_11();
        destroy_12();
        destroy_13();
        destroy_14();
        destroy_15();
        destroy_16();
        destroy_17();
        destroy_18();
        destroy_19();
        destroy_20();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 21 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7,
        class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14,
        class Arg15, class Arg16, class Arg17, class Arg18, class Arg19, class Arg20, class Arg21
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12,
        Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19, Arg20, Arg21> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }

    union {
        Arg5 _5;
        impl_::void_ void_5;
    };
    template<class ...U>
    void set_5(U&& ...v) {
        new (&_5) Arg5(std::forward<U>(v)...);
        assigned |= (1 << 5);
    }
    bool is_set_5() const {
        return !!(assigned & (1 << 5));
    }
    void destroy_5() {
        if(is_set_5()) _5.~Arg5();
    }

    union {
        Arg6 _6;
        impl_::void_ void_6;
    };
    template<class ...U>
    void set_6(U&& ...v) {
        new (&_6) Arg6(std::forward<U>(v)...);
        assigned |= (1 << 6);
    }
    bool is_set_6() const {
        return !!(assigned & (1 << 6));
    }
    void destroy_6() {
        if(is_set_6()) _6.~Arg6();
    }

    union {
        Arg7 _7;
        impl_::void_ void_7;
    };
    template<class ...U>
    void set_7(U&& ...v) {
        new (&_7) Arg7(std::forward<U>(v)...);
        assigned |= (1 << 7);
    }
    bool is_set_7() const {
        return !!(assigned & (1 << 7));
    }
    void destroy_7() {
        if(is_set_7()) _7.~Arg7();
    }

    union {
        Arg8 _8;
        impl_::void_ void_8;
    };
    template<class ...U>
    void set_8(U&& ...v) {
        new (&_8) Arg8(std::forward<U>(v)...);
        assigned |= (1 << 8);
    }
    bool is_set_8() const {
        return !!(assigned & (1 << 8));
    }
    void destroy_8() {
        if(is_set_8()) _8.~Arg8();
    }

    union {
        Arg9 _9;
        impl_::void_ void_9;
    };
    template<class ...U>
    void set_9(U&& ...v) {
        new (&_9) Arg9(std::forward<U>(v)...);
        assigned |= (1 << 9);
    }
    bool is_set_9() const {
        return !!(assigned & (1 << 9));
    }
    void destroy_9() {
        if(is_set_9()) _9.~Arg9();
    }

    union {
        Arg10 _10;
        impl_::void_ void_10;
    };
    template<class ...U>
    void set_10(U&& ...v) {
        new (&_10) Arg10(std::forward<U>(v)...);
        assigned |= (1 << 10);
    }
    bool is_set_10() const {
        return !!(assigned & (1 << 10));
    }
    void destroy_10() {
        if(is_set_10()) _10.~Arg10();
    }

    union {
        Arg11 _11;
        impl_::void_ void_11;
    };
    template<class ...U>
    void set_11(U&& ...v) {
        new (&_11) Arg11(std::forward<U>(v)...);
        assigned |= (1 << 11);
    }
    bool is_set_11() const {
        return !!(assigned & (1 << 11));
    }
    void destroy_11() {
        if(is_set_11()) _11.~Arg11();
    }

    union {
        Arg12 _12;
        impl_::void_ void_12;
    };
    template<class ...U>
    void set_12(U&& ...v) {
        new (&_12) Arg12(std::forward<U>(v)...);
        assigned |= (1 << 12);
    }
    bool is_set_12() const {
        return !!(assigned & (1 << 12));
    }
    void destroy_12() {
        if(is_set_12()) _12.~Arg12();
    }

    union {
        Arg13 _13;
        impl_::void_ void_13;
    };
    template<class ...U>
    void set_13(U&& ...v) {
        new (&_13) Arg13(std::forward<U>(v)...);
        assigned |= (1 << 13);
    }
    bool is_set_13() const {
        return !!(assigned & (1 << 13));
    }
    void destroy_13() {
        if(is_set_13()) _13.~Arg13();
    }

    union {
        Arg14 _14;
        impl_::void_ void_14;
    };
    template<class ...U>
    void set_14(U&& ...v) {
        new (&_14) Arg14(std::forward<U>(v)...);
        assigned |= (1 << 14);
    }
    bool is_set_14() const {
        return !!(assigned & (1 << 14));
    }
    void destroy_14() {
        if(is_set_14()) _14.~Arg14();
    }

    union {
        Arg15 _15;
        impl_::void_ void_15;
    };
    template<class ...U>
    void set_15(U&& ...v) {
        new (&_15) Arg15(std::forward<U>(v)...);
        assigned |= (1 << 15);
    }
    bool is_set_15() const {
        return !!(assigned & (1 << 15));
    }
    void destroy_15() {
        if(is_set_15()) _15.~Arg15();
    }

    union {
        Arg16 _16;
        impl_::void_ void_16;
    };
    template<class ...U>
    void set_16(U&& ...v) {
        new (&_16) Arg16(std::forward<U>(v)...);
        assigned |= (1 << 16);
    }
    bool is_set_16() const {
        return !!(assigned & (1 << 16));
    }
    void destroy_16() {
        if(is_set_16()) _16.~Arg16();
    }

    union {
        Arg17 _17;
        impl_::void_ void_17;
    };
    template<class ...U>
    void set_17(U&& ...v) {
        new (&_17) Arg17(std::forward<U>(v)...);
        assigned |= (1 << 17);
    }
    bool is_set_17() const {
        return !!(assigned & (1 << 17));
    }
    void destroy_17() {
        if(is_set_17()) _17.~Arg17();
    }

    union {
        Arg18 _18;
        impl_::void_ void_18;
    };
    template<class ...U>
    void set_18(U&& ...v) {
        new (&_18) Arg18(std::forward<U>(v)...);
        assigned |= (1 << 18);
    }
    bool is_set_18() const {
        return !!(assigned & (1 << 18));
    }
    void destroy_18() {
        if(is_set_18()) _18.~Arg18();
    }

    union {
        Arg19 _19;
        impl_::void_ void_19;
    };
    template<class ...U>
    void set_19(U&& ...v) {
        new (&_19) Arg19(std::forward<U>(v)...);
        assigned |= (1 << 19);
    }
    bool is_set_19() const {
        return !!(assigned & (1 << 19));
    }
    void destroy_19() {
        if(is_set_19()) _19.~Arg19();
    }

    union {
        Arg20 _20;
        impl_::void_ void_20;
    };
    template<class ...U>
    void set_20(U&& ...v) {
        new (&_20) Arg20(std::forward<U>(v)...);
        assigned |= (1 << 20);
    }
    bool is_set_20() const {
        return !!(assigned & (1 << 20));
    }
    void destroy_20() {
        if(is_set_20()) _20.~Arg20();
    }

    union {
        Arg21 _21;
        impl_::void_ void_21;
    };
    template<class ...U>
    void set_21(U&& ...v) {
        new (&_21) Arg21(std::forward<U>(v)...);
        assigned |= (1 << 21);
    }
    bool is_set_21() const {
        return !!(assigned & (1 << 21));
    }
    void destroy_21() {
        if(is_set_21()) _21.~Arg21();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{}, void_5{}, void_6{}, void_7{}, void_8{},
        void_9{}, void_10{}, void_11{}, void_12{}, void_13{}, void_14{}, void_15{}, void_16{},
        void_17{}, void_18{}, void_19{}, void_20{}, void_21{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
        if(other.is_set_7()) set_7(other._7);
        if(other.is_set_8()) set_8(other._8);
        if(other.is_set_9()) set_9(other._9);
        if(other.is_set_10()) set_10(other._10);
        if(other.is_set_11()) set_11(other._11);
        if(other.is_set_12()) set_12(other._12);
        if(other.is_set_13()) set_13(other._13);
        if(other.is_set_14()) set_14(other._14);
        if(other.is_set_15()) set_15(other._15);
        if(other.is_set_16()) set_16(other._16);
        if(other.is_set_17()) set_17(other._17);
        if(other.is_set_18()) set_18(other._18);
        if(other.is_set_19()) set_19(other._19);
        if(other.is_set_20()) set_20(other._20);
        if(other.is_set_21()) set_21(other._21);
    } 

    template<
       class U1, class U2, class U3, class U4, class U5, class U6, class U7,
        class U8, class U9, class U10, class U11, class U12, class U13, class U14,
        class U15, class U16, class U17, class U18, class U19, class U20, class U21
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8,
        U9&& u9, U10&& u10, U11&& u11, U12&& u12, U13&& u13, U14&& u14, U15&& u15, U16&& u16,
        U17&& u17, U18&& u18, U19&& u19, U20&& u20, U21&& u21) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
        set_5(std::forward<U5>(u5));
        set_6(std::forward<U6>(u6));
        set_7(std::forward<U7>(u7));
        set_8(std::forward<U8>(u8));
        set_9(std::forward<U9>(u9));
        set_10(std::forward<U10>(u10));
        set_11(std::forward<U11>(u11));
        set_12(std::forward<U12>(u12));
        set_13(std::forward<U13>(u13));
        set_14(std::forward<U14>(u14));
        set_15(std::forward<U15>(u15));
        set_16(std::forward<U16>(u16));
        set_17(std::forward<U17>(u17));
        set_18(std::forward<U18>(u18));
        set_19(std::forward<U19>(u19));
        set_20(std::forward<U20>(u20));
        set_21(std::forward<U21>(u21));
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
        if(other.is_set_9()) set_9(std::move(other._9));
        if(other.is_set_10()) set_10(std::move(other._10));
        if(other.is_set_11()) set_11(std::move(other._11));
        if(other.is_set_12()) set_12(std::move(other._12));
        if(other.is_set_13()) set_13(std::move(other._13));
        if(other.is_set_14()) set_14(std::move(other._14));
        if(other.is_set_15()) set_15(std::move(other._15));
        if(other.is_set_16()) set_16(std::move(other._16));
        if(other.is_set_17()) set_17(std::move(other._17));
        if(other.is_set_18()) set_18(std::move(other._18));
        if(other.is_set_19()) set_19(std::move(other._19));
        if(other.is_set_20()) set_20(std::move(other._20));
        if(other.is_set_21()) set_21(std::move(other._21));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
        destroy_7();
        destroy_8();
        destroy_9();
        destroy_10();
        destroy_11();
        destroy_12();
        destroy_13();
        destroy_14();
        destroy_15();
        destroy_16();
        destroy_17();
        destroy_18();
        destroy_19();
        destroy_20();
        destroy_21();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 22 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7,
        class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14,
        class Arg15, class Arg16, class Arg17, class Arg18, class Arg19, class Arg20, class Arg21,
        class Arg22
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12,
        Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19, Arg20, Arg21, Arg22> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }

    union {
        Arg5 _5;
        impl_::void_ void_5;
    };
    template<class ...U>
    void set_5(U&& ...v) {
        new (&_5) Arg5(std::forward<U>(v)...);
        assigned |= (1 << 5);
    }
    bool is_set_5() const {
        return !!(assigned & (1 << 5));
    }
    void destroy_5() {
        if(is_set_5()) _5.~Arg5();
    }

    union {
        Arg6 _6;
        impl_::void_ void_6;
    };
    template<class ...U>
    void set_6(U&& ...v) {
        new (&_6) Arg6(std::forward<U>(v)...);
        assigned |= (1 << 6);
    }
    bool is_set_6() const {
        return !!(assigned & (1 << 6));
    }
    void destroy_6() {
        if(is_set_6()) _6.~Arg6();
    }

    union {
        Arg7 _7;
        impl_::void_ void_7;
    };
    template<class ...U>
    void set_7(U&& ...v) {
        new (&_7) Arg7(std::forward<U>(v)...);
        assigned |= (1 << 7);
    }
    bool is_set_7() const {
        return !!(assigned & (1 << 7));
    }
    void destroy_7() {
        if(is_set_7()) _7.~Arg7();
    }

    union {
        Arg8 _8;
        impl_::void_ void_8;
    };
    template<class ...U>
    void set_8(U&& ...v) {
        new (&_8) Arg8(std::forward<U>(v)...);
        assigned |= (1 << 8);
    }
    bool is_set_8() const {
        return !!(assigned & (1 << 8));
    }
    void destroy_8() {
        if(is_set_8()) _8.~Arg8();
    }

    union {
        Arg9 _9;
        impl_::void_ void_9;
    };
    template<class ...U>
    void set_9(U&& ...v) {
        new (&_9) Arg9(std::forward<U>(v)...);
        assigned |= (1 << 9);
    }
    bool is_set_9() const {
        return !!(assigned & (1 << 9));
    }
    void destroy_9() {
        if(is_set_9()) _9.~Arg9();
    }

    union {
        Arg10 _10;
        impl_::void_ void_10;
    };
    template<class ...U>
    void set_10(U&& ...v) {
        new (&_10) Arg10(std::forward<U>(v)...);
        assigned |= (1 << 10);
    }
    bool is_set_10() const {
        return !!(assigned & (1 << 10));
    }
    void destroy_10() {
        if(is_set_10()) _10.~Arg10();
    }

    union {
        Arg11 _11;
        impl_::void_ void_11;
    };
    template<class ...U>
    void set_11(U&& ...v) {
        new (&_11) Arg11(std::forward<U>(v)...);
        assigned |= (1 << 11);
    }
    bool is_set_11() const {
        return !!(assigned & (1 << 11));
    }
    void destroy_11() {
        if(is_set_11()) _11.~Arg11();
    }

    union {
        Arg12 _12;
        impl_::void_ void_12;
    };
    template<class ...U>
    void set_12(U&& ...v) {
        new (&_12) Arg12(std::forward<U>(v)...);
        assigned |= (1 << 12);
    }
    bool is_set_12() const {
        return !!(assigned & (1 << 12));
    }
    void destroy_12() {
        if(is_set_12()) _12.~Arg12();
    }

    union {
        Arg13 _13;
        impl_::void_ void_13;
    };
    template<class ...U>
    void set_13(U&& ...v) {
        new (&_13) Arg13(std::forward<U>(v)...);
        assigned |= (1 << 13);
    }
    bool is_set_13() const {
        return !!(assigned & (1 << 13));
    }
    void destroy_13() {
        if(is_set_13()) _13.~Arg13();
    }

    union {
        Arg14 _14;
        impl_::void_ void_14;
    };
    template<class ...U>
    void set_14(U&& ...v) {
        new (&_14) Arg14(std::forward<U>(v)...);
        assigned |= (1 << 14);
    }
    bool is_set_14() const {
        return !!(assigned & (1 << 14));
    }
    void destroy_14() {
        if(is_set_14()) _14.~Arg14();
    }

    union {
        Arg15 _15;
        impl_::void_ void_15;
    };
    template<class ...U>
    void set_15(U&& ...v) {
        new (&_15) Arg15(std::forward<U>(v)...);
        assigned |= (1 << 15);
    }
    bool is_set_15() const {
        return !!(assigned & (1 << 15));
    }
    void destroy_15() {
        if(is_set_15()) _15.~Arg15();
    }

    union {
        Arg16 _16;
        impl_::void_ void_16;
    };
    template<class ...U>
    void set_16(U&& ...v) {
        new (&_16) Arg16(std::forward<U>(v)...);
        assigned |= (1 << 16);
    }
    bool is_set_16() const {
        return !!(assigned & (1 << 16));
    }
    void destroy_16() {
        if(is_set_16()) _16.~Arg16();
    }

    union {
        Arg17 _17;
        impl_::void_ void_17;
    };
    template<class ...U>
    void set_17(U&& ...v) {
        new (&_17) Arg17(std::forward<U>(v)...);
        assigned |= (1 << 17);
    }
    bool is_set_17() const {
        return !!(assigned & (1 << 17));
    }
    void destroy_17() {
        if(is_set_17()) _17.~Arg17();
    }

    union {
        Arg18 _18;
        impl_::void_ void_18;
    };
    template<class ...U>
    void set_18(U&& ...v) {
        new (&_18) Arg18(std::forward<U>(v)...);
        assigned |= (1 << 18);
    }
    bool is_set_18() const {
        return !!(assigned & (1 << 18));
    }
    void destroy_18() {
        if(is_set_18()) _18.~Arg18();
    }

    union {
        Arg19 _19;
        impl_::void_ void_19;
    };
    template<class ...U>
    void set_19(U&& ...v) {
        new (&_19) Arg19(std::forward<U>(v)...);
        assigned |= (1 << 19);
    }
    bool is_set_19() const {
        return !!(assigned & (1 << 19));
    }
    void destroy_19() {
        if(is_set_19()) _19.~Arg19();
    }

    union {
        Arg20 _20;
        impl_::void_ void_20;
    };
    template<class ...U>
    void set_20(U&& ...v) {
        new (&_20) Arg20(std::forward<U>(v)...);
        assigned |= (1 << 20);
    }
    bool is_set_20() const {
        return !!(assigned & (1 << 20));
    }
    void destroy_20() {
        if(is_set_20()) _20.~Arg20();
    }

    union {
        Arg21 _21;
        impl_::void_ void_21;
    };
    template<class ...U>
    void set_21(U&& ...v) {
        new (&_21) Arg21(std::forward<U>(v)...);
        assigned |= (1 << 21);
    }
    bool is_set_21() const {
        return !!(assigned & (1 << 21));
    }
    void destroy_21() {
        if(is_set_21()) _21.~Arg21();
    }

    union {
        Arg22 _22;
        impl_::void_ void_22;
    };
    template<class ...U>
    void set_22(U&& ...v) {
        new (&_22) Arg22(std::forward<U>(v)...);
        assigned |= (1 << 22);
    }
    bool is_set_22() const {
        return !!(assigned & (1 << 22));
    }
    void destroy_22() {
        if(is_set_22()) _22.~Arg22();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{}, void_5{}, void_6{}, void_7{}, void_8{},
        void_9{}, void_10{}, void_11{}, void_12{}, void_13{}, void_14{}, void_15{}, void_16{},
        void_17{}, void_18{}, void_19{}, void_20{}, void_21{}, void_22{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
        if(other.is_set_7()) set_7(other._7);
        if(other.is_set_8()) set_8(other._8);
        if(other.is_set_9()) set_9(other._9);
        if(other.is_set_10()) set_10(other._10);
        if(other.is_set_11()) set_11(other._11);
        if(other.is_set_12()) set_12(other._12);
        if(other.is_set_13()) set_13(other._13);
        if(other.is_set_14()) set_14(other._14);
        if(other.is_set_15()) set_15(other._15);
        if(other.is_set_16()) set_16(other._16);
        if(other.is_set_17()) set_17(other._17);
        if(other.is_set_18()) set_18(other._18);
        if(other.is_set_19()) set_19(other._19);
        if(other.is_set_20()) set_20(other._20);
        if(other.is_set_21()) set_21(other._21);
        if(other.is_set_22()) set_22(other._22);
    } 

    template<
       class U1, class U2, class U3, class U4, class U5, class U6, class U7,
        class U8, class U9, class U10, class U11, class U12, class U13, class U14,
        class U15, class U16, class U17, class U18, class U19, class U20, class U21,
        class U22
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8,
        U9&& u9, U10&& u10, U11&& u11, U12&& u12, U13&& u13, U14&& u14, U15&& u15, U16&& u16,
        U17&& u17, U18&& u18, U19&& u19, U20&& u20, U21&& u21, U22&& u22) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
        set_5(std::forward<U5>(u5));
        set_6(std::forward<U6>(u6));
        set_7(std::forward<U7>(u7));
        set_8(std::forward<U8>(u8));
        set_9(std::forward<U9>(u9));
        set_10(std::forward<U10>(u10));
        set_11(std::forward<U11>(u11));
        set_12(std::forward<U12>(u12));
        set_13(std::forward<U13>(u13));
        set_14(std::forward<U14>(u14));
        set_15(std::forward<U15>(u15));
        set_16(std::forward<U16>(u16));
        set_17(std::forward<U17>(u17));
        set_18(std::forward<U18>(u18));
        set_19(std::forward<U19>(u19));
        set_20(std::forward<U20>(u20));
        set_21(std::forward<U21>(u21));
        set_22(std::forward<U22>(u22));
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
        if(other.is_set_9()) set_9(std::move(other._9));
        if(other.is_set_10()) set_10(std::move(other._10));
        if(other.is_set_11()) set_11(std::move(other._11));
        if(other.is_set_12()) set_12(std::move(other._12));
        if(other.is_set_13()) set_13(std::move(other._13));
        if(other.is_set_14()) set_14(std::move(other._14));
        if(other.is_set_15()) set_15(std::move(other._15));
        if(other.is_set_16()) set_16(std::move(other._16));
        if(other.is_set_17()) set_17(std::move(other._17));
        if(other.is_set_18()) set_18(std::move(other._18));
        if(other.is_set_19()) set_19(std::move(other._19));
        if(other.is_set_20()) set_20(std::move(other._20));
        if(other.is_set_21()) set_21(std::move(other._21));
        if(other.is_set_22()) set_22(std::move(other._22));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
        destroy_7();
        destroy_8();
        destroy_9();
        destroy_10();
        destroy_11();
        destroy_12();
        destroy_13();
        destroy_14();
        destroy_15();
        destroy_16();
        destroy_17();
        destroy_18();
        destroy_19();
        destroy_20();
        destroy_21();
        destroy_22();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 23 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7,
        class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14,
        class Arg15, class Arg16, class Arg17, class Arg18, class Arg19, class Arg20, class Arg21,
        class Arg22, class Arg23
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12,
        Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19, Arg20, Arg21, Arg22, Arg23> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }

    union {
        Arg5 _5;
        impl_::void_ void_5;
    };
    template<class ...U>
    void set_5(U&& ...v) {
        new (&_5) Arg5(std::forward<U>(v)...);
        assigned |= (1 << 5);
    }
    bool is_set_5() const {
        return !!(assigned & (1 << 5));
    }
    void destroy_5() {
        if(is_set_5()) _5.~Arg5();
    }

    union {
        Arg6 _6;
        impl_::void_ void_6;
    };
    template<class ...U>
    void set_6(U&& ...v) {
        new (&_6) Arg6(std::forward<U>(v)...);
        assigned |= (1 << 6);
    }
    bool is_set_6() const {
        return !!(assigned & (1 << 6));
    }
    void destroy_6() {
        if(is_set_6()) _6.~Arg6();
    }

    union {
        Arg7 _7;
        impl_::void_ void_7;
    };
    template<class ...U>
    void set_7(U&& ...v) {
        new (&_7) Arg7(std::forward<U>(v)...);
        assigned |= (1 << 7);
    }
    bool is_set_7() const {
        return !!(assigned & (1 << 7));
    }
    void destroy_7() {
        if(is_set_7()) _7.~Arg7();
    }

    union {
        Arg8 _8;
        impl_::void_ void_8;
    };
    template<class ...U>
    void set_8(U&& ...v) {
        new (&_8) Arg8(std::forward<U>(v)...);
        assigned |= (1 << 8);
    }
    bool is_set_8() const {
        return !!(assigned & (1 << 8));
    }
    void destroy_8() {
        if(is_set_8()) _8.~Arg8();
    }

    union {
        Arg9 _9;
        impl_::void_ void_9;
    };
    template<class ...U>
    void set_9(U&& ...v) {
        new (&_9) Arg9(std::forward<U>(v)...);
        assigned |= (1 << 9);
    }
    bool is_set_9() const {
        return !!(assigned & (1 << 9));
    }
    void destroy_9() {
        if(is_set_9()) _9.~Arg9();
    }

    union {
        Arg10 _10;
        impl_::void_ void_10;
    };
    template<class ...U>
    void set_10(U&& ...v) {
        new (&_10) Arg10(std::forward<U>(v)...);
        assigned |= (1 << 10);
    }
    bool is_set_10() const {
        return !!(assigned & (1 << 10));
    }
    void destroy_10() {
        if(is_set_10()) _10.~Arg10();
    }

    union {
        Arg11 _11;
        impl_::void_ void_11;
    };
    template<class ...U>
    void set_11(U&& ...v) {
        new (&_11) Arg11(std::forward<U>(v)...);
        assigned |= (1 << 11);
    }
    bool is_set_11() const {
        return !!(assigned & (1 << 11));
    }
    void destroy_11() {
        if(is_set_11()) _11.~Arg11();
    }

    union {
        Arg12 _12;
        impl_::void_ void_12;
    };
    template<class ...U>
    void set_12(U&& ...v) {
        new (&_12) Arg12(std::forward<U>(v)...);
        assigned |= (1 << 12);
    }
    bool is_set_12() const {
        return !!(assigned & (1 << 12));
    }
    void destroy_12() {
        if(is_set_12()) _12.~Arg12();
    }

    union {
        Arg13 _13;
        impl_::void_ void_13;
    };
    template<class ...U>
    void set_13(U&& ...v) {
        new (&_13) Arg13(std::forward<U>(v)...);
        assigned |= (1 << 13);
    }
    bool is_set_13() const {
        return !!(assigned & (1 << 13));
    }
    void destroy_13() {
        if(is_set_13()) _13.~Arg13();
    }

    union {
        Arg14 _14;
        impl_::void_ void_14;
    };
    template<class ...U>
    void set_14(U&& ...v) {
        new (&_14) Arg14(std::forward<U>(v)...);
        assigned |= (1 << 14);
    }
    bool is_set_14() const {
        return !!(assigned & (1 << 14));
    }
    void destroy_14() {
        if(is_set_14()) _14.~Arg14();
    }

    union {
        Arg15 _15;
        impl_::void_ void_15;
    };
    template<class ...U>
    void set_15(U&& ...v) {
        new (&_15) Arg15(std::forward<U>(v)...);
        assigned |= (1 << 15);
    }
    bool is_set_15() const {
        return !!(assigned & (1 << 15));
    }
    void destroy_15() {
        if(is_set_15()) _15.~Arg15();
    }

    union {
        Arg16 _16;
        impl_::void_ void_16;
    };
    template<class ...U>
    void set_16(U&& ...v) {
        new (&_16) Arg16(std::forward<U>(v)...);
        assigned |= (1 << 16);
    }
    bool is_set_16() const {
        return !!(assigned & (1 << 16));
    }
    void destroy_16() {
        if(is_set_16()) _16.~Arg16();
    }

    union {
        Arg17 _17;
        impl_::void_ void_17;
    };
    template<class ...U>
    void set_17(U&& ...v) {
        new (&_17) Arg17(std::forward<U>(v)...);
        assigned |= (1 << 17);
    }
    bool is_set_17() const {
        return !!(assigned & (1 << 17));
    }
    void destroy_17() {
        if(is_set_17()) _17.~Arg17();
    }

    union {
        Arg18 _18;
        impl_::void_ void_18;
    };
    template<class ...U>
    void set_18(U&& ...v) {
        new (&_18) Arg18(std::forward<U>(v)...);
        assigned |= (1 << 18);
    }
    bool is_set_18() const {
        return !!(assigned & (1 << 18));
    }
    void destroy_18() {
        if(is_set_18()) _18.~Arg18();
    }

    union {
        Arg19 _19;
        impl_::void_ void_19;
    };
    template<class ...U>
    void set_19(U&& ...v) {
        new (&_19) Arg19(std::forward<U>(v)...);
        assigned |= (1 << 19);
    }
    bool is_set_19() const {
        return !!(assigned & (1 << 19));
    }
    void destroy_19() {
        if(is_set_19()) _19.~Arg19();
    }

    union {
        Arg20 _20;
        impl_::void_ void_20;
    };
    template<class ...U>
    void set_20(U&& ...v) {
        new (&_20) Arg20(std::forward<U>(v)...);
        assigned |= (1 << 20);
    }
    bool is_set_20() const {
        return !!(assigned & (1 << 20));
    }
    void destroy_20() {
        if(is_set_20()) _20.~Arg20();
    }

    union {
        Arg21 _21;
        impl_::void_ void_21;
    };
    template<class ...U>
    void set_21(U&& ...v) {
        new (&_21) Arg21(std::forward<U>(v)...);
        assigned |= (1 << 21);
    }
    bool is_set_21() const {
        return !!(assigned & (1 << 21));
    }
    void destroy_21() {
        if(is_set_21()) _21.~Arg21();
    }

    union {
        Arg22 _22;
        impl_::void_ void_22;
    };
    template<class ...U>
    void set_22(U&& ...v) {
        new (&_22) Arg22(std::forward<U>(v)...);
        assigned |= (1 << 22);
    }
    bool is_set_22() const {
        return !!(assigned & (1 << 22));
    }
    void destroy_22() {
        if(is_set_22()) _22.~Arg22();
    }

    union {
        Arg23 _23;
        impl_::void_ void_23;
    };
    template<class ...U>
    void set_23(U&& ...v) {
        new (&_23) Arg23(std::forward<U>(v)...);
        assigned |= (1 << 23);
    }
    bool is_set_23() const {
        return !!(assigned & (1 << 23));
    }
    void destroy_23() {
        if(is_set_23()) _23.~Arg23();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{}, void_5{}, void_6{}, void_7{}, void_8{},
        void_9{}, void_10{}, void_11{}, void_12{}, void_13{}, void_14{}, void_15{}, void_16{},
        void_17{}, void_18{}, void_19{}, void_20{}, void_21{}, void_22{}, void_23{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
        if(other.is_set_7()) set_7(other._7);
        if(other.is_set_8()) set_8(other._8);
        if(other.is_set_9()) set_9(other._9);
        if(other.is_set_10()) set_10(other._10);
        if(other.is_set_11()) set_11(other._11);
        if(other.is_set_12()) set_12(other._12);
        if(other.is_set_13()) set_13(other._13);
        if(other.is_set_14()) set_14(other._14);
        if(other.is_set_15()) set_15(other._15);
        if(other.is_set_16()) set_16(other._16);
        if(other.is_set_17()) set_17(other._17);
        if(other.is_set_18()) set_18(other._18);
        if(other.is_set_19()) set_19(other._19);
        if(other.is_set_20()) set_20(other._20);
        if(other.is_set_21()) set_21(other._21);
        if(other.is_set_22()) set_22(other._22);
        if(other.is_set_23()) set_23(other._23);
    } 

    template<
       class U1, class U2, class U3, class U4, class U5, class U6, class U7,
        class U8, class U9, class U10, class U11, class U12, class U13, class U14,
        class U15, class U16, class U17, class U18, class U19, class U20, class U21,
        class U22, class U23
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8,
        U9&& u9, U10&& u10, U11&& u11, U12&& u12, U13&& u13, U14&& u14, U15&& u15, U16&& u16,
        U17&& u17, U18&& u18, U19&& u19, U20&& u20, U21&& u21, U22&& u22, U23&& u23) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
        set_5(std::forward<U5>(u5));
        set_6(std::forward<U6>(u6));
        set_7(std::forward<U7>(u7));
        set_8(std::forward<U8>(u8));
        set_9(std::forward<U9>(u9));
        set_10(std::forward<U10>(u10));
        set_11(std::forward<U11>(u11));
        set_12(std::forward<U12>(u12));
        set_13(std::forward<U13>(u13));
        set_14(std::forward<U14>(u14));
        set_15(std::forward<U15>(u15));
        set_16(std::forward<U16>(u16));
        set_17(std::forward<U17>(u17));
        set_18(std::forward<U18>(u18));
        set_19(std::forward<U19>(u19));
        set_20(std::forward<U20>(u20));
        set_21(std::forward<U21>(u21));
        set_22(std::forward<U22>(u22));
        set_23(std::forward<U23>(u23));
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
        if(other.is_set_9()) set_9(std::move(other._9));
        if(other.is_set_10()) set_10(std::move(other._10));
        if(other.is_set_11()) set_11(std::move(other._11));
        if(other.is_set_12()) set_12(std::move(other._12));
        if(other.is_set_13()) set_13(std::move(other._13));
        if(other.is_set_14()) set_14(std::move(other._14));
        if(other.is_set_15()) set_15(std::move(other._15));
        if(other.is_set_16()) set_16(std::move(other._16));
        if(other.is_set_17()) set_17(std::move(other._17));
        if(other.is_set_18()) set_18(std::move(other._18));
        if(other.is_set_19()) set_19(std::move(other._19));
        if(other.is_set_20()) set_20(std::move(other._20));
        if(other.is_set_21()) set_21(std::move(other._21));
        if(other.is_set_22()) set_22(std::move(other._22));
        if(other.is_set_23()) set_23(std::move(other._23));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
        destroy_7();
        destroy_8();
        destroy_9();
        destroy_10();
        destroy_11();
        destroy_12();
        destroy_13();
        destroy_14();
        destroy_15();
        destroy_16();
        destroy_17();
        destroy_18();
        destroy_19();
        destroy_20();
        destroy_21();
        destroy_22();
        destroy_23();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
/* match_tuple of size 24 */
template<
    class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7,
        class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14,
        class Arg15, class Arg16, class Arg17, class Arg18, class Arg19, class Arg20, class Arg21,
        class Arg22, class Arg23, class Arg24
>
struct match_tuple<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12,
        Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19, Arg20, Arg21, Arg22, Arg23, Arg24> {

    union {
        Arg1 _1;
        impl_::void_ void_1;
    };
    template<class ...U>
    void set_1(U&& ...v) {
        new (&_1) Arg1(std::forward<U>(v)...);
        assigned |= (1 << 1);
    }
    bool is_set_1() const {
        return !!(assigned & (1 << 1));
    }
    void destroy_1() {
        if(is_set_1()) _1.~Arg1();
    }

    union {
        Arg2 _2;
        impl_::void_ void_2;
    };
    template<class ...U>
    void set_2(U&& ...v) {
        new (&_2) Arg2(std::forward<U>(v)...);
        assigned |= (1 << 2);
    }
    bool is_set_2() const {
        return !!(assigned & (1 << 2));
    }
    void destroy_2() {
        if(is_set_2()) _2.~Arg2();
    }

    union {
        Arg3 _3;
        impl_::void_ void_3;
    };
    template<class ...U>
    void set_3(U&& ...v) {
        new (&_3) Arg3(std::forward<U>(v)...);
        assigned |= (1 << 3);
    }
    bool is_set_3() const {
        return !!(assigned & (1 << 3));
    }
    void destroy_3() {
        if(is_set_3()) _3.~Arg3();
    }

    union {
        Arg4 _4;
        impl_::void_ void_4;
    };
    template<class ...U>
    void set_4(U&& ...v) {
        new (&_4) Arg4(std::forward<U>(v)...);
        assigned |= (1 << 4);
    }
    bool is_set_4() const {
        return !!(assigned & (1 << 4));
    }
    void destroy_4() {
        if(is_set_4()) _4.~Arg4();
    }

    union {
        Arg5 _5;
        impl_::void_ void_5;
    };
    template<class ...U>
    void set_5(U&& ...v) {
        new (&_5) Arg5(std::forward<U>(v)...);
        assigned |= (1 << 5);
    }
    bool is_set_5() const {
        return !!(assigned & (1 << 5));
    }
    void destroy_5() {
        if(is_set_5()) _5.~Arg5();
    }

    union {
        Arg6 _6;
        impl_::void_ void_6;
    };
    template<class ...U>
    void set_6(U&& ...v) {
        new (&_6) Arg6(std::forward<U>(v)...);
        assigned |= (1 << 6);
    }
    bool is_set_6() const {
        return !!(assigned & (1 << 6));
    }
    void destroy_6() {
        if(is_set_6()) _6.~Arg6();
    }

    union {
        Arg7 _7;
        impl_::void_ void_7;
    };
    template<class ...U>
    void set_7(U&& ...v) {
        new (&_7) Arg7(std::forward<U>(v)...);
        assigned |= (1 << 7);
    }
    bool is_set_7() const {
        return !!(assigned & (1 << 7));
    }
    void destroy_7() {
        if(is_set_7()) _7.~Arg7();
    }

    union {
        Arg8 _8;
        impl_::void_ void_8;
    };
    template<class ...U>
    void set_8(U&& ...v) {
        new (&_8) Arg8(std::forward<U>(v)...);
        assigned |= (1 << 8);
    }
    bool is_set_8() const {
        return !!(assigned & (1 << 8));
    }
    void destroy_8() {
        if(is_set_8()) _8.~Arg8();
    }

    union {
        Arg9 _9;
        impl_::void_ void_9;
    };
    template<class ...U>
    void set_9(U&& ...v) {
        new (&_9) Arg9(std::forward<U>(v)...);
        assigned |= (1 << 9);
    }
    bool is_set_9() const {
        return !!(assigned & (1 << 9));
    }
    void destroy_9() {
        if(is_set_9()) _9.~Arg9();
    }

    union {
        Arg10 _10;
        impl_::void_ void_10;
    };
    template<class ...U>
    void set_10(U&& ...v) {
        new (&_10) Arg10(std::forward<U>(v)...);
        assigned |= (1 << 10);
    }
    bool is_set_10() const {
        return !!(assigned & (1 << 10));
    }
    void destroy_10() {
        if(is_set_10()) _10.~Arg10();
    }

    union {
        Arg11 _11;
        impl_::void_ void_11;
    };
    template<class ...U>
    void set_11(U&& ...v) {
        new (&_11) Arg11(std::forward<U>(v)...);
        assigned |= (1 << 11);
    }
    bool is_set_11() const {
        return !!(assigned & (1 << 11));
    }
    void destroy_11() {
        if(is_set_11()) _11.~Arg11();
    }

    union {
        Arg12 _12;
        impl_::void_ void_12;
    };
    template<class ...U>
    void set_12(U&& ...v) {
        new (&_12) Arg12(std::forward<U>(v)...);
        assigned |= (1 << 12);
    }
    bool is_set_12() const {
        return !!(assigned & (1 << 12));
    }
    void destroy_12() {
        if(is_set_12()) _12.~Arg12();
    }

    union {
        Arg13 _13;
        impl_::void_ void_13;
    };
    template<class ...U>
    void set_13(U&& ...v) {
        new (&_13) Arg13(std::forward<U>(v)...);
        assigned |= (1 << 13);
    }
    bool is_set_13() const {
        return !!(assigned & (1 << 13));
    }
    void destroy_13() {
        if(is_set_13()) _13.~Arg13();
    }

    union {
        Arg14 _14;
        impl_::void_ void_14;
    };
    template<class ...U>
    void set_14(U&& ...v) {
        new (&_14) Arg14(std::forward<U>(v)...);
        assigned |= (1 << 14);
    }
    bool is_set_14() const {
        return !!(assigned & (1 << 14));
    }
    void destroy_14() {
        if(is_set_14()) _14.~Arg14();
    }

    union {
        Arg15 _15;
        impl_::void_ void_15;
    };
    template<class ...U>
    void set_15(U&& ...v) {
        new (&_15) Arg15(std::forward<U>(v)...);
        assigned |= (1 << 15);
    }
    bool is_set_15() const {
        return !!(assigned & (1 << 15));
    }
    void destroy_15() {
        if(is_set_15()) _15.~Arg15();
    }

    union {
        Arg16 _16;
        impl_::void_ void_16;
    };
    template<class ...U>
    void set_16(U&& ...v) {
        new (&_16) Arg16(std::forward<U>(v)...);
        assigned |= (1 << 16);
    }
    bool is_set_16() const {
        return !!(assigned & (1 << 16));
    }
    void destroy_16() {
        if(is_set_16()) _16.~Arg16();
    }

    union {
        Arg17 _17;
        impl_::void_ void_17;
    };
    template<class ...U>
    void set_17(U&& ...v) {
        new (&_17) Arg17(std::forward<U>(v)...);
        assigned |= (1 << 17);
    }
    bool is_set_17() const {
        return !!(assigned & (1 << 17));
    }
    void destroy_17() {
        if(is_set_17()) _17.~Arg17();
    }

    union {
        Arg18 _18;
        impl_::void_ void_18;
    };
    template<class ...U>
    void set_18(U&& ...v) {
        new (&_18) Arg18(std::forward<U>(v)...);
        assigned |= (1 << 18);
    }
    bool is_set_18() const {
        return !!(assigned & (1 << 18));
    }
    void destroy_18() {
        if(is_set_18()) _18.~Arg18();
    }

    union {
        Arg19 _19;
        impl_::void_ void_19;
    };
    template<class ...U>
    void set_19(U&& ...v) {
        new (&_19) Arg19(std::forward<U>(v)...);
        assigned |= (1 << 19);
    }
    bool is_set_19() const {
        return !!(assigned & (1 << 19));
    }
    void destroy_19() {
        if(is_set_19()) _19.~Arg19();
    }

    union {
        Arg20 _20;
        impl_::void_ void_20;
    };
    template<class ...U>
    void set_20(U&& ...v) {
        new (&_20) Arg20(std::forward<U>(v)...);
        assigned |= (1 << 20);
    }
    bool is_set_20() const {
        return !!(assigned & (1 << 20));
    }
    void destroy_20() {
        if(is_set_20()) _20.~Arg20();
    }

    union {
        Arg21 _21;
        impl_::void_ void_21;
    };
    template<class ...U>
    void set_21(U&& ...v) {
        new (&_21) Arg21(std::forward<U>(v)...);
        assigned |= (1 << 21);
    }
    bool is_set_21() const {
        return !!(assigned & (1 << 21));
    }
    void destroy_21() {
        if(is_set_21()) _21.~Arg21();
    }

    union {
        Arg22 _22;
        impl_::void_ void_22;
    };
    template<class ...U>
    void set_22(U&& ...v) {
        new (&_22) Arg22(std::forward<U>(v)...);
        assigned |= (1 << 22);
    }
    bool is_set_22() const {
        return !!(assigned & (1 << 22));
    }
    void destroy_22() {
        if(is_set_22()) _22.~Arg22();
    }

    union {
        Arg23 _23;
        impl_::void_ void_23;
    };
    template<class ...U>
    void set_23(U&& ...v) {
        new (&_23) Arg23(std::forward<U>(v)...);
        assigned |= (1 << 23);
    }
    bool is_set_23() const {
        return !!(assigned & (1 << 23));
    }
    void destroy_23() {
        if(is_set_23()) _23.~Arg23();
    }

    union {
        Arg24 _24;
        impl_::void_ void_24;
    };
    template<class ...U>
    void set_24(U&& ...v) {
        new (&_24) Arg24(std::forward<U>(v)...);
        assigned |= (1 << 24);
    }
    bool is_set_24() const {
        return !!(assigned & (1 << 24));
    }
    void destroy_24() {
        if(is_set_24()) _24.~Arg24();
    }


    match_tuple() : void_1{}, void_2{}, void_3{}, void_4{}, void_5{}, void_6{}, void_7{}, void_8{},
        void_9{}, void_10{}, void_11{}, void_12{}, void_13{}, void_14{}, void_15{}, void_16{},
        void_17{}, void_18{}, void_19{}, void_20{}, void_21{}, void_22{}, void_23{}, void_24{} {}

    match_tuple(const match_tuple& other) {
        if(other.is_set_1()) set_1(other._1);
        if(other.is_set_2()) set_2(other._2);
        if(other.is_set_3()) set_3(other._3);
        if(other.is_set_4()) set_4(other._4);
        if(other.is_set_5()) set_5(other._5);
        if(other.is_set_6()) set_6(other._6);
        if(other.is_set_7()) set_7(other._7);
        if(other.is_set_8()) set_8(other._8);
        if(other.is_set_9()) set_9(other._9);
        if(other.is_set_10()) set_10(other._10);
        if(other.is_set_11()) set_11(other._11);
        if(other.is_set_12()) set_12(other._12);
        if(other.is_set_13()) set_13(other._13);
        if(other.is_set_14()) set_14(other._14);
        if(other.is_set_15()) set_15(other._15);
        if(other.is_set_16()) set_16(other._16);
        if(other.is_set_17()) set_17(other._17);
        if(other.is_set_18()) set_18(other._18);
        if(other.is_set_19()) set_19(other._19);
        if(other.is_set_20()) set_20(other._20);
        if(other.is_set_21()) set_21(other._21);
        if(other.is_set_22()) set_22(other._22);
        if(other.is_set_23()) set_23(other._23);
        if(other.is_set_24()) set_24(other._24);
    } 

    template<
       class U1, class U2, class U3, class U4, class U5, class U6, class U7,
        class U8, class U9, class U10, class U11, class U12, class U13, class U14,
        class U15, class U16, class U17, class U18, class U19, class U20, class U21,
        class U22, class U23, class U24
    > 
    match_tuple(U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8,
        U9&& u9, U10&& u10, U11&& u11, U12&& u12, U13&& u13, U14&& u14, U15&& u15, U16&& u16,
        U17&& u17, U18&& u18, U19&& u19, U20&& u20, U21&& u21, U22&& u22, U23&& u23, U24&& u24) {
        set_1(std::forward<U1>(u1));
        set_2(std::forward<U2>(u2));
        set_3(std::forward<U3>(u3));
        set_4(std::forward<U4>(u4));
        set_5(std::forward<U5>(u5));
        set_6(std::forward<U6>(u6));
        set_7(std::forward<U7>(u7));
        set_8(std::forward<U8>(u8));
        set_9(std::forward<U9>(u9));
        set_10(std::forward<U10>(u10));
        set_11(std::forward<U11>(u11));
        set_12(std::forward<U12>(u12));
        set_13(std::forward<U13>(u13));
        set_14(std::forward<U14>(u14));
        set_15(std::forward<U15>(u15));
        set_16(std::forward<U16>(u16));
        set_17(std::forward<U17>(u17));
        set_18(std::forward<U18>(u18));
        set_19(std::forward<U19>(u19));
        set_20(std::forward<U20>(u20));
        set_21(std::forward<U21>(u21));
        set_22(std::forward<U22>(u22));
        set_23(std::forward<U23>(u23));
        set_24(std::forward<U24>(u24));
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
        if(other.is_set_9()) set_9(std::move(other._9));
        if(other.is_set_10()) set_10(std::move(other._10));
        if(other.is_set_11()) set_11(std::move(other._11));
        if(other.is_set_12()) set_12(std::move(other._12));
        if(other.is_set_13()) set_13(std::move(other._13));
        if(other.is_set_14()) set_14(std::move(other._14));
        if(other.is_set_15()) set_15(std::move(other._15));
        if(other.is_set_16()) set_16(std::move(other._16));
        if(other.is_set_17()) set_17(std::move(other._17));
        if(other.is_set_18()) set_18(std::move(other._18));
        if(other.is_set_19()) set_19(std::move(other._19));
        if(other.is_set_20()) set_20(std::move(other._20));
        if(other.is_set_21()) set_21(std::move(other._21));
        if(other.is_set_22()) set_22(std::move(other._22));
        if(other.is_set_23()) set_23(std::move(other._23));
        if(other.is_set_24()) set_24(std::move(other._24));
    } 

    ~match_tuple() {
        destroy_1();
        destroy_2();
        destroy_3();
        destroy_4();
        destroy_5();
        destroy_6();
        destroy_7();
        destroy_8();
        destroy_9();
        destroy_10();
        destroy_11();
        destroy_12();
        destroy_13();
        destroy_14();
        destroy_15();
        destroy_16();
        destroy_17();
        destroy_18();
        destroy_19();
        destroy_20();
        destroy_21();
        destroy_22();
        destroy_23();
        destroy_24();
    } 

private: 
    uint_least32_t assigned = 0; 
};

/*************************************************************************************************/
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
    template<class ...U>
    match_result(U&& ...u) {
        construct(std::forward<U>(u)...);
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

namespace impl_ {
/*************************************************************************************************/

template<std::size_t N, class Res> struct getter;

template<class ...T>
struct getter<0, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_1) {
        return res->_1;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_1) {
        return res->_1;
    }
};
template<class ...T>
struct getter<1, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_2) {
        return res->_2;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_2) {
        return res->_2;
    }
};
template<class ...T>
struct getter<2, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_3) {
        return res->_3;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_3) {
        return res->_3;
    }
};
template<class ...T>
struct getter<3, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_4) {
        return res->_4;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_4) {
        return res->_4;
    }
};
template<class ...T>
struct getter<4, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_5) {
        return res->_5;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_5) {
        return res->_5;
    }
};
template<class ...T>
struct getter<5, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_6) {
        return res->_6;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_6) {
        return res->_6;
    }
};
template<class ...T>
struct getter<6, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_7) {
        return res->_7;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_7) {
        return res->_7;
    }
};
template<class ...T>
struct getter<7, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_8) {
        return res->_8;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_8) {
        return res->_8;
    }
};
template<class ...T>
struct getter<8, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_9) {
        return res->_9;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_9) {
        return res->_9;
    }
};
template<class ...T>
struct getter<9, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_10) {
        return res->_10;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_10) {
        return res->_10;
    }
};
template<class ...T>
struct getter<10, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_11) {
        return res->_11;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_11) {
        return res->_11;
    }
};
template<class ...T>
struct getter<11, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_12) {
        return res->_12;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_12) {
        return res->_12;
    }
};
template<class ...T>
struct getter<12, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_13) {
        return res->_13;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_13) {
        return res->_13;
    }
};
template<class ...T>
struct getter<13, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_14) {
        return res->_14;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_14) {
        return res->_14;
    }
};
template<class ...T>
struct getter<14, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_15) {
        return res->_15;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_15) {
        return res->_15;
    }
};
template<class ...T>
struct getter<15, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_16) {
        return res->_16;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_16) {
        return res->_16;
    }
};
template<class ...T>
struct getter<16, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_17) {
        return res->_17;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_17) {
        return res->_17;
    }
};
template<class ...T>
struct getter<17, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_18) {
        return res->_18;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_18) {
        return res->_18;
    }
};
template<class ...T>
struct getter<18, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_19) {
        return res->_19;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_19) {
        return res->_19;
    }
};
template<class ...T>
struct getter<19, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_20) {
        return res->_20;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_20) {
        return res->_20;
    }
};
template<class ...T>
struct getter<20, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_21) {
        return res->_21;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_21) {
        return res->_21;
    }
};
template<class ...T>
struct getter<21, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_22) {
        return res->_22;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_22) {
        return res->_22;
    }
};
template<class ...T>
struct getter<22, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_23) {
        return res->_23;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_23) {
        return res->_23;
    }
};
template<class ...T>
struct getter<23, match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->_24) {
        return res->_24;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->_24) {
        return res->_24;
    }
};

/*************************************************************************************************/

template<std::size_t N, class Res> struct setter;

template<class ...T>
struct setter<0, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_1(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<1, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_2(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<2, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_3(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<3, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_4(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<4, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_5(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<5, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_6(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<6, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_7(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<7, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_8(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<8, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_9(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<9, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_10(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<10, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_11(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<11, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_12(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<12, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_13(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<13, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_14(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<14, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_15(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<15, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_16(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<16, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_17(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<17, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_18(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<18, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_19(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<19, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_20(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<20, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_21(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<21, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_22(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<22, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_23(std::forward<U>(val));
    }
};
template<class ...T>
struct setter<23, match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->set_24(std::forward<U>(val));
    }
};

/*************************************************************************************************/

template<std::size_t N, class Res> struct checker;

template<class ...T>
struct checker<0, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_1();
    }
};
template<class ...T>
struct checker<1, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_2();
    }
};
template<class ...T>
struct checker<2, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_3();
    }
};
template<class ...T>
struct checker<3, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_4();
    }
};
template<class ...T>
struct checker<4, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_5();
    }
};
template<class ...T>
struct checker<5, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_6();
    }
};
template<class ...T>
struct checker<6, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_7();
    }
};
template<class ...T>
struct checker<7, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_8();
    }
};
template<class ...T>
struct checker<8, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_9();
    }
};
template<class ...T>
struct checker<9, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_10();
    }
};
template<class ...T>
struct checker<10, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_11();
    }
};
template<class ...T>
struct checker<11, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_12();
    }
};
template<class ...T>
struct checker<12, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_13();
    }
};
template<class ...T>
struct checker<13, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_14();
    }
};
template<class ...T>
struct checker<14, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_15();
    }
};
template<class ...T>
struct checker<15, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_16();
    }
};
template<class ...T>
struct checker<16, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_17();
    }
};
template<class ...T>
struct checker<17, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_18();
    }
};
template<class ...T>
struct checker<18, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_19();
    }
};
template<class ...T>
struct checker<19, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_20();
    }
};
template<class ...T>
struct checker<20, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_21();
    }
};
template<class ...T>
struct checker<21, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_22();
    }
};
template<class ...T>
struct checker<22, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_23();
    }
};
template<class ...T>
struct checker<23, match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->is_set_24();
    }
};

} /* namespace impl_ */
} /* namespace matchers */
} /* namespace functional_hell */
#endif /* MATCH_TUPLE_HPP_ */
