#include "field_decls.h"

void field_decls::set_field(std::string type, identifier_list *ids) {
    f_type = type;
    id_list = ids;
    #ifdef __TEST
        std::cout << "TYPE:" << f_type << std::endl;
    #endif
    return;
}

field_decls::field_decls() {
    #ifdef __TEST
        std::cout << "Field Declarations created\n";
    #endif
    f_type = "";
    id_list = NULL;
}

field_decls::~ field_decls() {
    if (id_list != NULL)
        delete id_list;
}

llvm::Value* field_decls::codegen() {
    llvm::Type* typ = nullptr;

    if(f_type == "int")
        typ = llvm::Type::getInt32Ty(the_context);
    else if(f_type == "char")
        typ = llvm::Type::getInt8Ty(the_context);
    else if(f_type == "bool")
        typ = llvm::Type::getInt1Ty(the_context);
    if(!typ)
        return log_error("Unknown Type!!");
    
    for (unsigned i = 0; i < id_list->get_size(); ++i) {
        if (id_list->is_array(i)) {
            llvm::ArrayType *arr_type = llvm::ArrayType::get(typ, id_list->get_size(i));
            llvm::GlobalVariable *gv = new llvm::GlobalVariable(*the_module, arr_type, false,
                                                    llvm::GlobalValue::ExternalLinkage, nullptr,
                                                    id_list->get_name(i));
            gv->setInitializer(llvm::Constant::getNullValue(typ));
        } else {
            llvm::GlobalVariable *gv = new llvm::GlobalVariable(*the_module, typ, false,
                                                    llvm::GlobalValue::ExternalLinkage, nullptr,
                                                    id_list->get_name(i));
            gv->setInitializer(llvm::Constant::getNullValue(typ));
        }
    }
    llvm::Value* val = llvm::ConstantInt::get(the_context, llvm::APInt(INT_WIDTH, 0));
    return val;
}