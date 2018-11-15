#ifndef __METHOD_DECLS__
#define __METHOD_DECLS__

#include <bits/stdc++.h>
#include "identifier.h"
#include "llvm/IR/Value.h"

class method_decls {
private:
    std::string r_type;
    identifier *m_id;
public:
    llvm::Value* codegen();
    method_decls(std::string, identifier*);
    ~ method_decls();
};

#endif