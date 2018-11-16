#ifndef __METHOD_DECLS__
#define __METHOD_DECLS__

#include <bits/stdc++.h>
#include "identifier.h"
#include "arg_list.h"
#include "codegenerator.h"

class method_decls {
private:
    std::string r_type;
    identifier *m_id;
    arg_list *args;
public:
    llvm::Value* codegen();
    method_decls(std::string, identifier*, arg_list*);
    ~ method_decls();
};

#endif