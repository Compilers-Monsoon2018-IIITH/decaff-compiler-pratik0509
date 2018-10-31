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