#ifndef __LOCATION__
#define __LOCATION__

#include <bits/stdc++.h>

typedef union {
    int ival;
    char cval;
    bool bval;
} value3;

enum class type3 {
    ival, cval, bval
};

class location {
private:
    value3 v;
    type3 loc_type;
public:
    location();
    location(int val);
    location(char val);
    location(bool val);
};

#endif