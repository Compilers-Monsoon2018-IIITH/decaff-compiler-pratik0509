#include "literal.h"

literal::literal(int val) {
    #ifdef __TEST
        std::cout << "literal created\n";
    #endif
    v.ival = val;
    this->type = l_type::ival;
}

literal::literal(char val) {
    #ifdef __TEST
        std::cout << "literal created\n";
    #endif
    v.cval = val;
    this->type = l_type::cval;
}

literal::literal(bool val) {
    #ifdef __TEST
        std::cout << "literal created\n";
    #endif
    v.bval = val;
    this->type = l_type::bval;
}
