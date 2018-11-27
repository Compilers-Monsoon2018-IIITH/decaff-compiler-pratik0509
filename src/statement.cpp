#include "statement.h"

statement::statement() {
    #ifdef __TEST
        std::cout << "statement created" << std::endl;
    #endif
}

void statement::add_statement(block* b) {
    #ifdef __TEST
        std::cout << "statement created" << std::endl;
    #endif
    statement_type s;
    s.blk = b;
    stmnts.push_back({s, statement_mode::blk});
    has_return = b->has_return();
}

void statement::add_statement(assignment* b) {
    #ifdef __TEST
        std::cout << "statement created" << std::endl;
    #endif
    statement_type s;
    s.asg = b;
    stmnts.push_back({s, statement_mode::asg});
    has_return = false;
}

void statement::add_statement(method_call* b) {
    #ifdef __TEST
        std::cout << "statement created" << std::endl;
    #endif
    statement_type s;
    s.m_call = b;
    stmnts.push_back({s, statement_mode::m_call});
    has_return = false;
}

// Return <expression>
void statement::add_statement(expression* b) {
    #ifdef __TEST
        std::cout << "statement created" << std::endl;
    #endif
    statement_type s;
    s.ret = b;
    stmnts.push_back({s, statement_mode::ret});
    has_return = true;
}

void statement::add_statement(char b) {
    #ifdef __TEST
        std::cout << "statement created" << std::endl;
    #endif
    statement_type s;
    s.jump = b;
    stmnts.push_back({s, (b == 'b') ? statement_mode::brek : statement_mode::cont});
    has_return = false;
}

void statement::add_statement(kfor *b) {
    #ifdef __TEST
        std::cout << "statement created" << std::endl;
    #endif
    statement_type s;
    s.loop = b;
    stmnts.push_back({s, statement_mode::loop});
    has_return = b->has_return();
}

void statement::add_statement(kif *b) {
    #ifdef __TEST
        std::cout << "statement created" << std::endl;
    #endif
    statement_type s;
    s.cond = b;
    stmnts.push_back({s, statement_mode::cond});
    has_return = b->has_return();
}

llvm::Value* statement::codegen() {
    log_error("In statement loop!!");
    llvm::Value* val = llvm::ConstantInt::get(the_context, llvm::APInt(INT_WIDTH, SUCCESS));
    for(auto itr = stmnts.begin(); itr != stmnts.end(); ++itr) {
        switch(itr->second) {
            case statement_mode::blk:
            val = itr->first.blk->codegen();
            break;
            case statement_mode::asg:
            val = itr->first.asg->codegen();
            break;
            case statement_mode::m_call:
            val = itr->first.m_call->codegen();
            break;
            case statement_mode::ret:
            if(!(itr->first.ret)) {
                builder->CreateRetVoid();
            } else {
                val = itr->first.ret->codegen();
                if(itr->first.ret->get_type() == type::loc)
                    val = builder->CreateLoad(val);
                builder->CreateRet(val);
            }
            break;
            case statement_mode::cond:
            val = itr->first.cond->codegen();
            break;
            case statement_mode::loop:
            val = itr->first.loop->codegen();
            break;
            case statement_mode::brek:
            {
            val = llvm::ConstantInt::get(the_context, llvm::APInt(INT_WIDTH, SUCCESS));
            loop_metadata* cur_loop = loop_stack.top();
            builder->CreateBr(cur_loop->afterloop_bb);
            }
            break;
            case statement_mode::cont:
            {
            val = llvm::ConstantInt::get(the_context, llvm::APInt(INT_WIDTH, SUCCESS));
            loop_metadata* cur_loop = loop_stack.top();
            std::string iter = cur_loop->iter_name;
            llvm::AllocaInst *iter_var = named_values[iter];
            llvm::Value *iter_step = llvm::ConstantInt::get(the_context, llvm::APInt(INT_WIDTH, SUCCESS));
            llvm::Value *cur_iter = builder->CreateLoad(iter_var, iter);
            llvm::Value *next_iter = builder->CreateAdd(cur_iter, iter_step, "next_value");
            builder->CreateStore(next_iter, iter_var);
            llvm::Value *cond = builder->CreateICmpULE(next_iter, cur_loop->end_cond,
                                                                        "end_cond");
            llvm::BasicBlock *loop_after_bb = builder->GetInsertBlock();
            builder->CreateCondBr(cond, cur_loop->loop_bb, cur_loop->afterloop_bb);
            }
            break;
        }
    }
    return val;
}

bool statement::is_return() {
    return has_return;
}