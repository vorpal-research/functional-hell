#include <iostream>
#include <utility>
#include <memory>
#include <string>
#include <vector>
#include <cassert>


// provide the -I.. flag
#include "matchers_aux.hpp"

using namespace functional_hell::matchers;
using namespace functional_hell::matchers::placeholders;

struct Incomparable {
};

bool operator==(Incomparable, Incomparable) = delete;

struct Struct {
    Incomparable y;
    Incomparable x;
};

struct StructExtractor
{
    storage_t<Incomparable&, Incomparable&> unapply(Struct& v) const {
        return make_storage(v.y, v.x);
    }

    storage_t<const Incomparable&, const Incomparable&> unapply(const Struct& v) const {
        return make_storage(v.y, v.x);
    }
};

static auto $Struct = make_pattern(StructExtractor{});


int main() {

    auto a = Struct{ {}, {} };
    assert($Struct(_1, _2) >> a);
    assert(!($Struct(_1, _1) >> a)); // comparing incomparables yields false
}

