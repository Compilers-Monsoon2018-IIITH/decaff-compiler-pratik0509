#include "expression.h"

expression::expression(location *v) {
    #ifdef __TEST
        std::cout << "expression created\n";
    #endif
    val.loc = v;
}

expression::expression(method_call *v) {
    #ifdef __TEST
        std::cout << "expression created\n";
    #endif
    val.mcall = v;
}

expression::expression(literal *v) {
    #ifdef __TEST
        std::cout << "expression created\n";
    #endif
    val.lit = v;
}

expression::~expression() {
    switch (e_type) {
        case type::loc: delete val.loc; break;
        case type::mcall: delete val.mcall; break;
        case type::lit: delete val.lit; break;
    }
}