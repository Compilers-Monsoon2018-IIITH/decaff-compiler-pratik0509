#include "identifier.h"

std::string identifier::get_name() {
    return name;
}

identifier::identifier(std::string id) {
    #ifdef __TEST
        std::cout << "Identifier created\n";
    #endif
    name = id;
    arr_sz = -1;
}

identifier::identifier(std::string id, int sz) {
    #ifdef __TEST
        std::cout << "Identifier created\n";
    #endif
    name = id;
    arr_sz = sz;
}

llvm::Value* identifier::codegen() {
    llvm::Value* val = named_values[name];
    if (!val)
        log_error("Unknown Variable Name : " + name);
    return val;
}

int identifier::get_size() {
    return arr_sz;
}