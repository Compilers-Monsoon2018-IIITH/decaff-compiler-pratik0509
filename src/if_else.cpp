#include "if_else.h"

kif::kif(expression *e, block *b) {
    #ifdef __TEST
        std::cout << "IF created\n";
    #endif
    cond = e;
    blk = b;
}

kif::kif(expression *e, block *b, kelse* k) {
    #ifdef __TEST
        std::cout << "IF created\n";
    #endif
    cond = e;
    blk = b;
    els = k;
}

kelse::kelse(kif *i, block *b) {
    #ifdef __TEST
        std::cout << "ELSE created\n";
    #endif
    elif = i;
    blk = b;
}