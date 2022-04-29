%option noyywrap

%{
	 #include<stdio.h>
       int nlines=1,nwords,nchars;
%}

%%
\n {nchars++;nlines++;}
[^ \n\t]+ {nwords++, nchars=nchars+yyleng;}
. {nchars++;}
%%

int main()
{
	yyin=fopen("input.txt","r");
	yylex();
	printf("Sentences = %d\nChars=%d\nWords=%d",nlines,nchars,nwords);
	return 0;
}