#ifndef __PARAM_LIST__
#define __PARAM_LIST__

#include <bits/stdc++.h>
#include "expression.h"
#include <new>
#include "codegenerator.h"

class expression;
class location;

typedef struct pp {
    std::string str;
    expression *expr;
} param_type;

enum class param_mode {
    str, expr
};

class param_list {
private:
    std::vector<std::pair<param_type, param_mode>> p_list;
public:
    param_list();
    llvm::Value* codegen(int);
    unsigned int get_num_args();
    void add_param(std::string);
    void add_param(expression*);
};

#endif