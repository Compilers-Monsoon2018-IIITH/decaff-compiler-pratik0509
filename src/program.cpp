#include "program.h"

void program::set_global_decl(global_decl *decl) {
    if (g_decl != NULL)
        delete g_decl;
    g_decl = decl;
    return;
}

program::program() {
    #ifdef __TEST
        std::cout << "Program created\n";
    #endif
    g_decl = NULL;
}

program::~program() {
    if (g_decl != NULL)
        delete g_decl;
}

llvm::Value* program::codegen() {
    llvm::Value* val = nullptr;
    return g_decl->codegen();
}

void program::codeout() {
    std::cerr << "Generating Code to stdout:" << std::endl;
    the_module->print(llvm::outs(), nullptr);
    return;
}