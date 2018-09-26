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

%%

[ \t]                    ;
\n                       { return T_NEWLINE; }
{DIGIT}+                 { yylval.ival = atoi(yytext); return T_INTG; }
{DIGIT}+\.{DIGIT}*       { yylval.fval = atof(yytext); return T_FLOT; }
{TRUE}|{FALSE}           { yylval.bval = ((strcmp(yytext, "true") == 0) ? 1 : 0); return T_BOOL; }
{ADD}                    { return O_ADD; }
{SUB}                    { return O_SUB; }
{MUL}                    { return O_MUL; }
{DIV}                    { return O_DIV; }
{MOD}                    { return O_MOD; }
{LEF}                    { return O_LEF; }
{RIT}                    { return O_RIT; }
{OR}                     { return O_OR; }
{BOR}                     { return O_BOR; }
{AND}                    { return O_AND; }
{BND}                    { return O_BND; }
{XOR}                    { return O_XOR; }
{NOT}                    { return O_NOT; }
{LEQ}                    { return O_LEQ; }
{GEQ}                    { return O_GEQ; }
{EQL}                    { return O_EQL; }
{NEQ}                    { return O_NEQ; }
{LES}                    { return O_LES; }
{GRE}                    { return O_GRE; }
{ALPHA}{ALNUM}*           { return IDENTIFIER; }

%%