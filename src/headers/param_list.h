#ifndef __PARAM_LIST__
#define __PARAM_LIST__

#include <bits/stdc++.h>
#include "expression.h"

typedef union {
    std::string str;
    expression *expr;
} param_type;

enum class param_mode {
    str, expr
};

class param_list {
private:
    int x;
public:
    param_list();
    void add_param(std::string);
    void add_param(expression*);
};

#endif