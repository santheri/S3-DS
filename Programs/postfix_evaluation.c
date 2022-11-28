#include<stdio.h>
#include<conio.h>
#include<ctype.h>
int stack[20];
int top=-1;
void push(char);
int pop();
void main()
{
    char p[20];
    int value[20],i=0,opr,op1,op2,op3,result;
    printf("enter the postfix expression: ");
    gets(p);
    while(p[i]!='\0')
    {
        if(isalpha(p[i]))
        {
            printf("enter the value of %c : ",p[i]);
            scanf("%d",&value[i]);
        }
        i++;
    }
    i=0;
    while(p[i]!='\0')
    {
        if(isalpha(p[i]))
        {
            push(value[i]);

        }
        else
        {
            opr=p[i];
            op2=pop();
            op1=pop();
            switch(opr)
            {
                case '*':
                        op3=op1*op2;
                        break;
                case '/':
                        op3=op1/op2;
                        break;
                case'+':
                        op3=op1+op2;
                        break;
                case'-':
                        op3=op1-op2;
                        break;
            }
            push(op3);
        }
        i++;
    }
    result=pop();
    printf("result=%d",result);
    getch();
}
void push(char n)
{
    top++;
    stack[top]=n;

}
int pop()
{
    char b;
    b=stack[top];
    top--;
    return b;
}