#ifndef __FOR__
#define __FOR__

#include <bits/stdc++.h>
#include "expression.h"
#include "block.h"

class block;

class kfor {
private:
    std::string iter;
    expression *start;
    expression *end;
    block *blk;
public:
    kfor(std::string, expression*, expression*, block*);
};

#endif