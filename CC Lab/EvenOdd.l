%{
#include<stdio.h>
#include<stdlib.h>
int n1 = 0;
int n2 = 0;
%}
num_seq [0-9]*
%%
{num_seq}[0|2|4|6|8] {
		printf("Even Number [%d]", yyleng);
		return atoi(yytext);		
		}
{num_seq}[1|3|5|7|9] {
		printf("Odd Number [%d]", yyleng);
		return atoi(yytext);		
		}
%%
int yywrap(void){}
int main()
{
printf("Input an even number and an odd number: ");
n1 = yylex();
n2 = yylex();
int diff = n1 - n2;
if(diff % 2 != 0)
	printf("\nYour inputs are checked for correctness,\nResult: Correct\n");
else
	printf("\nYour inputs are checked for correctness,\nResult: Incorrect\n"); 
yylex();
return 0;
}
