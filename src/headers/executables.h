#ifndef __EXECUTABLES__
#define __EXECUTABLES__

#include <bits/stdc++.h>
#include "var_decl.h"

typedef union {
    var_decl *v_dec;
} exec_types; 

enum class exec_modes {
    v_decl, stmnt
};

class executables {
private:
    std::list<std::pair<exec_types, exec_modes>> execs;
public:
    executables();
    void add_executable(var_decl*);
};

#endif