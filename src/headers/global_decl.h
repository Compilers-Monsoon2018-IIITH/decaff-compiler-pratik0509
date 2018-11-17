#ifndef __GLOBAL_DECL__
#define __GLOBAL_DECL__

#include <bits/stdc++.h>
#include "field_decls.h"
#include "method_decls.h"
#include "codegenerator.h"

class global_decl {
private:
    std::list<field_decls*> f_decls;
    std::list<method_decls*> m_decls;
public:
    void add_field(field_decls *decl);
    llvm::Value* codegen();
    void add_method(method_decls *decl);
    global_decl();
};

#endif