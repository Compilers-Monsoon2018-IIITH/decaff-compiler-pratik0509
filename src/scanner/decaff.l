%{
    #include <stdio.h>
    #include <stdbool.h>
    #include <string.h>
    #include "decaff.tab.h"
%}

DIGIT   [0-9]
TRUE    "true"
FALSE   "false"

%%

[ \t\n]                  ;
{DIGIT}+                 { yylval.ival = atoi(yytext); return INT;      }
{DIGIT}*\.{DIGIT}*       { yylval.fval = atof(yytext); return FLOAT;    }
{TRUE}|{FALSE}           { yylval.bval = ((strcmp(yytext, "true") == 0) ? 1 : 0); return BOOL;      }

%%