#ifndef __IF_ELSE__
#define __IF_ELSE__

#include <bits/stdc++.h>
#include "block.h"

class kelse;
class block;

class kif {
private:
    expression *cond;
    block *blk;
    kelse *els;
public:
    kif(expression*, block*);
    kif(expression*, block*, kelse*);
};

class kelse {
private:
    kif *elif;
    block *blk;
public:
    kelse(kif*, block*);
};

#endif