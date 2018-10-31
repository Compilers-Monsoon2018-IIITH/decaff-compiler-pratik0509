#ifndef __EXPRESSION__
#define __EXPRESSION__

#include <bits/stdc++.h>
#include "location.h"
#include "method_call.h"
#include "literal.h"


typedef union {
    location *loc;
    method_call *mcall;
    literal *lit;
} value;

enum class type {
    loc, mcall, lit
};

class expression {
private:
    value val;
    type e_type;
public:
    expression(location *val);
    expression(method_call *val);
    expression(literal *val);
    ~ expression();
};

#endif