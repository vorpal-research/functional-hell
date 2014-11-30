#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

#include "matchers_fancy_syntax.h"

enum SomeEnum { Foo, Bar };

SomeEnum from_string(const std::string& str) {
    using functional_hell::matchers::Nil;

    SWITCH(str) {
        CASE("Foo") return Foo;
        CASE("Bar") return Bar;
        CASE( Nil ) return Foo;
        DEFAULT_CASE return Bar;
    }
    return SomeEnum(-1);
}

int main() {
    using namespace std;
    std::cout << from_string("Foo") << std::endl;
    std::cout << from_string("Bar") << std::endl;
    std::cout << from_string("")    << std::endl;
    std::cout << from_string("Hoo") << std::endl;
}
