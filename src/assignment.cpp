#include "assignment.h"

assignment::assignment(location *l, std::string s, expression *e) {
    #ifdef __TEST
        std::cout << "Assignment created\n";
    #endif
    loc = l;
    op = s;
    expr = e;
}

// llvm::Value* assignment::codegen() {
//     llvm::Value* lval = named_values[loc->get_name()];
//     if(!lval)
//         lval = the_module->getGlobalVariable(loc->get_name());
//     if(!lval)
//         return log_error("Unknown Variable Symbol Found!!");

//     llvm::Value* val = expr->codegen();
//     if (expr->get_type() == type::loc)
//         val = builder->CreateLoad(val);
    
//     if(!val)
//         return log_error("Unknown rvalue!!");
    
//     llvm::Value* lloc = loc->codegen();
//     lval = builder->CreateLoad(lloc);
//     // lval = builder->CreateLoad(lval);

//     if (op == "+=")
//         val = builder->CreateAdd(lval, val, "add_eql_tmp");
//     else if (op == "-=")
//         val = builder->CreateSub(lval, val, "sub_eql_tmp");
//     return builder->CreateStore(val, named_values[loc->get_name()]);
// }

llvm::Value* assignment::codegen() {
    llvm::Value* val = expr->codegen();
    if (expr->get_type() == type::loc)
        val = builder->CreateLoad(val);
    
    if(!val)
        return log_error("Unknown rvalue!!");
    if(named_values.find(loc->get_name()) == named_values.end()) {
        log_error("Inside Global Values!!");
        llvm::GlobalVariable *gvar = the_module->getGlobalVariable(loc->get_name());
        if(!gvar)
            return log_error("Unknown Variable Symbol Found!!");
        builder->CreateStore(val, gvar);
        if (op == "+=")
            val = builder->CreateAdd(gvar, val, "add_eql_tmp");
        else if (op == "-=")
            val = builder->CreateSub(gvar, val, "sub_eql_tmp");
        return builder->CreateStore(val, gvar);
    }

    llvm::AllocaInst *lvar = named_values[loc->get_name()];
    llvm::Value *lval = builder->CreateLoad(lvar);
    if(!lvar || !lval)
        return log_error("Unknown Variable Symbol Found!!");

    if (op == "+=")
        val = builder->CreateAdd(val, lval, "add_eql_tmp");
    else if (op == "-=")
        val = builder->CreateSub(lvar, val, "sub_eql_tmp");

    return builder->CreateStore(val, lvar);
}