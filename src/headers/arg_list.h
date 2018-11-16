#ifndef __ARG_LIST__
#define __ARG_LIST__

#include <bits/stdc++.h>
#include "identifier.h"
#include "codegenerator.h"


class arg_list {
private:
    std::vector<std::pair<std::string, identifier*>> args;
public:
    llvm::Value* codegen();
    std::string get_type(int);
    std::string get_name(int);
    int get_size();
    void add_identifier(std::string, identifier*);
    arg_list();
};
#endif