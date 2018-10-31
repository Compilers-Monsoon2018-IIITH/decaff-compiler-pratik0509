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
}

void statement::add_statement(assignment* b) {
    #ifdef __TEST
        std::cout << "statement created" << std::endl;
    #endif
    statement_type s;
    s.asg = b;
    stmnts.push_back({s, statement_mode::asg});
}
