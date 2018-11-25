#include "method_decls.h"


method_decls::method_decls(std::string type, identifier* id, arg_list* arg, block* blk) {
    #ifdef __TEST
        std::cout << "Method Declarations created\n";
    #endif
    m_id = id;
    r_type = type;
    args = arg;
    m_blk = blk;
}

method_decls::~method_decls() {
    if (m_id != NULL)
        delete m_id;
}

llvm::Value* method_decls::codegen() {
    std::vector<llvm::Type*> method_args;
    for(int i = 0; i < args->get_size(); ++i) {
        std::string arg_typ = args->get_type(i);
        std::string arg_name = args->get_name(i);
        if(arg_typ == "int")
            method_args.emplace_back(llvm::Type::getInt32Ty(the_context));
        else if(arg_typ == "char")
            method_args.emplace_back(llvm::Type::getInt8Ty(the_context));
        else if(arg_typ == "bool")
            method_args.emplace_back(llvm::Type::getInt1Ty(the_context));
        else
            return log_error("Unknown type of argument!!");
    }

    llvm::Type* ret_typ;
    if(r_type == "int")
        ret_typ = llvm::Type::getInt32Ty(the_context);
    else if(r_type == "char")
        ret_typ = llvm::Type::getInt8Ty(the_context);
    else if(r_type == "bool")
        ret_typ = llvm::Type::getInt1Ty(the_context);
    else
        return log_error("Unknown return type!!");

    llvm::FunctionType* func_typ = llvm::FunctionType::get(ret_typ, method_args, false);
    llvm::Function *func = llvm::Function::Create(func_typ, llvm::Function::ExternalLinkage,
                                    m_id->get_name(), the_module);
    int idx = 0;
    for(llvm::Function::arg_iterator itr = func->arg_begin(); itr != func->arg_end(); ++itr, ++idx)
        itr->setName(args->get_name(idx));

    llvm::BasicBlock* func_blk = llvm::BasicBlock::Create(the_context, "entrypoint", func);
    builder->SetInsertPoint(func_blk);
    
    idx = 0;
    for(llvm::Function::arg_iterator itr = func->arg_begin(); itr != func->arg_end(); ++itr, ++idx) {
        llvm::AllocaInst *local_arg = create_entry_alloc(func, args->get_name(idx), args->get_type(idx));
        builder->CreateStore(itr, local_arg);
        named_values[args->get_name(idx)] = local_arg;
    }

    llvm::Value* ret_val = m_blk->codegen();
    if(ret_val) {
        builder->CreateRet(ret_val);
        return ret_val;
    }
    func->eraseFromParent();
    return log_error("Cannot create the function!!");
}