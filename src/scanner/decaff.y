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
}

%token <ival> INT
%token <fval> FLOAT
%token <bval> BOOL

%%

expr:
    expr INT    { printf("Found: %d\n", $2); }
    | expr FLOAT    { printf("Found: %f\n", $2); }
    | expr BOOL    { printf("Found: %d\n", $2); }
    | INT   { printf("Found: %d\n", $1); }
    | FLOAT    { printf("Found: %f\n", $1); }
    | BOOL    { printf("Found: %d\n", $1); }
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
