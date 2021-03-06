/*
 * named_operators.hpp
 * author: Mikhail Beliaev
 *
 * all the credit for the idea goes to Konrad Rudolph
 * and this project: https://github.com/klmr/named-operator
 */

#ifndef NAMED_OPERATORS_HPP_
#define NAMED_OPERATORS_HPP_

#include <functional>

// you can redefine these to make your own kind of named operators
// keep in mind that this changes the operator precedence!
// we use * by default because it has the most precedence among binary ops
// (so it is, at least, predictable)
#ifndef OPERATOR_OPENING
#define OPERATOR_OPENING *
#endif
#ifndef OPERATOR_CLOSING
#define OPERATOR_CLOSING *
#endif

#define MACRO_PASTE0(LHV, RHV) LHV ## RHV
#define MACRO_PASTE(LHV, RHV) MACRO_PASTE0(LHV, RHV)
#define OPERATOR_ASSIGN MACRO_PASTE(OPERATOR_CLOSING, =)

/*************************************************************************************************/

namespace functional_hell {
namespace named_operators {

/*************************************************************************************************/

// named operator is basically a wrapper for anything callable, e.g. a lambda
template<class Lambda>
struct named_operator {
    Lambda lam;

    template<class Lhv, class Rhv>
    constexpr auto operator()(Lhv&& lhv, Rhv&& rhv) const ->
            decltype(lam(std::forward<Lhv>(lhv), std::forward<Rhv>(rhv))) {
        return lam(std::forward<Lhv>(lhv), std::forward<Rhv>(rhv));
    }
};
// this is a temporary storage we use to keep our syntax flow, it stores the lhv inside itself
// XXX: move this to impl_ ?
template<class Lhv, class Lambda>
struct named_operator_stage_2 {
    Lhv&& lhv;
    Lambda lam;
};

// the rest is pretty obvious (apart from having to std::forward, well, everything, sorry for that)
template<class T, class Lambda>
constexpr named_operator_stage_2<T, Lambda> operator OPERATOR_OPENING (
        T&& v,
        const named_operator<Lambda>& lam
    ) {
	return named_operator_stage_2<T, Lambda>{ std::forward<T>(v), lam.lam };
}

template<class Lhv, class Rhv, class Lambda>
constexpr auto operator OPERATOR_CLOSING(
        named_operator_stage_2<Lhv, Lambda>&& middleman,
        Rhv&& rhv
    ) ->
        decltype(middleman.lam(std::forward<Lhv>(middleman.lhv), std::forward<Rhv>(rhv))) {
    return middleman.lam(std::forward<Lhv>(middleman.lhv), std::forward<Rhv>(rhv));
}

template<class Lhv, class Rhv, class Lambda>
constexpr auto operator OPERATOR_ASSIGN(
        named_operator_stage_2<Lhv, Lambda>&& middleman,
        Rhv&& rhv
    ) ->
        decltype(middleman.lam(std::forward<Lhv>(middleman.lhv), std::forward<Rhv>(rhv))) {
    return std::forward<Lhv>(middleman.lhv)
         = middleman.lam(std::forward<Lhv>(middleman.lhv), std::forward<Rhv>(rhv));
}

// and a fancy helper function
template<class Lam>
constexpr named_operator<Lam> make_named_operator(Lam lam) {
    return named_operator<Lam>{ lam };
}
/*************************************************************************************************/

// unary operators work just the same way
// they are even simpler: no need for stupid intermediate objects with data
template<class Lambda>
struct unary_named_operator_stage_2 {
    Lambda lam;
};
template<class Lambda>
struct unary_named_operator {
    Lambda lam;

    constexpr unary_named_operator_stage_2<Lambda> operator OPERATOR_OPENING() {
        return unary_named_operator_stage_2<Lambda>{ lam };
    }

    template<class Rhv>
    constexpr auto operator()(Rhv&& rhv) const -> decltype(lam(std::forward<Rhv>(rhv))) {
        return lam(std::forward<Rhv>(rhv));
    }
};

template<class Rhv, class Lambda>
constexpr auto operator OPERATOR_CLOSING(unary_named_operator_stage_2<Lambda>&& middleman, Rhv&& rhv)
-> decltype(middleman.lam(std::forward<Rhv>(rhv))) {
    return middleman.lam(std::forward<Rhv>(rhv));
}

template<class Lam>
constexpr unary_named_operator<Lam> make_named_unary_operator(Lam lam) {
    return unary_named_operator<Lam>{ lam };
}

/*************************************************************************************************/

} /* namespace named_operators */
} /* namespace functional_hell */

// be good children so Santa and/or NSA give us presents for X-mas
#undef MACRO_PASTE0
#undef MACRO_PASTE
#undef OPERATOR_ASSIGN
#undef OPERATOR_OPENING
#undef OPERATOR_CLOSING

#endif /* NAMED_OPERATORS_HPP_ */
