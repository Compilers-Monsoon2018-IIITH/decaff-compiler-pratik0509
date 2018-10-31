#ifndef __STATEMENT__
#define __STATEMENT__
#include <bits/stdc++.h>
#include "statement.h"
#include "block.h"
#include "assignment.h"

class block;

typedef union {
    block *blk;
    assignment *asg;
} statement_type;

enum class statement_mode {
    blk, asg
};

class statement {
private:
    std::list<std::pair<statement_type, statement_mode>> stmnts;
public:
    statement();
    void add_statement(block*);
    void add_statement(assignment*);
};

#endif