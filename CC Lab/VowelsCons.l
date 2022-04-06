%{
#include<stdio.h>
#include<stdlib.h>
int v = 0;
int c = 0;
%}
%%
[aeiouAEIOU] {v++;}
[a-zA-Z] {c++;}
%%
int yywrap(void){
return 1;
}
int main()
{
printf("Enter the string: ");
yylex();
printf("No of vowels = %d\nNo of consonants = %d\n", v, c);
return 0;
}
