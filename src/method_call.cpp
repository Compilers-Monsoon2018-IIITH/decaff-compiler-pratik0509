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

llvm::Value* method_call::codegen() {
    llvm::Function* calleef = the_module->getFunction(loc->get_name());
    if (!calleef)
        return log_error("Unknown Function Referenced!!");

    if (calleef->arg_size() != p_list->get_num_args())
        return log_error("Incorrect Number of Arguments Passed!!");
    
    std::vector <llvm::Value*> argsv;
    for (unsigned int i = 0; i < p_list->get_num_args(); ++i) {
        argsv.push_back(p_list->codegen(i));
        if(!argsv.back())
         return nullptr;
    }
    return builder.CreateCall(calleef, argsv, "cal_tmp");
}