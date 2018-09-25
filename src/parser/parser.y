%{
    #include <stdio.h>
    #include <stdbool.h>

    extern int yylex();
    extern int yyparse();

    void yyerror(const char* str);
}%

%union {
    int ival;
    float fval;
    bool bval;
}

%token ival <INT>
%token fval <FLOAT>
%token bval <BOOL>

%%

expr:
    INT expr    { printf("Found: %d\n", $1); }
    | FLOAT expr    { printf("Found: %f\n", $1); }
    | BOOL expr    { printf("Found: %d\n", $1); }
    ;

%%



void yyerror(const char *s) {
	cout << "EEK, parse error!  Message: " << s << endl;
	// might as well halt now:
	exit(-1);
}
