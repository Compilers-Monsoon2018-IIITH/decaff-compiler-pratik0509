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
    
    // Not required now
    // condv = builder->CreateFCmpONE(condv, llvm::ConstantFP::get(the_context, llvm::APFloat(0.0)), "ifcond");

    llvm::Function* the_func = builder->GetInsertBlock()->getParent();

    llvm::BasicBlock *if_bb = llvm::BasicBlock::Create(the_context, "if_bb", the_func);
    llvm::BasicBlock *else_bb = llvm::BasicBlock::Create(the_context, "else_bb");
    llvm::BasicBlock *next_bb = llvm::BasicBlock::Create(the_context, "aftr_cond");
    llvm::BasicBlock *after_if = else_bb;

    bool if_ret = blk->has_return();
    bool els_ret = (els_blk) ? els_blk->has_return() : false;
    if(!els_blk)
        after_if = next_bb;
    
    builder->CreateCondBr(condv, if_bb, after_if);
    builder->SetInsertPoint(if_bb);

    llvm::Value *if_val = blk->codegen();
    if(!if_val)
        return if_val;
    
    if (!if_ret)
        builder->CreateBr(next_bb);

    if_bb = builder->GetInsertBlock();

    llvm::Value* els_val;

    if (els_blk) {
        the_func->getBasicBlockList().push_back(else_bb);
        builder->SetInsertPoint(else_bb);
        els_val = els_blk->codegen();
        if(!els_val)
            return els_val;
        if(els_ret)
            builder->CreateBr(next_bb);
    }

    the_func->getBasicBlockList().push_back(next_bb);

    builder->SetInsertPoint(next_bb);

    if(els_ret && if_ret) {
        llvm::Type* ret_type = builder->GetInsertBlock()->getParent()->getReturnType();
        // TODO: Add for Void
        builder->CreateRet(llvm::ConstantInt::get(the_context, llvm::APInt(INT_WIDTH, SUCCESS)));
    }
    llvm::Value* ret_val = llvm::ConstantInt::get(the_context, llvm::APInt(INT_WIDTH, SUCCESS));
    return nullptr;
}

bool kif::has_return() {
    return blk->has_return() || (els_blk && els_blk->has_return());
}