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

// Return <Expression>
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
            val = itr->first.ret->codegen();
            if(itr->first.ret->get_type() == type::loc)
                val = builder.CreateLoad(val);
            builder.CreateRet(val);
            break;
            case statement_mode::brek:
            val = llvm::ConstantInt::get(the_context, llvm::APInt(INT_WIDTH, SUCCESS));
            // llvm::LoopInfo* curr_loop = 
            // TODO
            break;
        }
    }
    return val;
}

bool statement::is_return() {
    return has_return;
}