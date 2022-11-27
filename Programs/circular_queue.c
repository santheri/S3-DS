#include <stdio.h>
#include <stdlib.h>
#define n 5
void enqueue();
void dequeue();
void display();
int cq[n],rear=-1,front=-1;
void main()
{
int ch;
while(1)
{
printf("Menu\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: enqueue();
break;
case 2: dequeue();
break;
case 3: display();
break;
case 4:
printf("You have succesfully exited\n");
exit(0);
default: printf("Invalid Choice");
}
}
}
void enqueue()
{
int item;
printf("Enter the element to be inserted\n");
scanf("%d",&item);
if(front==(rear+1)%n)
printf("Queue is full\n");
else if(front==-1 && rear==-1)
{
front++;
rear++;
cq[rear]=item;
}
else
{
rear=(rear+1)%n;
cq[rear]=item;
}
}
void dequeue()
{
if(front==-1 && rear==-1)
printf("Queue is empty");
else if(front==rear)
{
printf("The deleted element is %d\n",cq[front]);
front=-1;
rear=-1;
}
else
{
printf("the deleted element is %d\n",cq[front]);
front=(front+1)%n;    
}
printf("\n");
}
void display()
{
int i;
if(front==-1 && rear==-1)
printf("Queue is empty\n");

else
{
printf("The elements in the queue are ");
for(i=front;i != rear;i=(i+1)%n)
printf("%d ",cq[i]);
printf("%d ",cq[i]);
}
printf("\n");
}