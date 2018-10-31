#include "method_decls.h"


method_decls::method_decls(std::string type, identifier* id) {
    #ifdef __TEST
        std::cout << "Method Declarations created\n";
    #endif
    m_id = id;
    r_type = type;
    return;
}

method_decls::~method_decls() {
    if (m_id != NULL)
        delete m_id;
}