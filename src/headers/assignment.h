#ifndef __ASSIGNMENT__
#define __ASSIGNMENT__

#include <bits/stdc++.h>
#include "expression.h"
#include "codegenerator.h"

class expression;

class assignment {
private:
    location *loc;
    std::string op;
    expression *expr;
public:
    llvm::Value* codegen();
    assignment(location*, std::string, expression*);
};

#endif