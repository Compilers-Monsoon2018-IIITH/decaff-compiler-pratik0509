#ifndef __EXECUTABLES__
#define __EXECUTABLES__

#include <bits/stdc++.h>
#include "var_decl.h"
#include "statement.h"
#include "codegenerator.h"

class statement;

typedef union {
    var_decl *v_dec;
    statement *stmnt;
} exec_types; 

enum class exec_modes {
    v_decl, stmnt
};

class executables {
private:
    std::list<std::pair<exec_types, exec_modes>> execs;
public:
    executables();
    llvm::Value* codegen(std::map<std::string, llvm::AllocaInst*> &);
    void add_executable(var_decl*);
    void add_executable(statement*);
};

#endif