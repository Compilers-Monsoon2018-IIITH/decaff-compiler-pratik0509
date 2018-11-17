#ifndef __IDENTIFIER_LIST__
#define __IDENTIFIER_LIST__

#include <bits/stdc++.h>
#include "identifier.h"
#include "codegenerator.h"

class identifier_list {
private:
    std::vector<identifier*> ids;
public:
    void add_identifier(identifier*);
    unsigned int get_size();
    std::string get_name(int);
    bool is_array(int);
    unsigned int get_size(int);
    llvm::Value* codegen();
    identifier_list();
};

#endif