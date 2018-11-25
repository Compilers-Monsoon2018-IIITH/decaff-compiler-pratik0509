#include "for.h"

kfor::kfor(std::string i, expression *e1, expression *e2, block *b) {
    #ifdef __TEST
        std::cout << "for created" << std::endl;
    #endif
    iter = i;
    start = e1;
    end = e2;
    blk = b;
}

bool kfor::has_return() {
    return blk->has_return();
}

llvm::Value* kfor::codegen() {
    llvm::Value *init_state = start->codegen();
    if (!init_state)
        return init_state;
    
    if (start->get_type() == type::loc)
        init_state = builder.CreateLoad(init_state);
    

    llvm::Function *the_func = builder.GetInsertBlock()->getParent();

    llvm::AllocaInst *local_var = create_entry_alloc(the_func, iter, "int");
    builder.CreateStore(init_state, local_var);

    llvm::BasicBlock *prev_bb = builder.GetInsertBlock();
    llvm::BasicBlock *loop_bb = llvm::BasicBlock::Create(the_context, "loop_bb", the_func);
    llvm::BasicBlock *afterloop_bb = llvm::BasicBlock::Create(the_context, "afterloop_bb", the_func);
    builder.CreateBr(loop_bb);
    builder.SetInsertPoint(loop_bb);

    llvm::PHINode *iter_var = builder.CreatePHI(llvm::Type::getInt32Ty(the_context), 2, iter); // 2 is loop join flows
    iter_var->addIncoming(init_state, prev_bb);
    llvm::Value *end_state = end->codegen();
    if (!end_state)
        return end_state;

    if (end->get_type() == type::loc)
        end_state = builder.CreateLoad(end_state);

    llvm::AllocaInst *old_iter_val = named_values[iter];
    named_values[iter] = local_var;
    llvm::Value* block_val = blk->codegen();
    if (!block_val)
        return block_val;
    loop_stack.push(new loop_metadata(end_state, iter, iter_var, afterloop_bb, loop_bb));

    llvm::Value *cur_iter_val = builder.CreateLoad(local_var, iter);
    llvm::Value *iter_step = llvm::ConstantInt::get(the_context, llvm::APInt(INT_WIDTH, STEP_DEFAULT));
    llvm::Value *next_iter_val = builder.CreateAdd(cur_iter_val, iter_step, "nxt_val");
    builder.CreateStore(next_iter_val, local_var);
    end_state = builder.CreateICmpSLT(next_iter_val, end_state, "end_cond");
    llvm::BasicBlock *end_blk = builder.GetInsertBlock();
    builder.CreateCondBr(end_state, loop_bb, afterloop_bb);
    builder.SetInsertPoint(afterloop_bb);
    iter_var->addIncoming(next_iter_val, end_blk);

    if (old_iter_val) {
        named_values[iter] = old_iter_val;
    } else {
        named_values.erase(iter);
    }
    llvm::Value *V = llvm::ConstantInt::get(the_context, llvm::APInt(INT_WIDTH, STEP_DEFAULT));
    return V;
}