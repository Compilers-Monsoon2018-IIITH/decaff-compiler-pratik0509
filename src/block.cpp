#include "block.h"

block::block(executables *e) {
    #ifdef __TEST
        std::cout << "Block created\n";
    #endif
    exec = e;
}

block::~block() {
    if (exec != NULL)
        delete exec;
}

llvm::Value* block::codegen() {
    std::map<std::string, llvm::AllocaInst*> old_values;
    return exec->codegen(old_values);
}