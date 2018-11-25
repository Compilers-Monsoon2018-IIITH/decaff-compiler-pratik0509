#include "global_decl.h"

void global_decl::add_field(field_decls *decl) {
    f_decls.emplace_back(decl);
    return;
}

void global_decl::add_method(method_decls *decl) {
    m_decls.emplace_back(decl);
    return;
}

global_decl::global_decl() {
    #ifdef __TEST
        std::cout << "Global Declaration created\n";
    #endif
    f_decls = std::list<field_decls*>();
    m_decls = std::list<method_decls*>();
}

llvm::Value* global_decl::codegen() {
    llvm::Value* val = nullptr;
    for(auto &itr: f_decls) {
        val = itr->codegen();
        if(!val)
            return nullptr;
    }
    for(auto &itr: m_decls) {
        val = itr->codegen();
        if(!val)
            return nullptr;
    }
    llvm::Value *ret_val = llvm::ConstantInt::get(the_context, llvm::APInt(INT_WIDTH, SUCCESS));
    return ret_val;
}