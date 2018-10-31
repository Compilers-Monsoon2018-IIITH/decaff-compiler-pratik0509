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