#ifndef __NODE__
#define __NODE__

#include "program.h"
#include "global_decl.h"
#include "field_decls.h"
#include "method_decls.h"
#include "identifier_list.h"
#include "block.h"
#include "executables.h"
#include "var_decl.h"
#include "expression.h"
#include "literal.h"
#include "location.h"
#include "method_call.h"

union node {
    int ival;
    char cval;
    bool bval;
    char *str_value;
    class program *prog;
    class global_decl *g_decl;
    class field_decls *f_decls;
    class method_decls *m_decls;
    class identifier_list *id_list;
    class block *blk;
    class executables *exe;
    class var_decl *v_decl;
    class expression *expr;
    class literal *lit;
    class location *loc;
    class method_call *m_call;
    node() = default;

    ~ node() = default;
};

typedef union node YYSTYPE;

#endif