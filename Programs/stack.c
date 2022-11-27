//this is a menu driven program for implementing stack operations




#include <stdio.h>
#include<stdlib.h>
#define n 5
void push();
void pop();
void display();
int stack[n],top=-1;
void main()
{
    int ch,i,item;
    while(1)
    {
        printf("Menu\n 1.push\n 2.pop\n 3.Display\n 4.Exit\n");
        printf("Enter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:printf("wrong choice");
        }
    }
}
void push()
{
    int item;
    printf("Enter the number\n");
    scanf("%d",&item);
    if(top==n-1)
    {
        printf("stack overflow\n");
    }
    else
    {
        top++;
        stack[top]=item;
    }
}
void pop()
{
    int item;
    if(top==-1)
    printf("stack underflow\n");
    else{
        item=stack[top];
        top--;
        printf("The poped element is %d \n",item);
    }
}
void display()
{
    int i;
    if(top==-1)
    printf("stack is empty");
    else
    {
        for(i=0;i<=top;i++)
        printf("%d ",stack[i]);
        printf("\n");
    }
}