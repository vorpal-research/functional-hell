#include <iostream>
#include <utility>
#include <memory>

// provide the -I.. flag
#include "matchers_aux.hpp"

using namespace functional_hell::matchers;

struct example_matcher {

    template<class A, class B>
    storage_t<A&, B&> unapply(std::pair<A, B>& v) const {
        storage_t<A&, B&> ret;
        ret.construct();
        ret->set_1(v.first);
        ret->set_2(v.second);
        return ret;
    }
};

auto $pair = make_pattern(example_matcher{});

int main () {
    auto pr = std::make_pair(std::make_pair(1, 2), 3);

    if(auto m = $pair($pair(1, _2), _1) >> pr) {
        std::cerr << m->_1 << std::endl; // 3
        std::cerr << m->_2 << std::endl; // 2
    }

    if(auto m = $pair($pair(_1, _2), _) >> pr) {
        std::cerr << m->_1 << std::endl; // 1
        std::cerr << m->_2 << std::endl; // 2
    }

}