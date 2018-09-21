%{
    int chars = 0;
    int words = 0;
    int lines = 0;
%}


DIGIT   [0-9]
ID      [a-zA-Z][0-9a-zA-Z]*
// PROGRAM     class Program

%%

"int"                   { printf("INT"); }
"float"                 { printf("FLOAT"); }
"void"                  { printf("VOID"); }
{ID}                    { printf("INDENT"); }


%%
