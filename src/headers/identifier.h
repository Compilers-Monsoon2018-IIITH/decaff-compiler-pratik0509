#ifndef __IDENTIFIER__
#define __IDENTIFIER__

#include <bits/stdc++.h>
#include "codegenerator.h"

class identifier {
private:
    std::string name;
    int arr_sz;
public:
    std::string get_name();
    llvm::Value* codegen();
    identifier(std::string);
    identifier(std::string, int);
};

#endif