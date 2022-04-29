%option noyywrap

%{
    #include <stdio.h>
    int lc = 1;
%}

%%
\n {
    lc++;
}
%%

int main(){
    yyin = fopen("input.txt", "r");
    yylex();
    printf("\n Total Lines: %d", lc);
    return 0;
}