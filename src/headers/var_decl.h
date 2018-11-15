#ifndef __VAR_DECL__
#define __VAR_DECL__

#include <bits/stdc++.h>
#include "identifier_list.h"
#include "llvm/IR/Value.h"

class var_decl {
private:
    std::string f_type;
    identifier_list *id_list;
public:
    void set_field(std::string, identifier_list*);
    llvm::Value* codegen();
    var_decl();
    ~ var_decl();
};

#endif