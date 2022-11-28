#include <stdio.h>
#include <stdlib.h>
#define N 5
struct PriorityCQ
{
int item,p;
}PQ[N],temp;
void insert();
void delete();
void display();
void sort();
int front=-1,rear=-1;
void main()
{
    int ch;
    while(1)
    {
        printf("Menu\n 1.insert\n 2.delete\n 3.display\n 4.exit\n");
        printf("Enter the choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("You have sucessfully exited the program\n");
            exit(0);
            break;
            default:
            printf("Invalid choice\n");
        }
    }
}
void insert()
{
    if(rear==N-1)
    printf("Queue is full\n");
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        printf("Enter the element and its proirity");
        scanf("%d",&PQ[rear].item);
        scanf("%d",&PQ[rear].p);
    }
    else
    {
        rear++;
        printf("Enter the elements and priority");
        scanf("%d",&PQ[rear].item);
        scanf("%d",&PQ[rear].p);
    }
}
void delete()
{
    if(front==-1 && rear==-1)
    printf("Queue is empty\n");
    else if(front==rear)
    {
        printf("The deleted element is %d\n",PQ[front].item);
        printf("The deleted priority is %d\n",PQ[front].p);
        front=-1;
        rear=-1;
    }
    else
    {
        sort();
        printf("The deleted element is %d\n",PQ[front].item);
        printf("The deleted priority is %d\n",PQ[front].p);
        front=front+1;
    }
}
void display()
{
    int i;
    if(front==-1 && rear==-1)
    {
    printf("Q is empty\n");
    }
    else
    {
        printf("The elements are\n");
        for(i=front;i<=rear ; i++)
        {
            printf("Element : %d ,",PQ[i].item);
            printf("Priority : %d ;",PQ[i].p);
        }
        printf("\n");

    }
}
void sort()
{
    int i,j;
    for(i=front;i<=rear;i++)
    {
        for(j=front;j<=rear-i-1;j++)
        {
            if(PQ[j].p>PQ[j+1].p)
            {
                temp=PQ[j];
                PQ[j]=PQ[j+1];
                PQ[j+1]=temp;
            }
        }
    }
}