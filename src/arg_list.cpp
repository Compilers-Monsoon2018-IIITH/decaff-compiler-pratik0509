#include "arg_list.h"

void arg_list::add_identifier(std::string type, identifier *id) {
    #ifdef __TEST
        std::cout << "identifier added\n";
    #endif
    args.push_back({type, id});
    return;
}

arg_list::arg_list() {
    #ifdef __TEST
        std::cout << "arg list created\n";
    #endif
    args = std::list<std::pair<std::string, identifier*>>();
}