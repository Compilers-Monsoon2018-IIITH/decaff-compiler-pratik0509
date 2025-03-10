#ifndef __VAR_DECL__
#define __VAR_DECL__

#include <bits/stdc++.h>
#include "identifier_list.h"
#include "codegenerator.h"

class var_decl {
private:
    std::string v_type;
    identifier_list *id_list;
public:
    void set_field(std::string, identifier_list*);
    llvm::Value* codegen(std::map<std::string, llvm::AllocaInst*> &);
    var_decl();
    ~ var_decl();
};

#endif