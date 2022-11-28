#include<stdio.h>
#include<conio.h>
#include<string.h>
void push (char);
char pop();
int precd(char);
char infix[30], postfix[20];
char stack[20];
int top=-1;
int main()
{
    int i=0, j=0;
    char  c, item;
    printf("\nenter the infix expression:  ");
    gets(infix);
    while(infix[i]!='\0')
    {
        c=infix[i];
        switch(c)
        {
            case '(':
                        push(c);
                        break;

            case ')' :
                        item=pop();
                        while(item!='(')
                        {
                            postfix[j]=item;
                            j++;
                            item=pop();
                        }
                        break;
            case '^':
            case '/':
            case '*':
            case '+':
            case '-':
                        while((precd(stack[top]))>=(precd(c)))
                        {
                            item=pop();
                            postfix[j]=item;
                            j++;
                        }
                        push(c);
                        break;
            default:
                        postfix[j]=c;
                        j++;
        }
        i++;
    }
    while(top>=0)
    {
        item=pop();
        postfix[j]=item;
        j++;
    }
    postfix[j]='\0';
    printf("\nThe postfix expression is : ");
    puts(postfix);
    getch();
}
void push(char n)
{
    top++;
    stack[top]=n;
}
char pop()
{
    char b;
    b=stack[top];
    top--;
    return b;
}
int precd(char n)
{
    if(n=='^')
        return 7;
    else if(n=='/' || n=='*')
        return 6;
    else if(n=='+' || n=='-')
        return 5;
    else
        return 4;
}