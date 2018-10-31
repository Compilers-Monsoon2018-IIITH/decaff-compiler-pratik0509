#include "identifier_list.h"

void identifier_list::add_identifier(identifier *id) {
    ids[id->get_name()] = id;
    return;
}

identifier_list::identifier_list() {
    #ifdef __TEST
        std::cout << "Identifier List created\n";
    #endif
    ids = std::map<std::string, identifier*>();
}

