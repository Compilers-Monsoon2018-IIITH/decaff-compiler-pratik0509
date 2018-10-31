#include "location.h"

location::location() {
    #ifdef __TEST
        std::cout << "location created\n";
    #endif
}

location::location(std::string val) {
    #ifdef __TEST
        std::cout << "location created\n";
    #endif
    name = val;
    loc_type = location_type::scalar;
    idx = NULL;
}

location::location(std::string val, expression *e) {
    #ifdef __TEST
        std::cout << "location created\n";
    #endif
    name = val;
    loc_type = location_type::vector;
    idx = e;
}

