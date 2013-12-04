#include "matchers_aux.hpp"

#define SWITCH(V)\
    for(auto a_rather_dedicated_switcher_ = functional_hell::matchers::make_switcher(V);\
        a_rather_dedicated_switcher_;\
        a_rather_dedicated_switcher_.off())

#define GUARDED_CASE(...)\
        if(a_rather_dedicated_switcher_)\
        if(__VA_ARGS__)\
        if(a_rather_dedicated_switcher_.off())

#define CASE(...)\
        GUARDED_CASE(a_rather_dedicated_switcher_.Case_(__VA_ARGS__))
#define NAMED_CASE(NAME, ...)\
        GUARDED_CASE(auto NAME = a_rather_dedicated_switcher_.Case_(__VA_ARGS__))
#define DEFAULT_CASE GUARDED_CASE(true)
