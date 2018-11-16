#include "location.h"

location::location() {
    #ifdef __TEST
        std::cout << "location created\n";
    #endif
}

location::location(std::string val) {
    #ifdef __TEST
        std::cout << "location created\n";
    #endif
    name = val;
    loc_type = location_type::scalar;
    idx = NULL;
}

location::location(std::string val, expression *e) {
    #ifdef __TEST
        std::cout << "location created\n";
    #endif
    name = val;
    loc_type = location_type::vector;
    idx = e;
}

llvm::Value* location::codegen() {
    llvm::Value* val = named_values[name];
    if (!val)
        return log_error("Location Not Declared!!");
    switch(loc_type) {
        case location_type::scalar:
        return val;
        case location_type::vector:
        return nullptr;
        default:
        return log_error("Unknown Location Type!!");
    }
}

std::string location::get_name() {
    return name;
}