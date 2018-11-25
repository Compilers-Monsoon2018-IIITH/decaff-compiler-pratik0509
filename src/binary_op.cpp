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

llvm::Value* binary_op::codegen() {
    llvm::Value* left_op = expr1->codegen();
    llvm::Value* right_op = expr2->codegen();
    if (!left_op || !right_op)
        return nullptr;
    switch(op) {
        case binary_operator::multiply:
        return builder->CreateMul(left_op, right_op, "mul_tmp");
        break;
        case binary_operator::add:
        return builder->CreateAdd(left_op, right_op, "add_tmp");
        break;
        case binary_operator::subtract:
        return builder->CreateSub(left_op, right_op, "sub_tmp");
        break;
        case binary_operator::divide:
        return builder->CreateSDiv(left_op, right_op, "div_tmp");
        break;
        case binary_operator::modulo:
        return builder->CreateSRem(left_op, right_op, "mod_tmp");
        break;
        case binary_operator::logical_and:
        return builder->CreateAnd(left_op, right_op, "lad_tmp");
        break;
        case binary_operator::logical_or:
        return builder->CreateOr(left_op, right_op, "lor_tmp");
        break;
        case binary_operator::less_than:
        return builder->CreateICmpSLT(left_op, right_op, "les_tmp");
        break;
        case binary_operator::greater_than:
        return builder->CreateICmpSGT(left_op, right_op, "gre_tmp");
        break;
        case binary_operator::less_than_equals:
        return builder->CreateICmpSLE(left_op, right_op, "leq_tmp");
        break;
        case binary_operator::greater_than_equals:
        return builder->CreateICmpSGE(left_op, right_op, "geq_tmp");
        break;
        case binary_operator::equals:
        return builder->CreateICmpEQ(left_op, right_op, "eql_tmp");
        break;
        case binary_operator::not_equals:
        return builder->CreateICmpNE(left_op, right_op, "neq_tmp");
        break;
        default:
        return log_error("Operator Not Supplied!!");
    }
}