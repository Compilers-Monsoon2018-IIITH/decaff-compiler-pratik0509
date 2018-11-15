#include "identifier.h"

std::string identifier::get_name() {
    return name;
}

identifier::identifier(std::string id) {
    #ifdef __TEST
        std::cout << "Identifier created\n";
    #endif
    name = id;
}

llvm::Value* identifier::codegen() {
    llvm::Value* val = named_values[name];
    if (!val)
        log_error("Unknown Variable Name : " + name);
    return val;
}