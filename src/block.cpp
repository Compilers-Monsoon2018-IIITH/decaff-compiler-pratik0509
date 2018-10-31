#include "block.h"

block::block(executables *e) {
    #ifdef __TEST
        std::cout << "Block created\n";
    #endif
    exec = e;
}

block::~block() {
    if (exec != NULL)
        delete exec;
}