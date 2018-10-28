#ifndef __NODE__
#define __NODE__

#include "program.h"
#include "global_decl.h"
#include "field_decls.h"
#include "method_decls.h"
#include "identifier_list.h"

union node {
    int numb;
    bool bval;
    char *str_value;
    class program *prog;
    class global_decl *g_decl;
    class field_decls *f_decls;
    class method_decls *m_decls;
    class identifier_list *id_list;
    node() = default;

    ~ node() = default;
};

typedef union node YYSTYPE;

#endif