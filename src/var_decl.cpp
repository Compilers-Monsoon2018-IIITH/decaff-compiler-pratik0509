#include "var_decl.h"

void var_decl::set_field(std::string type, identifier_list *ids) {
    f_type = type;
    id_list = ids;
    #ifdef __TEST
        std::cout << "TYPE:" << f_type << std::endl;
    #endif
    return;
}

var_decl::var_decl() {
    #ifdef __TEST
        std::cout << "Field Declarations created\n";
    #endif
    f_type = "";
    id_list = NULL;
}

var_decl::~ var_decl() {
    if (id_list != NULL)
        delete id_list;
}
