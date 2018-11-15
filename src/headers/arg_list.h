#ifndef __ARG_LIST__
#define __ARG_LIST__

#include <bits/stdc++.h>
#include "identifier.h"
#include "llvm/IR/Value.h"


class arg_list {
private:
    std::list<std::pair<std::string, identifier*>> args;
public:
    llvm::Value* codegen();
    void add_identifier(std::string, identifier*);
    arg_list();
};
#endif