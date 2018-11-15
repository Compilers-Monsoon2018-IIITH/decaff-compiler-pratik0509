#ifndef __PROGRAM__
#define __PROGRAM__

#include <bits/stdc++.h>
#include "global_decl.h"
#include "llvm/IR/Value.h"

class program {
private:
    global_decl *g_decl;
public:
    llvm::Value* codegen();
    void set_global_decl(global_decl *decl);
    program();
    ~ program();
};

#endif