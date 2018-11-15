#ifndef __IDENTIFIER__
#define __IDENTIFIER__

#include <bits/stdc++.h>
#include "llvm/IR/Value.h"

class identifier {
private:
    std::string name;
public:
    std::string get_name();
    llvm::Value* codegen();
    identifier(std::string);
};

#endif