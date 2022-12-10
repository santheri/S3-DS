#include <stdio.h>
#include <stdlib.h>
void enqueue();
void dequeue();
void display();

struct node
{
    int data;
    struct node *next;
}*front = NULL,*start = NULL,*rear = NULL ,*x,*temp;
void main()
{
    int ch;
    while(1)
    {
    printf("Menu\n 1.Enqueue\n 2.Dequeue\n 3.display\n 4.exit\n");
    printf("Enter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        enqueue();
        break;
        case 2:
        dequeue();
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
void enqueue()
{
    int item;
    printf("Enter the element");
    scanf("%d",&item);
    x=(struct node*)malloc(sizeof(struct node));
    x->data=item;
    x->next=NULL;
    if(rear==NULL)
    {
    rear=x;
    front=x;
    }
    else
    {
        rear->next=x;
        rear=x;
    }
    
}
void dequeue()
{
    if(front==NULL)
    printf("queue is empty");
    else if(front==rear)
    {
        temp=front;
        printf("the deleted element is %d ",front->data);
        front=NULL;
        rear=NULL;
    }
    else{
        temp=front;
        printf("the deleted element is %d ",front->data);
        front=temp->next;
        free(temp);
        printf("\n");
    }
}
void display()
{
    if(front==NULL)
    printf("queue is empty");
    else
    {
        printf("The queue is \n");
        temp = front;
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
        }
    }
