#ifndef __METHOD_CALL__
#define __METHOD_CALL__

#include <bits/stdc++.h>

typedef union {
    int ival;
    char cval;
    bool bval;
} value2;

enum class type2 {
    ival, cval, bval
};

class method_call {
private:
    value2 v;
    type2 l_type;
public:
    method_call();
    method_call(int val);
    method_call(char val);
    method_call(bool val);
};

#endif