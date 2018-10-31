#ifndef __ARG_LIST__
#define __ARG_LIST__

#include <bits/stdc++.h>
#include "identifier.h"

class arg_list {
private:
    std::list<std::pair<std::string, identifier*>> args;
public:
    void add_identifier(std::string, identifier*);
    arg_list();
};
#endif