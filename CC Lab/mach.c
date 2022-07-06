#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 50
void push(char);
char pop(void);
int top=-1;
char stack[MAX];
void main(){
  int i;
  char str[20],a,b,c;
  printf("\n\t\t *** CODE GENERATION ***\n\t  for single register microprocessor");
  printf("\n\nENTER THE POSTFIX EXPRESSION:");
  scanf("%s", str);
  for(i=0;str[i]!='\0';i++){
    if(isalpha(str[i]))
    push(str[i]);
    else{
     b=pop();
     a=pop();
     switch(str[i]){
       case '+': printf("\n\n\t\t LOAD %c, R",a);
         printf("\n\n\t\t ADD %c, R",b);
         printf("\n\n\t\t MOV temp(R), %c",a);
         break;
       case '-': printf("\n\n\t\t LOAD %c, R",a);
         printf("\n\n\t\t SUB %c, R",b);
         printf("\n\n\t\t MOV temp(R), %c",a);
         break;
      case '*': printf("\n\n\t\t LOAD %c, R",a);
         printf("\n\n\t\t MUL %c, R",b);
         printf("\n\n\t\t MOV temp(R), %c",a);
         break;

      case '/': printf("\n\n\t\t LOAD %c, R",a);
         printf("\n\n\t\t DIV %c, R",b);
         printf("\n\n\t\t MOV temp(R), %c",a);
         break;
      }
      push(a);
     }
    }
    printf("\n\n");
}
void push(char item){
  if(top==MAX)
  printf("\n\n STACK OVERFLOW\n");
  else{
      top=top+1;
      stack[top]=item;
   }
}
char pop(void){
  char item;
  if(top==-1){
    printf("\n STACK UNDERFLOW\n");
  }
  else{
      item=stack[top];
      top--;
   }
   return item;
}
