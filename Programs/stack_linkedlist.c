#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void display();

struct node
{
    int data;
    struct node *next;
}*top=NULL,*x,*temp,*start=NULL;
void main()
{
    int ch;
    while(1)
    {
    printf("Menu\n 1.push\n 2.pop\n 3.display\n 4.exit\n");
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
        default:printf("Wrong choice");
    }
    }
}
void push()
{
    int item;
    printf("Enter the element");
    scanf("%d",&item);
    x=(struct node*)malloc(sizeof(struct node));
    x->data=item;
    x->next=NULL;
    if(top==NULL)
    top=x;
    else
    {
        x->next=top;
        top=x;
    }
}
void pop()
{
    if(top==NULL)
    printf("Stack is empty");
    else{
        temp=top;
        top=temp->next;
        printf("The deleted element is %d",temp->data);
        free(temp);
        printf("\n");
        }
}
void display()
{
    int i;
    if(top==NULL)
    printf("Stack is empty");
    else
    {
        temp=top;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}