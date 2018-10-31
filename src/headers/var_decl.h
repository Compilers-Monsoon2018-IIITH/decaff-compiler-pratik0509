#ifndef __VAR_DECL__
#define __VAR_DECL__

#include <bits/stdc++.h>
#include "identifier_list.h"

class var_decl {
private:
    std::string f_type;
    identifier_list *id_list;
public:
    void set_field(std::string, identifier_list*);
    var_decl();
    ~ var_decl();
};

#endif