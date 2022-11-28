#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
} *start,*temp,*x,*prev;
void create();
void display();
void insert_beg();
void insert_end();
void insert_pos();
void del_beg();
void del_end();
void del_pos();
void main()
{
    int ch,x,n,i;
    while(1)
    {
        printf("Menu\n 1.Creation\n 2.display\n 3.insert at the beggining\n 4.insert at the end\n 5.insert at any position\n 6.delete from beginning\n 7.delete from end\n 8.delete from any position\n 9.exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:printf("enter the number of nodes");
        scanf("%d",&n);
        for(i=1;i<n+1;i++)
        create();
        break;
        case 2:display();
        break;
        case 3:insert_beg();
        break;
        case 4:insert_end();
        break;
        case 5:insert_pos();
        break;
        case 6:del_beg();
        break;
        case 7:del_end();
        break;
        case 8:del_pos();
        break;
        case 9:exit(0);
        }

    }
}
void create()
{
    int item;
    printf("Enter the item");
    scanf("%d",&item);
    x=(struct node*)malloc(sizeof(struct node));
    x->data=item;
    x->next=NULL;
    if(start==NULL)
    {
        start=x;
        temp=x;
    }
    else
    {
        temp->next=x;
        temp=x;
    }
}
void display()
{
    if(start==NULL)
    printf("List is empty");
    else
    {
        temp=start;
        printf("The list is\n");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
void insert_beg()
{
    int item;
    printf("Enter the data item");
    scanf("%d",&item);
    x=(struct node*)malloc(sizeof(struct node));
    x->data=item;
    x->next=NULL;
    if(start==NULL)
    {
        start=x;
    }
    else
    {
        x->next=start;
        start=x;
    }
}
void insert_end()
{
    int item;
    printf("Enter the data item");
    scanf("%d",&item);
    x=(struct node*)malloc(sizeof(struct node));
    x->data=item;
    x->next=NULL;
    if(start==NULL)
    {
        start=x;
    }
    else
    {
        temp=start;
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=x;
    }
}
void insert_pos()
{
    int item,pos,k;
    printf("Enter the item");
    scanf("%d",&item);
    printf("Enter the position");
    scanf("%d",&pos);
    x=(struct node*)malloc(sizeof(struct node));
    x->data=item;
    x->next=NULL;
    temp=start;
    if(start==NULL)
    start=x;
    else
    {
        for(k=1;k<pos-1;k++)
        {
            temp=temp->next;
        }
        x->next=temp->next;
        temp->next=x;
    }
}
void del_beg()
{
    if(start==NULL)
    printf("List is empty");
    else
    {
        temp=start;
        start=temp->next;
        printf("the deleted element is %d",temp->data);
        printf("\n");
        free(temp);
    }
}
void del_end()
{
    if(start==NULL)
    printf("List is empty\n");
    else if(start->next==NULL)
    {
        temp=start;
        printf("Deleted element is %d",temp->data);
        printf("\n");
        start=NULL;
        free(temp);
}
    else
    {
        temp=start;
        while(temp->next !=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        printf("The deleted element is %d",temp->data);
        printf("\n");
        free(temp);
        prev->next=NULL;
    }
}
void del_pos()
{
    if(start==NULL)
    printf("List is empty");
    else if(start->next==NULL)
    {
        temp=start;
        printf("Deleted element is %d\n",temp->data);
        start=NULL;
        free(temp);
    }
    else
    {
        int pos,k;
        temp=start;
        printf("Enter the position");
        scanf("%d",&pos);
        for(k=1;k<pos;k++)
            {
                prev=temp;
                temp=temp->next;
            }
            prev->next=temp->next;
            printf("the deleted element is %d\n",temp->data);
            free(temp);
        }
}