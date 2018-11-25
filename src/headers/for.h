#ifndef __FOR__
#define __FOR__

#include <bits/stdc++.h>
#include "expression.h"
#include "block.h"
#include "llvm/IR/Value.h"

class block;

class kfor {
private:
    std::string iter;
    expression *start;
    expression *end;
    block *blk;
public:
    llvm::Value* codegen();
    kfor(std::string, expression*, expression*, block*);
    bool has_return();
};

#endif