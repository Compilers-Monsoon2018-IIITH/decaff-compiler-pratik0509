#include "location.h"

location::location() {
    #ifdef __TEST
        std::cout << "location created\n";
    #endif
}

location::location(int val) {
    #ifdef __TEST
        std::cout << "location created\n";
    #endif
    v.ival = val;
    loc_type = type3::ival;
}

location::location(char val) {
    #ifdef __TEST
        std::cout << "location created\n";
    #endif
    v.cval = val;
    loc_type = type3::cval;
}

location::location(bool val) {
    #ifdef __TEST
        std::cout << "location created\n";
    #endif
    v.bval = val;
    loc_type = type3::bval;
}
