#include "expression.h"

expression::expression() {
    #ifdef __TEST
        std::cout << "expression created\n";
    #endif
}

expression::expression(location *v) {
    #ifdef __TEST
        std::cout << "expression created\n";
    #endif
    val.loc = v;
    e_type = type::loc;
}

expression::expression(method_call *v) {
    #ifdef __TEST
        std::cout << "expression created\n";
    #endif
    val.mcall = v;
    e_type = type::mcall;
}

expression::expression(literal *v) {
    #ifdef __TEST
        std::cout << "expression created\n";
    #endif
    val.lit = v;
    e_type = type::lit;
}

expression::expression(binary_op *v) {
    #ifdef __TEST
        std::cout << "expression created\n";
    #endif
    val.b_op = v;
    e_type = type::b_op;
}

expression::expression(unary_op *v) {
    #ifdef __TEST
        std::cout << "expression created\n";
    #endif
    val.u_op = v;
    e_type = type::u_op;
}

expression::~expression() {
    switch (e_type) {
        case type::loc: delete val.loc; break;
        case type::mcall: delete val.mcall; break;
        case type::lit: delete val.lit; break;
        case type::b_op: delete val.b_op; break;
    }
}

llvm::Value* expression::codegen() {
    llvm::Value* ret_val;
    switch(e_type) {
        case type::loc:
        return nullptr;
        case type::mcall:
        return nullptr;
        case type::lit:
        return val.lit->codegen();
        case type::b_op:
        return val.b_op->codegen();
        case type::u_op:
        return val.u_op->codegen();
        default:
        return log_error("Unknown Expression Found");
    }
}

type expression::get_type() {
    return e_type;
}