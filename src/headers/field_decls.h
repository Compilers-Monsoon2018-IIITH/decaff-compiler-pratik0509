#ifndef __FIELD_DECLS__
#define __FIELD_DECLS__

#include <bits/stdc++.h>
#include "identifier_list.h"
#include "llvm/IR/Value.h"

class field_decls {
private:
    std::string f_type;
    identifier_list *id_list;
public:
    void set_field(std::string, identifier_list*);
    llvm::Value* codegen();
    field_decls();
    ~ field_decls();
};

#endif