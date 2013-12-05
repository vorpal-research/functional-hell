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
    template<class T> storage_t<T> unapply(T&& v) const { return { std::forward<T>(v) }; };
};

static auto Id = make_pattern(IdentityExtractor{});

template<std::size_t ...Ixs> struct int_sequence {};

template<std::size_t H, class Seq> struct cons_sequence;
template<std::size_t H, std::size_t ...Tail>
struct cons_sequence<H, int_sequence<Tail...>> { using type = int_sequence<H, Tail...>; };

template<std::size_t Start, class Tup> struct mkIndexer;
template<std::size_t Start, class H, class ...Tail>
struct mkIndexer<Start, std::tuple<H, Tail...>> {
    using type = typename cons_sequence<
                     Start, 
                     typename mkIndexer<Start+1, std::tuple<Tail...>>::type
                 >::type;
};
template<std::size_t Start>
struct mkIndexer<Start, std::tuple<>> {
    using type = int_sequence<>;
};
template<class Tup> using mkIndexer_t = typename mkIndexer<0, Tup>::type;

template<class Tup>
mkIndexer_t<Tup> make_indexer(const Tup&) { return mkIndexer_t<Tup>{}; }

template<class Tup> struct tup2storage;
template<class ...Elts> struct tup2storage<std::tuple<Elts...>> {
    using type = storage_t<Elts...>;
};
template<class ...Elts> struct tup2storage<const std::tuple<Elts...>> {
    using type = storage_t<Elts...>;
};
template<class Tup> using tup2storage_t = typename tup2storage<Tup>::type;

struct TupleExtractor {
    template<class Tup, std::size_t ...Ixs>
    tup2storage_t<Tup> unapply_impl(Tup& tup, int_sequence<Ixs...>) const {
        return { std::get<Ixs>(tup)... };
    }
    template<class ...Args>
    storage_t<Args...> unapply(std::tuple<Args...>& tup) const {
        return unapply_impl<std::tuple<Args...>>(tup, make_indexer(tup));
    }
    template<class ...Args>
    storage_t<Args...> unapply(const std::tuple<Args...>& tup) const {
        return unapply_impl<const std::tuple<Args...>>(tup, make_indexer(tup));
    }
};

static auto Tie = make_pattern(TupleExtractor{});

template<class ...Args>
std::tuple<Args...> tuple_for_match(Args&&... args) {
    return std::tuple<Args...>{ std::forward<Args>(args)... };
}

template<class ...Ts>
struct Switcher {
    std::tuple<Ts...> vals;
    bool guard;

    template<class ...Pats>
    auto Case_(const Pats&... pat) const -> decltype(Tie(pat...) >> vals) {
        return Tie(pat...) >> vals;
    }

    constexpr operator bool() { return guard; }
    bool off() { guard = false; return true; }
};

template<class ...Ts>
Switcher<Ts...> make_switcher(Ts&&... v) { return Switcher<Ts...>{ tuple_for_match(std::forward<Ts>(v)...), true }; };

} /* namespace matchers */
} /* namespace functional_hell */