#ifndef __METHOD_DECLS__
#define __METHOD_DECLS__

#include <bits/stdc++.h>
#include "identifier.h"

class method_decls {
private:
    std::string r_type;
    identifier *m_id;
public:
    method_decls(std::string, identifier*);
    ~ method_decls();
};

#endif