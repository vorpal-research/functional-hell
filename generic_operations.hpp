/*
 * generic_operators.hpp
 * author: Mikhail Beliaev
 * A set of operators similar to the ones found in <functional>, but with templates moved down
 * to operator level. This means that instead of
 *      std::transform(a, b, c, e, std::plus<int>{});
 * you can write
 *      std::transform(a, b, c, e, plus{});
 * and not care about argument types
 */
#ifndef GENERIC_OPERATORS_HPP_
#define GENERIC_OPERATORS_HPP_

#include <functional>

namespace functional_hell {
namespace generic_operations {

// with operators.def, this is pretty straightforward

#define PROCESS_BINARY(STDDEF, OP) \
    struct generic_ ## STDDEF { \
        template<class Lhv, class Rhv> \
        constexpr auto operator()(Lhv&& lhv, Rhv&& rhv) const -> decltype(std::forward<Lhv>(lhv) OP std::forward<Rhv>(rhv)) { \
        	return std::forward<Lhv>(lhv) OP std::forward<Rhv>(rhv); \
        } \
    };

#define PROCESS_PREFIX(STDDEF, OP) \
    struct generic_ ## STDDEF { \
        template<class Rhv> \
        constexpr auto operator()(Rhv&& rhv) const -> decltype(OP std::forward<Rhv>(rhv)) { \
            return OP std::forward<Rhv>(rhv); \
        } \
    };

#define PROCESS_POSTFIX(STDDEF, OP) \
    struct generic_ ## STDDEF { \
        template<class Rhv> \
        constexpr auto operator()(Rhv&& rhv) const -> decltype(std::forward<Rhv>(rhv) OP) { \
            return std::forward<Rhv>(rhv) OP; \
        } \
    };
#define PROCESS_CAST(STDDEF, CAST) \
    template<class To> \
    struct generic_ ## STDDEF { \
        template<class Rhv> \
        constexpr auto operator()(Rhv&& rhv) const -> decltype(CAST<To>(std::forward<Rhv>(rhv))) { \
            return CAST<To>(std::forward<Rhv>(rhv)); \
        } \
    };

#include "operators.def"

// we also provide guys for common other operations: indexing, calls, typical collection ops

struct generic_index {
    template<class Lhv, class Rhv>
    constexpr auto operator()(Lhv&& lhv, Rhv&& rhv) const -> decltype(std::forward<Lhv>(lhv)[std::forward<Rhv>(rhv)]) {
        return std::forward<Lhv>(lhv)[std::forward<Rhv>(rhv)];
    }
};
struct generic_call {
    template<class Lhv, class ...Args>
    constexpr auto operator()(Lhv&& lhv, Args&&... args) const -> decltype(std::forward<Lhv>(lhv)(std::forward<Args>(args)...)) {
        return std::forward<Lhv>(lhv)(std::forward<Args>(args)...);
    }
};

#define GENERICIZE_CONTAINER_OP(OP, EXPR_USING_CON) \
    struct generic_ ## OP { \
        template<class Con> \
        constexpr auto operator()(Con&& con) const -> decltype(EXPR_USING_CON) { \
            return EXPR_USING_CON; \
        } \
    };
GENERICIZE_CONTAINER_OP(size, std::forward<Con>(con).size())
GENERICIZE_CONTAINER_OP(empty, std::forward<Con>(con).size() == 0U)
GENERICIZE_CONTAINER_OP(front, std::forward<Con>(con).front())
GENERICIZE_CONTAINER_OP(back, std::forward<Con>(con).back())
GENERICIZE_CONTAINER_OP(begin, std::begin(std::forward<Con>(con)))
GENERICIZE_CONTAINER_OP(end, std::end(std::forward<Con>(con)))
GENERICIZE_CONTAINER_OP(cbegin, std::forward<Con>(con).cbegin())
GENERICIZE_CONTAINER_OP(cend, std::forward<Con>(con).cend())
GENERICIZE_CONTAINER_OP(rbegin, std::forward<Con>(con).rbegin())
GENERICIZE_CONTAINER_OP(rend, std::forward<Con>(con).rend())
GENERICIZE_CONTAINER_OP(crbegin, std::forward<Con>(con).crbegin())
GENERICIZE_CONTAINER_OP(crend, std::forward<Con>(con).crend())

#undef GENERICIZE_CONTAINER_OP

}
}

#endif /* GENERIC_OPERATORS_HPP_ */
