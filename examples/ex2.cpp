#include <iostream>
#include <utility>
#include <memory>
#include <cassert>

// provide the -I.. flag
#include "matchers_aux.hpp"

using namespace functional_hell::matchers;
using namespace std::placeholders;
using functional_hell::matchers::placeholders::_;

struct pairExtractor {
    template<class A, class B>
    storage_t<A&, B&> unapply(std::pair<A, B>& v) const {
        return make_storage(v.first, v.second);
    }

    template<class A, class B>
    storage_t<const A&, const B&> unapply(const std::pair<A, B>& v) const {
        return make_storage(v.first, v.second);
    }
};

auto Pair = make_pattern(pairExtractor{});

int main () {
    auto pr = std::make_pair(std::make_pair(1, 2), 3);

    if(auto m = Pair(Pair(1, _2), _1) >> pr) {
        assert((m->_1 == 3));
        assert((m->_2 == 2));

        std::cerr << m->_1 << std::endl; // 3
        std::cerr << m->_2 << std::endl; // 2
    }

    if(auto m = Pair(Pair(_1, _2), _) >> pr) {
        assert((m->_1 == 1));
        assert((m->_2 == 2));

        std::cerr << m->_1 << std::endl; // 1
        std::cerr << m->_2 << std::endl; // 2

        m->_2 = 42;

        assert((m->_2 == 42));
    }

    assert((pr.first.second == 42));
    std::cerr << pr.first.second << std::endl; // 42

}
