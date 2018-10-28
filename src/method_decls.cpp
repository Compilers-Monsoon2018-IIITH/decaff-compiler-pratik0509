#include "method_decls.h"

void method_decls::add_int(int *decl) {
    if (m_decl != NULL)
        delete m_decl;
    m_decl = decl;
    return;
}

method_decls::method_decls() {
    #ifdef __TEST
        std::cout << "Method Declarations created\n";
    #endif
    m_decl = NULL;
}

method_decls::~ method_decls() {
    if (m_decl != NULL)
        delete m_decl;
}
