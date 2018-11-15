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

llvm::Value* literal::codegen() {
    llvm::Value* val;
    switch(this->type) {
        case l_type::ival:
        val = llvm::ConstantInt::get(the_context, llvm::APInt(INT_WIDTH, v.ival));
        break;
        case l_type::cval:
        val = llvm::ConstantInt::get(the_context, llvm::APInt(CHAR_WIDTH, v.cval));
        break;
        case l_type::bval:
        val = llvm::ConstantInt::get(the_context, llvm::APInt(BOOL_WIDTH, v.bval));
        break;
        default:
        val = nullptr;
    }
    return val;
}
