#include "unary_op.h"
#include "expression.h"

unary_op::unary_op(expression *e, std::string b) {
    #ifdef __TEST
        std::cout << "unary_op created\n";
    #endif
    expr = e;
    if (b == "!")
        op = unary_operator::unary_not;
    else if (b == "-")
        op = unary_operator::unary_minus;
    else if (b == "+")
        op = unary_operator::unary_plus;
}
