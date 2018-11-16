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
    args = std::vector<std::pair<std::string, identifier*>>();
}

std::string arg_list::get_type(int i) {
    if (i >= args.size()) {
        log_error("Invalid Index arg_list!!");
        exit(0);
    }
    return args[i].first;    
}

std::string arg_list::get_name(int i) {
    if (i >= args.size()) {
        log_error("Invalid Index arg_list!!");
        exit(0);
    }
    return args[i].second->get_name();
}

int arg_list::get_size() {
    return args.size();
}