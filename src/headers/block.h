#ifndef __BLOCK__
#define __BLOCK__

#include <bits/stdc++.h>
#include "executables.h"
#include "codegenerator.h"

class executables;

class block {
private:
    executables *exec;
public:
    llvm::Value* codegen();
    block(executables*);
    ~ block();
};

#endif