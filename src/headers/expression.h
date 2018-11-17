#ifndef __EXPRESSION__
#define __EXPRESSION__

#include <bits/stdc++.h>
#include "location.h"
#include "method_call.h"
#include "literal.h"
#include "binary_op.h"
#include "unary_op.h"
#include "llvm/IR/Value.h"

class binary_op;
class unary_op;
class location;
class method_call;

typedef union {
    location *loc;
    method_call *mcall;
    literal *lit;
    binary_op *b_op;
    unary_op *u_op;
} value;

enum class type {
    loc, mcall, lit, b_op, u_op
};

class expression {
private:
    value val;
    type e_type;
public:
    expression();
    expression(location *val);
    expression(binary_op *val);
    expression(method_call *val);
    expression(literal *val);
    expression(unary_op *val);
    llvm::Value* codegen();
    type get_type();
    ~ expression();
};

#endif