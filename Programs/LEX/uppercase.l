%option noyywrap

%{
    #include <stdio.h>
    int uc = 0;
%}

%%
[A-Z] {uc++;}
\n {printf("Total Uppercase Characters: %d", uc);}
%%

int main(){
    printf("Enter the sentence: ");
    yylex();
    return 0;
} 