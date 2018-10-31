#ifndef __STATEMENT__
#define __STATEMENT__
#include <bits/stdc++.h>
#include "statement.h"
#include "block.h"
#include "assignment.h"
#include "method_call.h"
#include "for.h"
#include "if_else.h"

class block;
class kfor;
class kif;

typedef union {
    block *blk;
    assignment *asg;
    method_call *m_call;
    expression *ret;
    int jump;
    kfor *loop;
    kif *cond;
} statement_type;

enum class statement_mode {
    blk, asg, m_call, ret, brek, cont, loop, cond
};

class statement {
private:
    std::list<std::pair<statement_type, statement_mode>> stmnts;
public:
    statement();
    void add_statement(block*);
    void add_statement(assignment*);
    void add_statement(method_call*);
    void add_statement(expression*);
    void add_statement(kfor*);
    void add_statement(kif*);
    void add_statement(char);
};

#endif