#include "method_decls.h"


method_decls::method_decls(std::string type, identifier* id, arg_list* arg) {
    #ifdef __TEST
        std::cout << "Method Declarations created\n";
    #endif
    m_id = id;
    r_type = type;
    args = arg;
}

method_decls::~method_decls() {
    if (m_id != NULL)
        delete m_id;
}

llvm::Value* method_decls::codegen() {
    llvm::Function *the_func = the_module->getFunction(m_id->get_name());

    if (!the_func) {
        std::vector<llvm::Type*> argvs;
        for (int i = 0; i < args->get_size(); ++i) {
            if(args->get_type(i) == "int")
                argvs.push_back(llvm::Type::getInt32Ty(the_context));
            else if (args->get_type(i) == "char")
                argvs.push_back(llvm::Type::getInt8Ty(the_context));
            else if (args->get_type(i) == "bool")
                argvs.push_back(llvm::Type::getInt1Ty(the_context));
            else
                log_error("Invalid Argument Type Found!!");
        }
        llvm::FunctionType* ft = nullptr;
        if(r_type == "int")
            ft = llvm::FunctionType::get(llvm::Type::getInt32Ty(the_context), argvs, false);
        else if (r_type == "char")
            ft = llvm::FunctionType::get(llvm::Type::getInt8Ty(the_context), argvs, false);
        else if (r_type == "bool")
            ft = llvm::FunctionType::get(llvm::Type::getInt1Ty(the_context), argvs, false);
        else
            log_error("Invalid Return Type Found!!");
        the_func = llvm::Function::Create(ft, llvm::Function::ExternalLinkage, m_id->get_name(), the_module);
        unsigned idx = 0;
        for (auto &arg: the_func->args())
            arg.setName(args->get_name(idx++));
    }
    
    // **TODO** Basic Blocks and all
    return nullptr;
}