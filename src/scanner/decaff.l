%{
    #include <stdio.h>
    #include <stdbool.h>
    #include <string.h>
    #include "decaff.tab.h"
%}

DIGIT   [0-9]
ALPHA   [a-zA-Z]
ALNUM   [0-9a-zA-Z]
TRUE    "true"
FALSE   "false"
EQUAL   "="
ADDEQ   "+="
SUBEQ   "-="
COMMA   ","
ADD     "+"
SUB     "-"
MUL     "*"
DIV     "/"
MOD     "%"
LEF     "("
RIT     ")"
OR      "||"
AND     "&&"
NOT     "!"
XOR     "^"
LEQ     "<="
GEQ     ">="
EQL     "=="
NEQ     "!="
LES     "<"
GRE     ">"
BOR     "|"
BND     "&"
LCB     "{"
LSB     "["
RCB     "}"
RSB     "]"
K_CLASS "class"
K_PROG  "Program"
INT     "int"
BOOL    "bool"
SEMICOL ";"
K_IF    "if"
K_ELSE  "else"
CALLOUT "callout"
STR     "\""

%%

[ \t]                    ;
\n                       { printf("NEWLINE\n "); return T_NEWLINE; }
{K_CLASS}                { printf("class ");return KEY_CLASS; }
{K_PROG}                 { printf("Program ");return KEY_PROGRAM; }
{LCB}                    { printf("{ ");return LEFT_CBRACE; }
{LSB}                    { printf("[ ");return LEFT_SBRACE; }
{RCB}                    { printf("} ");return RIGHT_CBRACE; }
{RSB}                    { printf("] ");return RIGHT_SBRACE; }
{COMMA}                  { return O_COMMA; }
{INT}|{BOOL}             { return KEY_TYPE; }
{CALLOUT}                { return KEY_CALLOUT; }
{LEF}                    { printf("( ");return O_LEF; }
{RIT}                    { printf(") ");return O_RIT; }
{ALPHA}{ALNUM}*          { printf("identifiers ");return IDENTIFIER; }
{SEMICOL}                { printf("Semicolon ");return O_SEMICOLON; }
{DIGIT}+                 { return INT_LITERAL; }
{TRUE}|{FALSE}           { return BOOL_LITERAL; }
{EQUAL}                    { return EQUAL_OP; }
{ADDEQ}                    { return ADD_EQUAL_OP; }
{SUBEQ}                    { return SUB_EQUAL_OP; }
{K_IF}                     { return KEY_IF; }
{K_ELSE}                   { return KEY_ELSE; }
{STR}.*{STR}               { return STRING; }
{ADD}                       { return BINARY_ADD; }     
{SUB}                       { return BINARY_SUBTRACT; }     
{MUL}                       { return BINARY_MULTIPLY; }
{DIV}                       { return BINARY_DIVISION; }
{MOD}                       { return BINARY_MOD; }
{OR}                        { return R_OR; }
{AND}                       { return R_AND; }
{EQL}                       { return R_EQUALS; }
{NEQ}                       { return R_NOT_EQUALS; }
{LEQ}                       { return R_LESS_THAN_EQUAL; }
{GEQ}                       { return R_GREATER_THAN_EQUAL; }
{LES}                       { return R_LESS_THAN; }
{GRE}                       { return R_GREATER_THAN; }
{NOT}                       { return UNARY_NOT; }

%%