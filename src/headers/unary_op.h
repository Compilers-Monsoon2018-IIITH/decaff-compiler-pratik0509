#ifndef __UNARY_OP__
#define __UNARY_OP__

#include <bits/stdc++.h>
#include "expression.h"
#include "codegenerator.h"

class expression;

enum class unary_operator {
    unary_not, unary_minus, unary_plus
};

class unary_op {
private:
    expression *expr;
    unary_operator op;
public:
    llvm::Value* codegen();
    unary_op(expression*, std::string);
};

#endif