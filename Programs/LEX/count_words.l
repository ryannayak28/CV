%option noyywrap

%{
    #include<stdio.h>
    int i = 0;
%}

%%
[a-zA-Z0-9]* {i++;}
\n {printf("Total number of words in source program = %d", i); i=0;}
%%

int main(){
    printf("Enter the source program: ");
    yylex();
    return 0;
}