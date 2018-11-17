#include "assignment.h"

assignment::assignment(location *l, std::string s, expression *e) {
    #ifdef __TEST
        std::cout << "Assignment created\n";
    #endif
    loc = l;
    op = s;
    expr = e;
}

llvm::Value* assignment::codegen() {
    llvm::Value* val = named_values[loc->get_name()];
    if(val == nullptr)
        val = the_module->getGlobalVariable(loc->get_name());
    if(val == nullptr)
        return log_error("Unknown Variable Symbol Found!!");
    
}