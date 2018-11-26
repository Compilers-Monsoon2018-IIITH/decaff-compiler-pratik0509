#include "executables.h"

executables::executables() {
    #ifdef __TEST
        std::cout << "executables created\n";
    #endif
    execs = std::list<std::pair<exec_types, exec_modes>>();
}

void executables::add_executable(var_decl *v) {
    exec_types et;
    et.v_dec = v;
    execs.push_back({et, exec_modes::v_decl});
    return;
}


void executables::add_executable(statement *v) {
    exec_types et;
    et.stmnt = v;
    execs.push_back({et, exec_modes::stmnt});
    return;
}

llvm::Value* executables::codegen(std::map<std::string, llvm::AllocaInst*> &old_vals) {
    llvm::Value* val;
    for(auto itr = execs.begin(); itr != execs.end(); ++itr) {
        switch(itr->second) {
            case exec_modes::v_decl:
            val = itr->first.v_dec->codegen(old_vals);
            break;
            case exec_modes::stmnt:
            val = itr->first.stmnt->codegen();
            break;
        }
        if(!val)
            return nullptr;
    }
    for(auto itr = old_vals.begin(); itr != old_vals.end(); ++itr) {
        if(named_values.find(itr->first) != named_values.end())
            named_values[itr->first] = itr->second;
    }
    return val;
}

bool executables::has_return() {
    for (auto itr = execs.begin(); itr != execs.end(); ++itr) {
        if(itr->second == exec_modes::stmnt && itr->first.stmnt->is_return())
            return true;
    }
    return false;
}