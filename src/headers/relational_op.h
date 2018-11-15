#ifndef __EXECUTABLES__
#define __EXECUTABLES__

#include <bits/stdc++.h>
#include "llvm/IR/Value.h"

class executables {
private:
    int *id_list;
public:
    llvm::Value* codegen();
    executables();
    ~ executables();
};

#endif