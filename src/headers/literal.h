#ifndef __LITERAL__
#define __LITERAL__

#include <bits/stdc++.h>

typedef union {
    int ival;
    char cval;
    bool bval;
} l_value;

enum class l_type {
    ival, cval, bval
};

class literal {
private:
    l_value v;
    l_type type;
public:
    literal(int val);
    literal(char val);
    literal(bool val);
};

#endif