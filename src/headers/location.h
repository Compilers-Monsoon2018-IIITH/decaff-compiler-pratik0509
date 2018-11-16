#ifndef __LOCATION__
#define __LOCATION__

#include <bits/stdc++.h>
#include "expression.h"
#include "codegenerator.h"

class expression;

enum class location_type {
    scalar, vector
};

class location {
private:
    location_type loc_type;
    std::string name;
    expression *idx;
public:
    llvm::Value* codegen();
    std::string get_name();
    location();
    location(std::string);
    location(std::string, expression*);
};

#endif