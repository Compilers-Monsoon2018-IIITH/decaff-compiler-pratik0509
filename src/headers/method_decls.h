#ifndef __METHOD_DECLS__
#define __METHOD_DECLS__

#include <bits/stdc++.h>

class method_decls {
private:
    int *m_decl;
public:
    void add_int(int *decl);
    method_decls();
    ~ method_decls();
};

#endif