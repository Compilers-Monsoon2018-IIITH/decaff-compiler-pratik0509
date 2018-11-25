#include "var_decl.h"

void var_decl::set_field(std::string type, identifier_list *ids) {
    v_type = type;
    id_list = ids;
    #ifdef __TEST
        std::cout << "TYPE:" << v_type << std::endl;
    #endif
    return;
}

var_decl::var_decl() {
    #ifdef __TEST
        std::cout << "Variable Declarations created\n";
    #endif
    v_type = "";
    id_list = NULL;
}

var_decl::~ var_decl() {
    if (id_list != NULL)
        delete id_list;
}

llvm::Value* var_decl::codegen(std::map<std::string, llvm::AllocaInst*> &old_vals) {
    llvm::Function* the_func = builder->GetInsertBlock()->getParent();
    for(int i = 0; i < id_list->get_size(); ++i) {
        llvm::Value* init = nullptr;
        llvm::AllocaInst *alloc = nullptr;
        if (v_type == "int") {
            init = llvm::ConstantInt::get(the_context, llvm::APInt(INT_WIDTH, SUCCESS));
            alloc = create_entry_alloc(the_func, id_list->get_name(i), v_type);
        } else if (v_type == "char") {
            init = llvm::ConstantInt::get(the_context, llvm::APInt(CHAR_WIDTH, SUCCESS));
            alloc = create_entry_alloc(the_func, id_list->get_name(i), v_type);
        } if (v_type == "bool") {
            init = llvm::ConstantInt::get(the_context, llvm::APInt(BOOL_WIDTH, SUCCESS));
            alloc = create_entry_alloc(the_func, id_list->get_name(i), v_type);
        }
        builder->CreateStore(init, alloc);
        old_vals[id_list->get_name(i)] = named_values[id_list->get_name(i)];
        named_values[id_list->get_name(i)] = alloc;
    }
    llvm::Value* val = llvm::ConstantInt::get(the_context, llvm::APInt(INT_WIDTH, SUCCESS));
    return val;
}