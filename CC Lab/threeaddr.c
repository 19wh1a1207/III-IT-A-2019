#include<stdio.h>
#include<string.h>
void pm();
void plus();
void div();
int i,ch,j,l,addr=100;
char ex[10], exp4[10] ,exp1[10], exp3[10],id1[5],op[5],id2[5];
void main(){
    while(1){
        printf("\n1.assignment\n2.arithmetic\n3.relational\n4.Exit\nEnter the choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter the expression with assignment operator:");
                scanf("%s",exp4);
                l=strlen(exp4);
                exp3[0]='\0';
                i=0;
                while(exp4[i]!='='){
                    i++;
                }
                strncat(exp3,exp4,i);
                strrev(exp4);
                exp1[0]='\0';
                strncat(exp1,exp4,l-(i+1));
                strrev(exp1);
                printf("Three address code:\ntemp=%s\n%s=temp\n",exp1,exp3);
                break;
            case 2:
                printf("\nEnter the expression with arithmetic operator:");
                scanf("%s",ex);
                strcpy(exp4,ex);
                l=strlen(exp4);
                exp1[0]='\0';
                for(i=0;i<l;i++){
                    if(exp4[i]=='+'||exp4[i]=='-'){
                        if(exp4[i+2]=='/'||exp4[i+2]=='*'){
                            pm();
                            break;
                        }
                        else{
                            plus();
                            break;
                        }
                    }
                    else if(exp4[i]=='/'||exp4[i]=='*'){
                        div();
                        break;
                    }
                }   
                break;
            case 3:
                printf("Enter the expression with relational operator:");
                scanf("%s%s%s",&id1,&op,&id2);
                if(((strcmp(op,"<")==0)||(strcmp(op,">")==0)||(strcmp(op,"<=")==0)||(strcmp(op,">=")==0)||(strcmp(op,"==")==0)||(strcmp(op,"!=")==0))==0)
                    printf("Expression is error");
                else{
                    printf("\n%d\tif %s%s%s goto %d",addr,id1,op,id2,addr+3);
                    addr++;
                    printf("\n%d\t T:=0",addr);
                    addr++;
                    printf("\n%d\t goto %d",addr,addr+2);
                    addr++;
                    printf("\n%d\t T:=1",addr);
                }
                break;
            case 4:
                exit(0);
                break;
        }
    }
}
void pm(){
    strrev(exp4);
    j=l-i-1;
    strncat(exp1,exp4,j);
    strrev(exp1);
    printf("Three address code:\ntemp=%s\ntemp1=%c%ctemp\n",exp1,exp4[j+1],exp4[j]);
}
void div(){
    strncat(exp1,exp4,i+2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n",exp1,exp4[i+2],exp4[i+3]);
}
void plus(){
    strncat(exp1,exp4,i+2);
    printf("Three addressv code:\ntemp=%s\ntemp1=temp%c%c\n",exp1,exp4[i+2],exp4[i+3]);
}
void strrev(char *str1)  {  
    int i, len, temp;  
    len = strlen(str1);
    for (i = 0; i < len/2; i++){  
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}  

