#include "identifier_list.h"

identifier_list::identifier_list() {
    decl = NULL;
}

identifier_list::~identifier_list() {
    if (decl != NULL)
        delete decl;
}
