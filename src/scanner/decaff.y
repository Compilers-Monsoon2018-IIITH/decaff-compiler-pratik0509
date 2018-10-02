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
%token IDENTIFIER KEY_CLASS KEY_PROGRAM O_COMMA KEY_TYPE
%token O_SEMICOLON KEY_IF KEY_ELSE KEY_CALLOUT STRING
%token EQUAL_OP ADD_EQUAL_OP SUB_EQUAL_OP
%token LEFT_CBRACE RIGHT_CBRACE INT_LITERAL LEFT_SBRACE RIGHT_SBRACE BOOL_LITERAL
%token BINARY_ADD BINARY_SUBTRACT BINARY_MULTIPLY BINARY_DIVISION BINARY_MOD O_LEF O_RIT
%token O_NOT O_LEQ O_GEQ O_LES O_GRE O_EQL O_NEQ
%token R_AND R_OR R_EQUALS R_NOT_EQUALS R_GREATER_THAN R_GREATER_THAN_EQUAL R_LESS_THAN R_LESS_THAN_EQUAL
%token UNARY_NOT

%start PROGRAM

%%

PROGRAM: KEY_CLASS KEY_PROGRAM LEFT_CBRACE T_ELINES FIELD_DECLS T_ELINES METHOD_DECLS T_ELINES RIGHT_CBRACE T_NEWLINES
        ;

T_NEWLINES: %empty
        | T_NEWLINES T_NEWLINE
        ;

T_ELINES: T_NEWLINES
        | O_SEMICOLONS
        ;

O_SEMICOLONS: O_SEMICOLON
            | O_SEMICOLONS O_SEMICOLON
            | O_SEMICOLONS O_SEMICOLON T_NEWLINES
            ;

FIELD_DECLS: %empty
            | KEY_TYPE IDENTIFIER_LIST O_SEMICOLONS
            ;

IDENTIFIER_LIST: IDENTIFIER
                | IDENTIFIER LEFT_SBRACE INT_LITERAL RIGHT_SBRACE
                |  IDENTIFIER_LIST O_COMMA IDENTIFIER
                | IDENTIFIER_LIST O_COMMA IDENTIFIER LEFT_SBRACE INT_LITERAL RIGHT_SBRACE
                ;

METHOD_DECLS: %empty
            | KEY_TYPE IDENTIFIER O_LEF ARG_LIST O_RIT BLOCK O_SEMICOLONS
            ;

BLOCK: %empty
    | LEFT_CBRACE VAR_DECLS STATEMENTS  RIGHT_CBRACE T_ELINES
    ;

VAR_DECLS: KEY_TYPE IDENTIFIER_LIST O_SEMICOLONS
        ;

EXPRESSION: LOCATION
            | METHOD_CALL
            | LITERAL
            | EXPRESSION BINARY_OP EXPRESSION
            | BINARY_SUBTRACT EXPRESSION
            | UNARY_NOT EXPRESSION
            | O_LEF EXPRESSION O_RIT
            ;

BINARY_OP: ARITHMETIC_OP
        | RELATIONAL_OP
        | EQ_OP
        | CONDITIONAL_OP
        ;

ARITHMETIC_OP: BINARY_ADD
            | BINARY_SUBTRACT
            | BINARY_MULTIPLY
            | BINARY_DIVISION
            | BINARY_MOD
            ;

RELATIONAL_OP: R_LESS_THAN
            | R_GREATER_THAN
            | R_LESS_THAN_EQUAL
            | R_GREATER_THAN_EQUAL
            ;

EQ_OP: R_EQUALS | R_NOT_EQUALS;

CONDITIONAL_OP: R_AND | R_OR;

LITERAL: INT_LITERAL | BOOL_LITERAL;

STATEMENTS: %empty
        | LOCATION ASSIGNMENT_OP EXPRESSION O_SEMICOLONS
        | METHOD_CALL O_SEMICOLONS
        | KEY_IF O_LEF EXPRESSION O_RIT BLOCK
        | KEY_IF O_LEF EXPRESSION O_RIT BLOCK KEY_ELSE BLOCK
        | BLOCK
        ;

METHOD_CALL: METHOD_NAME O_LEF PARAM_LIST O_RIT
            | KEY_CALLOUT O_LEF STRING O_COMMA PARAM_LIST O_RIT
            ;

PARAM_LIST: %empty
        | EXPRESSION
        | PARAM_LIST O_COMMA EXPRESSION
        ;

METHOD_NAME: IDENTIFIER
            ;
ASSIGNMENT_OP: EQUAL_OP
            | ADD_EQUAL_OP
            | SUB_EQUAL_OP
            ;

LOCATION: IDENTIFIER
        | IDENTIFIER LEFT_SBRACE EXPRESSION RIGHT_SBRACE

ARG_LIST: %empty
        | KEY_TYPE IDENTIFIER
        | ARG_LIST O_COMMA KEY_TYPE IDENTIFIER

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
