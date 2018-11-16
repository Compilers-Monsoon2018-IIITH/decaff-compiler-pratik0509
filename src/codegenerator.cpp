#include "codegenerator.h"

llvm::LLVMContext the_context;
llvm::IRBuilder<> builder(the_context);
llvm::Module* the_module;
std::map<std::string, llvm::Value *> named_values;

llvm::Value *log_error(std::string str) {
    std::cerr << str << std::endl;
    return nullptr;
}
