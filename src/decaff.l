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
K_FOR   "for"
K_IF    "if"
K_ELSE  "else"
CALLOUT "callout"
RETURN  "return"
STR     "\""
CHR     "'"

%%

[ \t]                    ;
\n                       ;
{K_CLASS}                { printf("class ");return KEY_CLASS; }
{K_PROG}                 { printf("Program ");return KEY_PROGRAM; }
{LCB}                    { printf("{ ");return LEFT_CBRACE; }
{LSB}                    { printf("[ ");return LEFT_SBRACE; }
{RCB}                    { printf("} ");return RIGHT_CBRACE; }
{RSB}                    { printf("] ");return RIGHT_SBRACE; }
{COMMA}                  { return O_COMMA; }
{INT}|{BOOL}             { printf(" *TYPE* "); return KEY_TYPE; }
{CALLOUT}                { printf(" *callout* "); return KEY_CALLOUT; }
{LEF}                    { printf("( ");return O_LEF; }
{RIT}                    { printf(") ");return O_RIT; }
{RETURN}                   { printf(" <return> "); return KEY_RETURN;}
{STR}.*{STR}               { printf("<string> ");return STRING; }
{CHR}.{CHR}                 { printf("<character> ");return CHAR_LITERAL; }
{K_IF}                     { printf("if ");return KEY_IF; }
{K_FOR}                     { printf("for "); return KEY_FOR; }
{K_ELSE}                   { printf("else ");return KEY_ELSE; }
{TRUE}|{FALSE}           { printf("return "); return BOOL_LITERAL; }

{SEMICOL}                { printf("Semicolon ");return O_SEMICOLON; }
{DIGIT}+                 { printf(" DIGIT ");return INT_LITERAL; }
{EQUAL}                    { printf(" = "); return EQUAL_OP; }
{ADDEQ}                    { printf(" += ");return ADD_EQUAL_OP; }
{SUBEQ}                    { printf(" -= ");return SUB_EQUAL_OP; }
{ADD}                       { printf(" + ");return BINARY_ADD; }     
{SUB}                       { printf(" - ");return BINARY_SUBTRACT; }     
{MUL}                       { printf(" * ");return BINARY_MULTIPLY; }
{DIV}                       { printf(" / ");return BINARY_DIVISION; }
{MOD}                       { printf(" % ");return BINARY_MOD; }
{OR}                        { return R_OR; }
{AND}                       { return R_AND; }
{EQL}                       { return R_EQUALS; }
{NEQ}                       { return R_NOT_EQUALS; }
{LEQ}                       { return R_LESS_THAN_EQUAL; }
{GEQ}                       { return R_GREATER_THAN_EQUAL; }
{LES}                       { return R_LESS_THAN; }
{GRE}                       { return R_GREATER_THAN; }
{NOT}                       { return UNARY_NOT; }
{ALPHA}{ALNUM}*          { printf("identifiers ");return IDENTIFIER; }

%%