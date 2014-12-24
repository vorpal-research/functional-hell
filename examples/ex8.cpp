#include <iostream>

// provide the -I.. flag
#include "matchers_aux.hpp"
#include "matchers_fancy_syntax.h"

using namespace functional_hell::matchers;
using namespace functional_hell::matchers::placeholders;

int main() {
    auto pred = [](int a){ return a > 8; };

    int x = 9;
    int y = 4;

    SWITCH(x){
        CASE(Guard(pred)) {
            std::cout << "Hit" << std::endl;
        }
        CASE(_) throw 0;
    }
    SWITCH(y) {
        CASE(Guard(pred)) {
            std::cout << "Not hit!" << std::endl;
            throw 0;
        }
    }

    SWITCH(y) {
        CASE(View([](int a){ return a + 5; }, Guard(pred))) std::cout << "Hit" << std::endl;
        CASE(_) throw 0;
    }
}
