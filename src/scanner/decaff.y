%{
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>

    extern int yylex();
    extern int yyparse();
    extern FILE *yyin;
 
    void yyerror(const char* str);
%}

%union {
    int ival;
    float fval;
    bool bval;
    char cval;
}

%token <ival> T_INTG
%token <fval> T_FLOT
%token <bval> T_BOOL
%token T_NEWLINE
%token IDENTIFIER
%token O_ADD O_SUB O_MUL O_DIV O_MOD O_LEF O_RIT
%token O_NOT O_LEQ O_GEQ O_LES O_GRE O_EQL O_NEQ
%token O_BND O_BOR
%left O_BOR
%left O_BND
%left O_OR
%left O_AND
%left O_XOR
%left O_ADD O_SUB
%left O_MUL O_DIV
%left O_MOD
%type <ival> int_expr
%type <fval> float_expr
%type <bval> bool_expr

%%

expr_list:
    | expr_list expr
    ;

expr:
    T_NEWLINE
    | int_expr T_NEWLINE { printf("RESULT: %d\n", $1); }
    | float_expr T_NEWLINE { printf("RESULT: %f\n", $1); }
    | bool_expr T_NEWLINE { printf("RESULT: %d\n", $1); }
    ;

int_expr:
    IDENTIFIER                       { $$ = 0; }
    | T_INTG                          { $$ = $1; }
    | int_expr O_BOR int_expr       { $$ = $1 | $3; }
    | int_expr O_BND int_expr       { $$ = $1 & $3; }
    | int_expr O_OR int_expr       { $$ = $1 || $3; }
    | int_expr O_AND int_expr       { $$ = $1 && $3; }
    | int_expr O_XOR int_expr       { $$ = $1 ^ $3; }
    | int_expr O_ADD int_expr       { $$ = $1 + $3; }
    | int_expr O_SUB int_expr       { $$ = $1 - $3; }
    | int_expr O_MUL int_expr       { $$ = $1 * $3; }
    | int_expr O_DIV int_expr       { $$ = $1 / $3; }
    | int_expr O_MOD int_expr       { $$ = $1 % $3; }
    | O_LEF int_expr O_RIT          { $$ = $2; }
    | O_SUB int_expr                { $$ = -$2; }
    ;

bool_expr:
    IDENTIFIER                       { $$ = 0; }
    | T_BOOL                          { $$ = $1; }
    | bool_expr O_BOR bool_expr       { $$ = $1 | $3; }
    | bool_expr O_BND bool_expr       { $$ = $1 & $3; }
    | bool_expr O_OR bool_expr       { $$ = $1 || $3; }
    | bool_expr O_AND bool_expr       { $$ = $1 && $3; }
    | bool_expr O_XOR bool_expr       { $$ = $1 ^ $3; }
    | int_expr  O_LEQ int_expr        { $$ = $1 <= $3; }
    | int_expr  O_GEQ int_expr        { $$ = $1 >= $3; }
    | int_expr  O_LES int_expr        { $$ = $1 < $3; }
    | int_expr  O_GRE int_expr        { $$ = $1 > $3; }
    | int_expr  O_EQL int_expr        { $$ = $1 == $3; }
    | int_expr  O_NEQ int_expr        { $$ = $1 != $3; }
    | float_expr O_LEQ float_expr        { $$ = $1 <= $3; }
    | float_expr O_GEQ float_expr        { $$ = $1 >= $3; }
    | float_expr O_LES float_expr        { $$ = $1 < $3; }
    | float_expr O_GRE float_expr        { $$ = $1 > $3; }
    | float_expr O_EQL float_expr        { $$ = $1 == $3; }
    | float_expr O_NEQ float_expr        { $$ = $1 != $3; }
    | float_expr  O_LEQ int_expr        { $$ = $1 <= $3; }
    | float_expr  O_GEQ int_expr        { $$ = $1 >= $3; }
    | float_expr  O_LES int_expr        { $$ = $1 < $3; }
    | float_expr  O_GRE int_expr        { $$ = $1 > $3; }
    | float_expr  O_EQL int_expr        { $$ = $1 == $3; }
    | float_expr  O_NEQ int_expr        { $$ = $1 != $3; }
    | int_expr O_LEQ float_expr        { $$ = $1 <= $3; }
    | int_expr O_GEQ float_expr        { $$ = $1 >= $3; }
    | int_expr O_LES float_expr        { $$ = $1 < $3; }
    | int_expr O_GRE float_expr        { $$ = $1 > $3; }
    | int_expr O_EQL float_expr        { $$ = $1 == $3; }
    | int_expr O_NEQ float_expr        { $$ = $1 != $3; }
    | O_LEF bool_expr O_RIT          { $$ = $2; }
    ;

float_expr:
    T_FLOT                          { $$ = $1; }
    | float_expr O_ADD float_expr       { $$ = $1 + $3; }
    | float_expr O_SUB float_expr       { $$ = $1 - $3; }
    | float_expr O_MUL float_expr       { $$ = $1 * $3; }
    | float_expr O_DIV float_expr       { $$ = $1 / $3; }
    | int_expr O_ADD float_expr       { $$ = $1 + $3; }
    | int_expr O_SUB float_expr       { $$ = $1 - $3; }
    | int_expr O_MUL float_expr       { $$ = $1 * $3; }
    | int_expr O_DIV float_expr       { $$ = $1 / $3; }
    | float_expr O_ADD int_expr       { $$ = $1 + $3; }
    | float_expr O_SUB int_expr       { $$ = $1 - $3; }
    | float_expr O_MUL int_expr       { $$ = $1 * $3; }
    | float_expr O_DIV int_expr       { $$ = $1 / $3; }
    | O_LEF float_expr O_RIT          { $$ = $2; }
    ;

%%

int main(int argc, char** argv) {
	// Open a file handle to a particular file:
	FILE *myfile = fopen("test.decaff.file", "r");
	// Make sure it is valid:
	if (!myfile) {
		printf("I can't open test.decaff.file!\n");
		return -1;
	}
	// Set Flex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	// Parse through the input:
	yyparse();
	
}

void yyerror(const char *s) {
	printf("EEK, parse error!  Message: %s\n", s);
	// might as well halt now:
	exit(-1);
}
