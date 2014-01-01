/*
 * lambdas.hpp
 * author: Mikhail Beliaev
 *
 * Disclaimer: yes, this is basically a poor redo of Boost::Lambda, exactly
 *             yes, I do need this here
 */

#ifndef LAMBDAS_HPP_
#define LAMBDAS_HPP_

#include <utility>
#include <type_traits>

namespace functional_hell {
namespace lambdas {

struct lambda {};

template<size_t N>
struct Nth {
    template<class Head, class ...Args>
    static inline auto apply(Head&& head, Args&&... args)
            -> decltype(Nth<N-1>::apply(std::forward<Args>(args)...)) {
        static_assert(N < (sizeof...(Args)+1), "Nth<> index overflow");
        return Nth<N-1>::apply(std::forward<Args>(args)...);
    }
};

template<>
struct Nth<0U> {
    template<class Head, class ...Args>
    static inline auto apply(Head&& head, Args&&...)
            -> decltype(std::forward<Head>(head)) {
        return std::forward<Head>(head);
    }
};

template<class T>
class capture_by_ref: public lambda {
    T& ref;
public:
    capture_by_ref(T& ref): ref(ref){};

    template<class ...Args>
    inline auto operator()(Args&&... args) const -> T& {
        return ref;
    }
};

template<class T>
capture_by_ref<T> by_ref(T& ref) {
    return capture_by_ref<T>{ ref };
}

template<class T>
capture_by_ref<const T> by_ref(const T& ref) {
    return capture_by_ref<const T>{ ref };
}

template<class T>
class capture_by_val: public lambda {
    T val;
public:
    capture_by_val(capture_by_val&&) = default;
    capture_by_val(const capture_by_val&) = default;
    capture_by_val(T&& val): val(val){};
    capture_by_val(T& val): val(val){};
    capture_by_val(const T& val): val(val){};

    template<class ...Args>
    inline auto operator()(Args&&... args) const -> const T& {
        return val;
    }
};

template<class T>
capture_by_val<typename std::remove_reference<T>::type> by_val(T&& ref) {
    return capture_by_val<typename std::remove_reference<T>::type>{ std::forward<T>(ref) };
}

template<size_t N>
class placeholder: public lambda {
public:
    template<class ...Args>
    inline auto operator()(Args&&... args) const
            -> decltype(Nth<N>::apply(std::forward<Args>(args)...)) {
        static_assert(sizeof...(Args) > N, "placeholder: not enough arguments");
        return Nth<N>::apply(std::forward<Args>(args)...);
    }
};

// yes, I mean these guys to be static
// they have no memory anywayz
static placeholder<0> _0;
static placeholder<1> _1;
static placeholder<2> _2;
static placeholder<3> _3;
static placeholder<4> _4;
static placeholder<5> _5;
static placeholder<6> _6;
static placeholder<7> _7;

#define PROCESS_SPECIAL_BINARY(NAME, OP)
#define PROCESS_BINARY(NAME, OP) \
template<class Lhv, class Rhv> \
class lambda_ ## NAME: public lambda { \
    Lhv lhv; \
    Rhv rhv; \
 \
public: \
    lambda_ ## NAME(const Lhv& lhv, const Rhv& rhv) : lhv(lhv), rhv(rhv) {} \
    lambda_ ## NAME(Lhv&& lhv, Rhv&& rhv) : lhv(lhv), rhv(rhv) {} \
    lambda_ ## NAME(const lambda_ ## NAME&) = default; \
    lambda_ ## NAME(lambda_ ## NAME&&) = default; \
 \
    template<class ...Args> \
    inline auto operator()(Args&&... args) const -> \
        decltype(std::declval<Lhv>()(std::forward<Args>(args)...) OP std::declval<Rhv>()(std::forward<Args>(args)...)) { \
        return lhv(std::forward<Args>(args)...) OP rhv(std::forward<Args>(args)...); \
    } \
}; \
 \
template<class Lhv, class Rhv, class SFINAE = typename std::enable_if< \
        std::is_base_of<lambda, typename std::remove_reference<Lhv>::type>::value && \
        std::is_base_of<lambda, typename std::remove_reference<Rhv>::type>::value \
    >::type \
> lambda_ ## NAME<typename std::remove_reference<Lhv>::type, typename std::remove_reference<Rhv>::type> operator OP(Lhv&& lhv, Rhv&& rhv) { \
    return lambda_ ## NAME<typename std::remove_reference<Lhv>::type, typename std::remove_reference<Rhv>::type> { \
        std::forward<Lhv>(lhv), std::forward<Rhv>(rhv) \
    }; \
} \
\
template<class Lhv, class Rhv, class SFINAE = typename std::enable_if< \
        std::is_base_of<lambda, typename std::remove_reference<Lhv>::type>::value && \
        !std::is_base_of<lambda, typename std::remove_reference<Rhv>::type>::value \
    >::type \
> auto operator OP(Lhv&& lhv, Rhv&& rhv) -> \
    lambda_ ## NAME<typename std::remove_reference<Lhv>::type, decltype(by_val(std::forward<Rhv>(rhv)))>{ \
    return lambda_ ## NAME<typename std::remove_reference<Lhv>::type, decltype(by_val(std::forward<Rhv>(rhv)))> { \
        std::forward<Lhv>(lhv), by_val(std::forward<Rhv>(rhv)) \
    }; \
} \
\
template<class Lhv, class Rhv, class SFINAE = typename std::enable_if< \
        !std::is_base_of<lambda, typename std::remove_reference<Lhv>::type>::value && \
        std::is_base_of<lambda, typename std::remove_reference<Rhv>::type>::value \
    >::type \
> auto operator OP(Lhv&& lhv, Rhv&& rhv) -> \
    lambda_ ## NAME<decltype(by_val(std::forward<Lhv>(lhv))), typename std::remove_reference<Rhv>::type>{ \
    return lambda_ ## NAME<decltype(by_val(std::forward<Lhv>(lhv))), typename std::remove_reference<Rhv>::type> { \
        by_val(std::forward<Lhv>(lhv)), std::forward<Rhv>(rhv) \
    }; \
} \
\

#include "operators.def"

}
}

#endif /* LAMBDAS_HPP_ */
