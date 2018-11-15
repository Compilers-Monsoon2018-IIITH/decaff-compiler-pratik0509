#ifndef __BINARY_OP__
#define __BINARY_OP__

#include <bits/stdc++.h>
#include "expression.h"
#include "llvm/IR/Value.h"

class expression;

enum class binary_operator {
    add, subtract, multiply, divide, less_than,
    greater_than, equals, less_than_equals, greater_than_equals,
    not_equals, modulo, logical_and, logical_or
};

class binary_op {
private:
    expression *expr1;
    expression *expr2;
    binary_operator op;
public:
    llvm::Value* codegen();
    friend void set_operator(binary_op*, std::string);
    binary_op(expression*, expression*, std::string);
};

#endif