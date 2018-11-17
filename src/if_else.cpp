#include "if_else.h"

kif::kif(expression *e, block *b) {
    #ifdef __TEST
        std::cout << "IF created\n";
    #endif
    cond = e;
    blk = b;
}

kif::kif(expression *e, block *b, kelse* k) {
    #ifdef __TEST
        std::cout << "IF created\n";
    #endif
    cond = e;
    blk = b;
    els = k;
}

kelse::kelse(kif *i, block *b) {
    #ifdef __TEST
        std::cout << "ELSE created\n";
    #endif
    elif = i;
    blk = b;
}

llvm::Value* kif::codegen() {
    llvm::Value* condv = cond->codegen();
    if (!condv)
        return nullptr;
    
    condv = builder.CreateFCmpONE(condv, llvm::ConstantFP::get(the_context, llvm::APFloat(0.0)), "ifcond");

    llvm::Function* the_func = builder.GetInsertBlock()->getParent();

    llvm::BasicBlock *if_bb = llvm::BasicBlock::Create(the_context, "then", the_func);
    // TODO: Work to be done
    return nullptr;
}