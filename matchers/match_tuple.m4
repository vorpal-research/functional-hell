changequote(`~_{',`}_~')dnl 
dnl // We really change those quotes only to support 
dnl // syntax highlighting in editors, sorry for that :( */
changequote(~_{``}_~,~_{''}_~)dnl /* dunno lol */
changecom(///)dnl
dnl // first things first - define a classic FOR macro
dnl
define(
``FOR'',
``ifelse($#,0,````$0'''',``ifelse(eval($2<=$3),1,``pushdef(``$1'',$2)$4``''popdef(``$1'')$0(``$1'',incr($2),$3,``$4'')'')''dnl
)''dnl
)dnl
dnl // be really fancy about the output, wrap lines overflowing 100-char gap
define(
``AUTOWRAP'',
``ifelse(eval(eval($1 - 1) % $2 == 0),1,``
        '',`` '')''dnl 
)dnl
ifdef(``MAX_TUPLE_SIZE'',,
``define(``MAX_TUPLE_SIZE'',16)''dnl
)dnl
dnl
dnl /* and now here goes the file */
/*
    This file is generated from match_tuple.m4
    To regenerate it, run 
    $ m4 match_tuple.m4 >match_tuple.hpp
    You can manually supply the maximum size of tuple (defaults to 16) using
    $ m4 -DMAX_TUPLE_SIZE=62
    where 62 is the new max size
    Be careful though, as this file turns out to be ~11K lines of code for max size of 32

    Current max tuple size is MAX_TUPLE_SIZE
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
FOR(``LIMIT'',1,MAX_TUPLE_SIZE,``
/*************************************************************************************************/
/* match_tuple of size LIMIT */
template<
    class ``Arg1''FOR(``I'',2,LIMIT,``,AUTOWRAP(I,7)class ``Arg''I'')
>
struct match_tuple<``Arg1''FOR(``I'',2,LIMIT,``,AUTOWRAP(I,12)``Arg''I'')> {
FOR(``N'',1,LIMIT,``
    union {
        ``Arg''N ``_''N;
        impl_::void_ ``void_''N;
    };
    template<class ...U>
    void ``set_''N``(U&& ...v)'' {
        new (&``_''N) ``Arg''N``(std::forward<U>(v)...)'';
        assigned |= (1 << N);
    }
    bool ``is_set_''N``()'' const {
        return !!(assigned & (1 << N));
    }
    void ``destroy_''N``()'' {
        if(``is_set_''N``()'') ``_''N.~``Arg''N``()'';
    }
'')

    match_tuple() : void_1{}FOR(``I'',2,LIMIT,``,AUTOWRAP(I,8)``void_''I{}'') {}

    template<
        class ``UArg1''FOR(``I'',2,LIMIT,``,AUTOWRAP(I,7)class ``UArg''I'')
    >
    match_tuple(const match_tuple<``UArg1''FOR(``I'',2,LIMIT,``,AUTOWRAP(I,12)``UArg''I'')>& other) {dnl
FOR(``N'',1,LIMIT,``
        if(other.``is_set_''N``()'') ``set_''N``(other._''N``)'';dnl
'')
    } 

    template<
``       class U1''FOR(``I'',2,LIMIT,``,AUTOWRAP(I,7)class ``U''I'')
    > 
    match_tuple(``U1&& u1''FOR(``I'',2,LIMIT,``,AUTOWRAP(I,8)``U''I&& ``u''I'')) {dnl
FOR(``N'',1,LIMIT,``
        ``set_''N``(''std::forward<``U''N>(``u''N));dnl
'')
    } 

    template<
        class ``UArg1''FOR(``I'',2,LIMIT,``,AUTOWRAP(I,7)class ``UArg''I'')
    >
    match_tuple(match_tuple<``UArg1''FOR(``I'',2,LIMIT,``,AUTOWRAP(I,12)``UArg''I'')>&& other) {dnl
FOR(``N'',1,LIMIT,``
        if(other.``is_set_''N``()'') ``set_''N``(''std::move(other.``_''N));dnl
'')
    } 

    ~match_tuple() {dnl
FOR(``N'',1,LIMIT,``
        ``destroy_''N``()'';dnl
'')
    } 

private: 
    uint_least32_t assigned = 0; 
};
'')dnl

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

    match_tuple<Args...>& operator()(){
        return data;
    }

    const match_tuple<Args...>& operator()() const{
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

dnl /* and some accessor guys */
namespace impl_ {
/*************************************************************************************************/

template<std::size_t N, class Res> struct getter;

FOR(``N'',1,MAX_TUPLE_SIZE,``dnl
template<class ...T>
struct getter<eval(N-1), match_result<T...>> {
    static auto apply(match_result<T...>& res) -> decltype(res->``_''N) {
        return res->``_''N;
    }
    static auto apply(const match_result<T...>& res) -> decltype(res->``_''N) {
        return res->``_''N;
    }
};
'')dnl

/*************************************************************************************************/

template<std::size_t N, class Res> struct setter;

FOR(``N'',1,MAX_TUPLE_SIZE,``dnl
template<class ...T>
struct setter<eval(N-1), match_result<T...>> {
    template<class U>
    static void apply(match_result<T...>& res, U&& val) {
        res->``set_''N``(''std::forward<U>(val));
    }
};
'')dnl

/*************************************************************************************************/

template<std::size_t N, class Res> struct checker;

FOR(``N'',1,MAX_TUPLE_SIZE,``dnl
template<class ...T>
struct checker<eval(N-1), match_result<T...>> {
    static bool apply(const match_result<T...>& res) {
        return res->``is_set_''N``()'';
    }
};
'')dnl

} /* namespace impl_ */
} /* namespace matchers */
} /* namespace functional_hell */
#endif /* MATCH_TUPLE_HPP_ */
