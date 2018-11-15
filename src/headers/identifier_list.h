#ifndef __IDENTIFIER_LIST__
#define __IDENTIFIER_LIST__

#include <bits/stdc++.h>
#include "identifier.h"
#include "llvm/IR/Value.h"

class identifier_list {
private:
    std::map<std::string, identifier*> ids;
public:
    void add_identifier(identifier*);
    llvm::Value* codegen();
    identifier_list();
};

#endif