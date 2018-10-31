#include "method_call.h"

method_call::method_call() {
    #ifdef __TEST
        std::cout << "method_call created\n";
    #endif
}

method_call::method_call(int val) {
    #ifdef __TEST
        std::cout << "method_call created\n";
    #endif
    v.ival = val;
    l_type = type2::ival;
}

method_call::method_call(char val) {
    #ifdef __TEST
        std::cout << "method_call created\n";
    #endif
    v.cval = val;
    l_type = type2::cval;
}

method_call::method_call(bool val) {
    #ifdef __TEST
        std::cout << "method_call created\n";
    #endif
    v.bval = val;
    l_type = type2::bval;
}
