#include "codegenerator.h"

llvm::LLVMContext the_context;
llvm::IRBuilder<> builder(the_context);
llvm::Module* the_module;
std::map<std::string, llvm::AllocaInst*> named_values;

std::stack<loop_metadata*> loop_stack;

llvm::Value *log_error(std::string str) {
    std::cerr << str << std::endl;
    return nullptr;
}

llvm::AllocaInst *create_entry_alloc(llvm::Function *func, std::string var_name, std::string typ) {
    /* Get the builder for current context */
    llvm::IRBuilder<> tmp(&func->getEntryBlock(), func->getEntryBlock().begin());
    llvm::AllocaInst *alloca_instruction = nullptr;
    if (typ == "int") {
        alloca_instruction = tmp.CreateAlloca(llvm::Type::getInt32Ty(the_context), SUCCESS, var_name);
    } else if (typ == "bool") {
        alloca_instruction = tmp.CreateAlloca(llvm::Type::getInt1Ty(the_context), SUCCESS, var_name);
    } else if (typ == "char") {
        alloca_instruction = tmp.CreateAlloca(llvm::Type::getInt8Ty(the_context), SUCCESS, var_name);
    }
    return alloca_instruction;
}
