#include <iostream>

#include "matchers_fancy_syntax.h"

using namespace functional_hell::matchers;

enum Color { R, B };

// we do not encourage anyone to use the fancy syntax and matchers to match enums
// but hey, you can see for yourself: the following functions
// produce _identical_ object code

const char* color2string(Color clr) {
    SWITCH(clr) {
        CASE(Id(R)) return "Red";
        CASE(Id(B)) return "Black";
    }
    return ""; // clang is not very clever about custom syntax constructs
}
const char* color2string_traditional(Color clr) {
    switch(clr) {
        case R: return "Red";
        case B: return "Black";
    }
    return "";
}

int main() {
    std::cout << color2string(Color::R) << std::endl;
    std::cout << color2string_traditional(Color::B) << std::endl;
}
