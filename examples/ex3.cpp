#include <iostream>

#include "matchers_fancy_syntax.h"

using namespace functional_hell::matchers;

enum Color { R, B };

// we do not encourage anyone to use the fancy syntax and matchers to match enums
// but hey, you can see for yourself: the following functions
// produce _identical_ object code

const char* color2string(Color clr) {
    SWITCH(clr) {
        CASE(R) return "Red";
        CASE(B) return "Black";
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

bool ptrn(Color a, Color b, Color c, Color d) {
    SWITCH(a,b,c,d) {
        NAMED_CASE(m, R, R, _1, _1){
            if(m->_1 == R) return true;
            else return false;
        }
        CASE(B, B, B, B) return true;
        CASE(R, R, B, B) return true;
        CASE(B, B, R, R) return true;
    }
    return false;
}

int main() {
    std::cout << color2string(Color::R) << std::endl;
    std::cout << color2string_traditional(Color::B) << std::endl;
}
