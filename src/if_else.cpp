#include "if_else.h"

kif::kif(expression *e, block *b) {
    #ifdef __TEST
        std::cout << "IF created\n";
    #endif
    cond = e;
    blk = b;
    els_blk = nullptr;
}

kif::kif(expression *e, block *b, block* k) {
    #ifdef __TEST
        std::cout << "IF created\n";
    #endif
    cond = e;
    blk = b;
    els_blk = k;
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

    llvm::BasicBlock *if_bb = llvm::BasicBlock::Create(the_context, "if_bb", the_func);
    llvm::BasicBlock *else_bb = llvm::BasicBlock::Create(the_context, "else_bb");
    llvm::BasicBlock *next_bb = llvm::BasicBlock::Create(the_context, "aftr_cond");
    llvm::BasicBlock *after_if = else_bb;

    bool if_ret = blk->has_return();
    

    // TODO: Work to be done
    return nullptr;
}

bool kif::has_return() {
    return blk->has_return() || (els_blk && els_blk->has_return());
}