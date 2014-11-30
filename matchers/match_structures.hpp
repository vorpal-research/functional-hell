/*
 * match_structures.hpp
 * author: Mikhail Beliaev
 * NB: keep this file preprocessed if you find the compilation slowing down!
 * It takes ~ 1 second to preprocess all this include magics
 */

#ifndef MATCH_STRUCTURES_HPP_
#define MATCH_STRUCTURES_HPP_

#include "match_tuple.hpp"

namespace functional_hell {
namespace matchers {
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

    friend bool operator == (match_reference lhv, match_reference rhv) {
        return lhv.get() == rhv.get();
    }

    template<class U>
    friend bool operator == (match_reference lhv, const U& rhv) {
        return lhv.get() == rhv;
    }

    template<class U>
    friend bool operator == (const U& lhv, match_reference rhv) {
        return lhv == rhv.get();
    }

};

/*************************************************************************************************/

template<class It>
class match_sequence {
    It begin_;
    It end_;

public:
    using reference = typename std::iterator_traits<It>::reference;
    using const_reference = typename std::add_const<reference>::type;
    using pointer = typename std::iterator_traits<It>::pointer;
    using value_type = typename std::iterator_traits<It>::value_type;
    using iterator = It;
    using const_iterator = It;
    using difference_type = typename std::iterator_traits<It>::difference_type;
    using size_type = size_t;

    match_sequence(It begin, It end): begin_(begin), end_(end) {};

    It begin() const { return begin_; }
    It end() const { return end_; }

    friend bool operator == (const match_sequence& lhv, const match_sequence& rhv) {
        return lhv.begin_ == rhv.begin_ && lhv.end_ == rhv.end_;
    }
};

template<class It>
match_sequence<It> match_view(It begin, It end) {
    return {begin, end};
}

template<class Con>
auto match_container(const Con& con) -> match_sequence<decltype(std::begin(con))> {
    return { std::begin(con), std::end(con) };
}

template<class Con>
auto match_container(Con& con) -> match_sequence<decltype(std::begin(con))> {
    return { std::begin(con), std::end(con) };
}

template<class Con>
void match_container(Con&& con) = delete;

/*************************************************************************************************/

namespace impl_ {

template<class T> struct wrapped { using type = T; };
template<class T> struct wrapped<T&> { using type = match_reference<T>; };
template<class T> using wrapped_t = typename wrapped<T>::type;

} /* namespace impl_ */

/*************************************************************************************************/

} /* namespace matchers */
} /* namespace functional_hell */

#endif /* MATCH_TUPLE_HPP_ */
