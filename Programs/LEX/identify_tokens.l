%option noyywrap

%{
    #include <stdio.h>    
%}

%%
"while"|"if"|"else"|"elseif"|"do"|"int"|"float"|"return" {printf("\n%s is a keyword\n", yytext);}
"+"|"-"|"*"|"/"|"<="|">="|"=" {printf("\n%s is an operator\n", yytext);}
[a-zA-Z]* {printf("\n%s is an identifier\n", yytext);}
[0-9]+ {printf("\n%s is a number\n", yytext);}
[{}()|,;] {printf("\n%s is a seperator\n", yytext);}
%%

int main(){

    yylex();
    return 0;
}