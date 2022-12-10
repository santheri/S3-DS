#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *lchild,*rchild;
}*ptr,*x,*q,*root=NULL;
void post(struct node*);
void in(struct node*);
void pre(struct node*);
void insert();
void main()
{
int ch;
while(1)
{
printf("\nMenu\n1.Insert\n2.Preordered traversal\n3.Inordered traversal\n4.Postordered traversal\n5.Exit\nEnter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: insert();
break;
case 2: pre(root);
break;
case 3: in(root);
break;
case 4: post(root);
break;
case 5: exit(0);
       default: printf("Wrong choice!!");
}
}
}
void insert()
{
int item;

printf("\nEnter the item\n");
scanf("%d",&item);
x=(struct node*)malloc(sizeof(struct node));
x->data=item;
x->lchild=NULL;
x->rchild=NULL;
if(root==NULL)
root=x;
else
{
ptr=root;
while(ptr!=NULL)
{
q=ptr;
if(ptr->data>item)
ptr=ptr->lchild;
else if(ptr->data<item)
ptr=ptr->rchild;
}
if(q->data>item)
q->lchild=x;
else if(q->data<item)
q->rchild=x;
}
}
void pre(struct node *ptr)
{
if(ptr!=NULL)
{
printf("%d\t",ptr->data);
pre(ptr->lchild);
pre(ptr->rchild);
}
}
void in(struct node *ptr)
{
if(ptr!=NULL)
{
in(ptr->lchild);
printf("%d\t",ptr->data);
in(ptr->rchild);
}
}
void post(struct node *ptr)
{
if(ptr!=NULL)
{
post(ptr->lchild);
post(ptr->rchild);
printf("%d\t",ptr->data);
}
}

