#include "for.h"

kfor::kfor(std::string i, expression *e1, expression *e2, block *b) {
    #ifdef __TEST
        std::cout << "for created" << std::endl;
    #endif
    iter = i;
    start = e1;
    end = e2;
    blk = b;
}

bool kfor::has_return() {
    return blk->has_return();
}