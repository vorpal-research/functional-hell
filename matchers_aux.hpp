#include "matchers.hpp"

namespace functional_hell {
namespace matchers {

template<class Extractor>
struct pattern {
    Extractor ex;

    template<class ...Args>
    tree_matcher<Extractor, Args...> operator()(const Args&... args) const {
        return { ex, args... };
    }
};

template<class Extractor>
pattern<Extractor> make_pattern(const Extractor& ex) {
    return { ex };
}

struct IdentityExtractor {
    template<class T>
    storage_t<T> unapply(T&& v) const { return { std::forward<T>(v) }; };
};

static auto Id = make_pattern(IdentityExtractor{});

template<class T>
struct Switcher {
    T val;
    bool guard;

    template<class Pat>
    auto Case_(const Pat& pat) const -> decltype(pat >> val) {
        return pat >> val;
    }

    constexpr operator bool() { return guard; }
    bool off() { guard = false; return true; }
};

template<class T>
Switcher<T> make_switcher(T&& v) { return Switcher<T>{ std::forward<T>(v), true }; };

} /* namespace matchers */
} /* namespace functional_hell */