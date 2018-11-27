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
    if(!val)
        val = the_module->getNamedGlobal(name);
    if(!val)
        return log_error("Location Not Declared!!" + name);
    std::vector<llvm::Value*> array_idx;
    llvm::Value* index;
    switch(loc_type) {
        case location_type::scalar:
        return val;
        case location_type::vector:
        if(!idx)
            return log_error("Index Value Not Present!!");
        index = idx->codegen();
        if (idx->get_type() == type::loc) {
            index = builder->CreateLoad(index);
        }
        if(!index)
            return log_error("Invalid Index Access!!");
        array_idx.emplace_back(builder->getInt32(0));
        array_idx.emplace_back(index);
        return builder->CreateGEP(val, array_idx, name + "_idx");
        break;
        default:
        return log_error("Unknown Location Type!!");
    }
}

std::string location::get_name() {
    return name;
}