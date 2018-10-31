#include "assignment.h"

assignment::assignment(location *l, std::string s, expression *e) {
    #ifdef __TEST
        std::cout << "Assignment created\n";
    #endif
    loc = l;
    op = s;
    expr = e;
}