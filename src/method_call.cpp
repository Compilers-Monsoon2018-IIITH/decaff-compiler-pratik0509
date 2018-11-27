#include "method_call.h"

method_call::method_call() {
    #ifdef __TEST
        std::cout << "method_call created\n";
    #endif
}

void method_call::set_method_call(location *l, param_list *p) {
    loc = l;
    p_list = p;
    return;
}

llvm::Value* callout_codegen(method_call* mcall) {
    std::string c_func = mcall->p_list->get_string_argument(0);
    std::cerr << mcall->loc->get_name() ;
    log_error(c_func + "---");
    int idx = 0;
    llvm::Value* arg_val = nullptr;
    std::vector<llvm::Type*> arg_types;
    std::vector<llvm::Value*> arg_vals;
    for(idx = 1; idx < mcall->p_list->get_num_args(); ++idx) {
        std::cerr << idx << std::endl;
        if(mcall->p_list->is_string(idx)){
            log_error(mcall->p_list->get_string_argument(idx) + "--+--");
            arg_val = builder->CreateGlobalStringPtr(mcall->p_list->get_string_argument(idx));
        } else {
            arg_val = mcall->p_list->codegen(idx);
            if(mcall->p_list->is_loc(idx))
                arg_val = builder->CreateLoad(arg_val);

        }
        if(!arg_val)
            return log_error("Unknown Argument to callout!!");
        arg_vals.push_back(arg_val);
        arg_types.push_back(arg_val->getType());
    }
    llvm::FunctionType* func_type = llvm::FunctionType::get(llvm::Type::getInt32Ty(the_context), arg_types, false);
    llvm::Constant* func = the_module->getOrInsertFunction(c_func, func_type);
    if(!func)
        return log_error("Unknown Function in callout");
    llvm::Value* val = builder->CreateCall(func, arg_vals);
    return val;
}

llvm::Value* method_call::codegen() {
    if(loc->get_name() == CALLOUT_STR) {
        return callout_codegen(this);
    }
    llvm::Function* calleef = the_module->getFunction(loc->get_name());
    if (!calleef)
        return log_error("Unknown Function Referenced!!");

    if (calleef->arg_size() != p_list->get_num_args())
        return log_error("Incorrect Number of Arguments Passed!!");
    
    std::vector <llvm::Value*> argsv;
    for (unsigned int i = 0; i < p_list->get_num_args(); ++i) {
        llvm::Value* val = p_list->codegen(i);
        if(!val)
            return nullptr;
        if(p_list->is_loc(i))
            val = builder->CreateLoad(val);
        if(!val)
            return nullptr;
        argsv.push_back(val);
    }
    return builder->CreateCall(calleef, argsv, "cal_tmp");
}