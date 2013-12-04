/*
 * match_tuple.hpp
 * NB: keep this file preprocessed if you find the compilation slowing down!
 * It takes ~ 1 second to preprocess all this include magics 
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
template<class ...Args> struct match_tuple;
template<> struct match_tuple<>{};
#define START 2
#define END 1
#include "match_tuple.def"
#undef END
#define END 2
#include "match_tuple.def"
#undef END
#define END 3
#include "match_tuple.def"
#undef END
#define END 4
#include "match_tuple.def"
#undef END
#define END 5
#include "match_tuple.def"
#undef END
#define END 6
#include "match_tuple.def"
#undef END
#define END 7
#include "match_tuple.def"
#undef END
#define END 8
#include "match_tuple.def"
#undef END
#define END 9
#include "match_tuple.def"
#undef END
#define END 10
#include "match_tuple.def"
#undef END
#define END 11
#include "match_tuple.def"
#undef END
#define END 12
#include "match_tuple.def"
#undef END
#define END 13
#include "match_tuple.def"
#undef END
#define END 14
#include "match_tuple.def"
#undef END
#define END 15
#include "match_tuple.def"
#undef END
#define END 16
#include "match_tuple.def"

#undef START

// undef for END is at the end of the file

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

// END is still the max size of the tuple
#define START 1

#define PROCESS(N) \
template<class ...T> \
struct getter<(N-1), match_result<T...>> { \
    static auto apply(match_result<T...>& res) -> decltype(res->_ ## N) { \
        return res->_ ## N; \
    }\
    static auto apply(const match_result<T...>& res) -> decltype(res->_ ## N) { \
        return res->_ ## N; \
    } \
};\

#include "repeat.def"

/*************************************************************************************************/

template<std::size_t N, class Res> struct setter;

#define PROCESS(N) \
template<class ...T> \
struct setter<(N-1), match_result<T...>> { \
    template<class U> \
    static void apply(match_result<T...>& res, U&& val) { \
        res->set_ ## N(std::forward<U>(val)); \
    }\
};\

#include "repeat.def"

/*************************************************************************************************/

template<std::size_t N, class Res>
struct checker;

#define PROCESS(N) \
template<class ...T> \
struct checker<(N-1), match_result<T...>> { \
    static bool apply(const match_result<T...>& res) { \
        return res->is_set_ ## N(); \
    }\
};\

#include "repeat.def"

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

#undef START
#undef END

} /* namespace matchers */
} /* namespace functional_hell */

#endif /* MATCH_TUPLE_HPP_ */
