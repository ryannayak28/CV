%option noyywrap
%{
    #include<stdio.h>
    int v=0, c=0;
%}

%%
[AEIOUaeiou] {v++;}
[^AEIOUaeiou\n] {c++;}
\n {printf("Vowels = %d \t Consonants = %d", v, c);}
%%

int main()
{
    printf("Enter string: ");
    yylex();
    return 0;
}