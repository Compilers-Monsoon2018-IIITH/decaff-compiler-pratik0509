#include "literal.h"

#include "iostream"
#include "llvm/IR/Value.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"

#define INT_WIDTH 32
#define CHAR_WIDTH 8
#define BOOL_WIDTH 8

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


llvm::LLVMContext the_context;
llvm::IRBuilder<> Builder(the_context);
std::unique_ptr<llvm::Module> the_module;
std::map<std::string, llvm::Value *> named_values;

llvm::Value *LogErrorV(const char *str) {
    std::cerr << str << std::endl;
    return nullptr;
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
