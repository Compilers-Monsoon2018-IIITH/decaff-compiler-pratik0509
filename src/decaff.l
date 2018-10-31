%{
    #include <bits/stdc++.h>
    #include "node.h"
    #include "decaff.tab.hpp"
    #define YY_DECL extern "C" int yylex()
    using namespace std;
    extern union node yylval;
    int line_no = 1;
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
K_BREAK  "break"
K_CONT  "continue"
CALLOUT "callout"
RETURN  "return"
STR     "\""
CHR     "'"

%%

[ \t]                    ;
\n                       { line_no++; }
{K_CLASS}                { return KEY_CLASS; }
{K_PROG}                 { return KEY_PROGRAM; }
{LCB}                    { return LEFT_CBRACE; }
{LSB}                    { return LEFT_SBRACE; }
{RCB}                    { return RIGHT_CBRACE; }
{RSB}                    { return RIGHT_SBRACE; }
{COMMA}                  { return O_COMMA; }
{INT}|{BOOL}             { yylval.str_value = strdup(yytext); return KEY_TYPE; }
{CALLOUT}                { return KEY_CALLOUT; }
{K_BREAK}                { return KEY_BREAK; }
{K_CONT}                 { return KEY_CONTINUE; }
{LEF}                    { return O_LEF; }
{RIT}                    { return O_RIT; }
{RETURN}                 { return KEY_RETURN;}
{STR}.*{STR}             { return STRING; }
{CHR}.{CHR}              { yylval.cval = yytext[1]; return CHAR_LITERAL; }
{K_IF}                   { return KEY_IF; }
{K_FOR}                  { return KEY_FOR; }
{K_ELSE}                 { return KEY_ELSE; }
{TRUE}|{FALSE}           { yylval.bval = ((strcmp(yytext, "true") == 0) ? true : false); return BOOL_LITERAL; }

{SEMICOL}                { return O_SEMICOLON; }
{DIGIT}+                 { yylval.ival = atoi(yytext); return INT_LITERAL; }
{EQUAL}                  { yylval.str_value = strdup(yytext); return EQUAL_OP; }
{ADDEQ}                  { yylval.str_value = strdup(yytext); return ADD_EQUAL_OP; }
{SUBEQ}                  { yylval.str_value = strdup(yytext); return SUB_EQUAL_OP; }
{ADD}                    { yylval.str_value = strdup(yytext); return BINARY_ADD; }     
{SUB}                    { yylval.str_value = strdup(yytext); return BINARY_SUBTRACT; }     
{MUL}                    { yylval.str_value = strdup(yytext); return BINARY_MULTIPLY; }
{DIV}                    { yylval.str_value = strdup(yytext); return BINARY_DIVISION; }
{MOD}                    { yylval.str_value = strdup(yytext); return BINARY_MOD; }
{OR}                     { yylval.str_value = strdup(yytext); return R_OR; }
{AND}                    { yylval.str_value = strdup(yytext); return R_AND; }
{EQL}                    { yylval.str_value = strdup(yytext); return R_EQUALS; }
{NEQ}                    { yylval.str_value = strdup(yytext); return R_NOT_EQUALS; }
{LEQ}                    { yylval.str_value = strdup(yytext); return R_LESS_THAN_EQUAL; }
{GEQ}                    { yylval.str_value = strdup(yytext); return R_GREATER_THAN_EQUAL; }
{LES}                    { yylval.str_value = strdup(yytext); return R_LESS_THAN; }
{GRE}                    { yylval.str_value = strdup(yytext); return R_GREATER_THAN; }
{NOT}                    { yylval.str_value = strdup(yytext); return UNARY_NOT; }
{ALPHA}{ALNUM}*          { yylval.str_value = strdup(yytext); return IDENTIFIER; }

%%