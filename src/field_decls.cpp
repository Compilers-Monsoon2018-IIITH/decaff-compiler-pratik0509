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
