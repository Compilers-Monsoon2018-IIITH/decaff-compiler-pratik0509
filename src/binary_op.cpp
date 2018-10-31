#include "binary_op.h"
#include "expression.h"

void set_operator(binary_op *b, std::string str) {
    if(str == "*")
        b->op = binary_operator::multiply;
    else if(str == "+")
        b->op = binary_operator::add;
    else if(str == "%")
        b->op = binary_operator::modulo;
    else if(str == "&&")
        b->op = binary_operator::logical_and;
    else if(str == "||")
        b->op = binary_operator::logical_or;
    else if(str == "-")
        b->op = binary_operator::subtract;
    else if(str == "/")
        b->op = binary_operator::divide;
    else if(str == "<")
        b->op = binary_operator::less_than;
    else if(str == ">")
        b->op = binary_operator::greater_than;
    else if(str == "<=")
        b->op = binary_operator::less_than_equals;
    else if(str == ">=")
        b->op = binary_operator::greater_than_equals;
    else if(str == "!=")
        b->op = binary_operator::not_equals;
    else if(str == "==")
        b->op = binary_operator::equals;
    return;
}

binary_op::binary_op(expression *e1, expression *e2, std::string b) {
    #ifdef __TEST
        std::cout << "binary_op created\n";
    #endif
    expr1 = e1;
    expr2 = e2;
    set_operator(this, b);
}
