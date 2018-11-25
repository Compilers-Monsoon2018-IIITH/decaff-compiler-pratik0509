#ifndef __IF_ELSE__
#define __IF_ELSE__

#include <bits/stdc++.h>
#include "block.h"
#include "codegenerator.h"

class kelse;
class block;

class kif {
private:
    expression *cond;
    block *blk;
    block *els_blk;
public:
    llvm::Value* codegen();
    bool has_return();
    kif(expression*, block*);
    kif(expression*, block*, block*);
};

class kelse {
private:
    kif *elif;
    block *blk;
public:
    llvm::Value* codegen();
    kelse(kif*, block*);
};

#endif