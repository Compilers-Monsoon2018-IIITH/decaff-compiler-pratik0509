#include "param_list.h"

param_list::param_list() {
    #ifdef __TEST
        std::cout << "param_list created\n";
    #endif
}

void param_list::add_param(std::string v) {
    log_error("===" + v);
    param_type p;
    p.str = v.substr(1, v.length() - 2);
    p_list.push_back({p, param_mode::str});
}

void param_list::add_param(expression* v) {
    log_error("=== EXPR");
    param_type p;
    p.expr = v;
    p_list.push_back({p, param_mode::expr});
}

unsigned int param_list::get_num_args() {
    return p_list.size();
}

bool param_list::is_loc(int i) {
    return (p_list[i].second == param_mode::expr && p_list[i].first.expr->get_type() == type::loc);
}

bool param_list::is_string(int i) {
    return (p_list[i].second == param_mode::str);
}


std::string param_list::get_string_argument(int i) {
    if(p_list[i].second != param_mode::str)
        return "";
    return p_list[i].first.str;
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