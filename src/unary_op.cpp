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

llvm::Value* unary_op::codegen() {
    llvm::Value* val = expr->codegen();
    if (expr->get_type() == type::loc)
        val = builder.CreateLoad(val);
    switch(op) {
        case unary_operator::unary_minus:
        return builder.CreateNeg(val, "neg_tmp");
        case unary_operator::unary_plus:
        return val;
        case unary_operator::unary_not:
        return builder.CreateNot(val, "not_tmp");
    }
    return nullptr;
}