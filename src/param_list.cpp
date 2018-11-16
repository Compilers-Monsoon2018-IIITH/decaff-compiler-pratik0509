#include "param_list.h"

param_list::param_list() {
    #ifdef __TEST
        std::cout << "param_list created\n";
    #endif
}

void param_list::add_param(std::string v) {
    param_type p;
    p.str = v.c_str();
    p_list.push_back({p, param_mode::str});
}

void param_list::add_param(expression* v) {
    param_type p;
    p.expr = v;
    p_list.push_back({p, param_mode::expr});
}

unsigned int param_list::get_num_args() {
    return p_list.size();
}

llvm::Value* param_list::codegen(int i) {
    if (i >= p_list.size())
        return log_error("Invalid Index of Parameter List!!");
    switch(p_list[i].second) {
        case param_mode::expr:
        return p_list[i].first.expr->codegen();
        default:
        return log_error("Invalid Parameter Type");
    }
}