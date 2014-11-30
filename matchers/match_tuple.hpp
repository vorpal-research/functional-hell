/*
    This file is generated from match_tuple.m4
    To regenerate it, run 
    $ m4 match_tuple.m4 >match_tuple.hpp
    You can manually supply the maximum size of tuple (defaults to 16) using
    $ m4 -DMAX_TUPLE_SIZE=62
    where 62 is the new max size
    Be careful though, as this file turns out to be ~11K lines of code for max size of 32

    Current max tuple size is 16
*/
#ifndef MATCH_TUPLE_HPP_
#define MATCH_TUPLE_HPP_
#include <utility>
#include "meta.hpp"

namespace functional_hell {
namespace matchers {
/*************************************************************************************************/
namespace impl_ {

typedef none void_;

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

    template<
        class UArg1
    >
    match_tuple(const match_tuple<UArg1>& other) {
        if(other.is_set_1()) set_1(other._1);
    } 

    template<
       class U1
    > 
    match_tuple(U1&& u1) {
        set_1(std::forward<U1>(u1));
    } 

    template<
        class UArg1
    >
    match_tuple(match_tuple<UArg1>&& other) {
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

    template<
        class UArg1, class UArg2
    >
    match_tuple(const match_tuple<UArg1, UArg2>& other) {
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

    template<
        class UArg1, class UArg2
    >
    match_tuple(match_tuple<UArg1, UArg2>&& other) {
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

    template<
        class UArg1, class UArg2, class UArg3
    >
    match_tuple(const match_tuple<UArg1, UArg2, UArg3>& other) {
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

    template<
        class UArg1, class UArg2, class UArg3
    >
    match_tuple(match_tuple<UArg1, UArg2, UArg3>&& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4
    >
    match_tuple(const match_tuple<UArg1, UArg2, UArg3, UArg4>& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4
    >
    match_tuple(match_tuple<UArg1, UArg2, UArg3, UArg4>&& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5
    >
    match_tuple(const match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5>& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5
    >
    match_tuple(match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5>&& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6
    >
    match_tuple(const match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6>& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6
    >
    match_tuple(match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6>&& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6, class UArg7
    >
    match_tuple(const match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6, UArg7>& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6, class UArg7
    >
    match_tuple(match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6, UArg7>&& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6, class UArg7,
        class UArg8
    >
    match_tuple(const match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6, UArg7, UArg8>& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6, class UArg7,
        class UArg8
    >
    match_tuple(match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6, UArg7, UArg8>&& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6, class UArg7,
        class UArg8, class UArg9
    >
    match_tuple(const match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6, UArg7, UArg8, UArg9>& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6, class UArg7,
        class UArg8, class UArg9
    >
    match_tuple(match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6, UArg7, UArg8, UArg9>&& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6, class UArg7,
        class UArg8, class UArg9, class UArg10
    >
    match_tuple(const match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6, UArg7, UArg8, UArg9, UArg10>& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6, class UArg7,
        class UArg8, class UArg9, class UArg10
    >
    match_tuple(match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6, UArg7, UArg8, UArg9, UArg10>&& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6, class UArg7,
        class UArg8, class UArg9, class UArg10, class UArg11
    >
    match_tuple(const match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6, UArg7, UArg8, UArg9, UArg10, UArg11>& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6, class UArg7,
        class UArg8, class UArg9, class UArg10, class UArg11
    >
    match_tuple(match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6, UArg7, UArg8, UArg9, UArg10, UArg11>&& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6, class UArg7,
        class UArg8, class UArg9, class UArg10, class UArg11, class UArg12
    >
    match_tuple(const match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6, UArg7, UArg8, UArg9, UArg10, UArg11, UArg12>& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6, class UArg7,
        class UArg8, class UArg9, class UArg10, class UArg11, class UArg12
    >
    match_tuple(match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6, UArg7, UArg8, UArg9, UArg10, UArg11, UArg12>&& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6, class UArg7,
        class UArg8, class UArg9, class UArg10, class UArg11, class UArg12, class UArg13
    >
    match_tuple(const match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6, UArg7, UArg8, UArg9, UArg10, UArg11, UArg12,
        UArg13>& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6, class UArg7,
        class UArg8, class UArg9, class UArg10, class UArg11, class UArg12, class UArg13
    >
    match_tuple(match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6, UArg7, UArg8, UArg9, UArg10, UArg11, UArg12,
        UArg13>&& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6, class UArg7,
        class UArg8, class UArg9, class UArg10, class UArg11, class UArg12, class UArg13, class UArg14
    >
    match_tuple(const match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6, UArg7, UArg8, UArg9, UArg10, UArg11, UArg12,
        UArg13, UArg14>& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6, class UArg7,
        class UArg8, class UArg9, class UArg10, class UArg11, class UArg12, class UArg13, class UArg14
    >
    match_tuple(match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6, UArg7, UArg8, UArg9, UArg10, UArg11, UArg12,
        UArg13, UArg14>&& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6, class UArg7,
        class UArg8, class UArg9, class UArg10, class UArg11, class UArg12, class UArg13, class UArg14,
        class UArg15
    >
    match_tuple(const match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6, UArg7, UArg8, UArg9, UArg10, UArg11, UArg12,
        UArg13, UArg14, UArg15>& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6, class UArg7,
        class UArg8, class UArg9, class UArg10, class UArg11, class UArg12, class UArg13, class UArg14,
        class UArg15
    >
    match_tuple(match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6, UArg7, UArg8, UArg9, UArg10, UArg11, UArg12,
        UArg13, UArg14, UArg15>&& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6, class UArg7,
        class UArg8, class UArg9, class UArg10, class UArg11, class UArg12, class UArg13, class UArg14,
        class UArg15, class UArg16
    >
    match_tuple(const match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6, UArg7, UArg8, UArg9, UArg10, UArg11, UArg12,
        UArg13, UArg14, UArg15, UArg16>& other) {
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

    template<
        class UArg1, class UArg2, class UArg3, class UArg4, class UArg5, class UArg6, class UArg7,
        class UArg8, class UArg9, class UArg10, class UArg11, class UArg12, class UArg13, class UArg14,
        class UArg15, class UArg16
    >
    match_tuple(match_tuple<UArg1, UArg2, UArg3, UArg4, UArg5, UArg6, UArg7, UArg8, UArg9, UArg10, UArg11, UArg12,
        UArg13, UArg14, UArg15, UArg16>&& other) {
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
        if(!success) return nullptr;
        return &data;
    }

    const match_tuple<Args...>* operator->() const {
        if(!success) return nullptr;
        return &data;
    }

    match_tuple<Args...>& operator()(){
        if(!success) throw 0;// FIXME
        return data;
    }

    const match_tuple<Args...>& operator()() const{
        if(!success) throw 0;// FIXME
        return data;
    }

    explicit operator bool() {
        return success;
    }

    match_result(): null{}, success{false} {};

    template<class ...UArgs>
    match_result(const match_result<UArgs...>& other): 
        null{}, success((bool)other) {
        if(success) {
            construct(other());
        }
    }
    template<class ...UArgs>
    match_result(match_result<UArgs...>&& other): 
        null{}, success((bool)other) {
        if(success) {
            construct(std::move(other()));
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

} /* namespace impl_ */
} /* namespace matchers */
} /* namespace functional_hell */
#endif /* MATCH_TUPLE_HPP_ */
