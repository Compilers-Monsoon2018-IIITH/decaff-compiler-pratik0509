#ifndef __METHOD_DECLS__
#define __METHOD_DECLS__

#include <bits/stdc++.h>
#include "identifier.h"
#include "arg_list.h"
#include "codegenerator.h"
#include "block.h"

class method_decls {
private:
    std::string r_type;
    identifier *m_id;
    arg_list *args;
    block *m_blk;
public:
    llvm::Value* codegen();
    method_decls(std::string, identifier*, arg_list*, block*);
    method_decls(identifier*, arg_list*, block*);
    ~ method_decls();
};

#endif