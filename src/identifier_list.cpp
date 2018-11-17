#include "identifier_list.h"

void identifier_list::add_identifier(identifier *id) {
    #ifdef __TEST
        std::cout << "Adding identifier" << std::endl;
    #endif
    ids.emplace_back(id);
    return;
}

identifier_list::identifier_list() {
    #ifdef __TEST
        std::cout << "Identifier List created\n";
    #endif
    ids = std::vector<identifier*>();
}

bool identifier_list::is_array(int i) {
    return ids[i]->get_size() != -1;
}

unsigned identifier_list::get_size() {
    return ids.size();
}

unsigned identifier_list::get_size(int i) {
    return (unsigned)ids[i]->get_size();
}

std::string identifier_list::get_name(int i) {
    return ids[i]->get_name();
}