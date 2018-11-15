#ifndef __METHOD_CALL__
#define __METHOD_CALL__

#include <bits/stdc++.h>
#include "location.h"
#include "param_list.h"
#include "llvm/IR/Value.h"

class param_list;

class method_call {
private:
    location *loc;
    param_list *p_list;
public:
    llvm::Value* codegen();
    method_call();
    void set_method_call(location*, param_list*);
};

#endif