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
    llvm::Value* lval = named_values[loc->get_name()];
    if(!lval)
        lval = the_module->getGlobalVariable(loc->get_name());
    if(!lval)
        return log_error("Unknown Variable Symbol Found!!");

    llvm::Value* val = expr->codegen();
    if (expr->get_type() == type::loc)
        val = builder->CreateLoad(val);
    
    if(!val)
        return log_error("Unknown rvalue!!");
    
    llvm::Value* lloc = loc->codegen();
    lval = builder->CreateLoad(lloc);
    // lval = builder->CreateLoad(lval);

    if (op == "+=")
        val = builder->CreateAdd(lval, val, "add_eql_tmp");
    else if (op == "-=")
        val = builder->CreateSub(lval, val, "sub_eql_tmp");
    return builder->CreateStore(val, lloc);
}
