#include "identifier.h"

std::string identifier::get_name() {
    return name;
}

identifier::identifier(std::string id) {
    #ifdef __TEST
        std::cout << "Identifier created\n";
    #endif
    name = id;
}