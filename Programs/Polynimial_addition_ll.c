#include <stdio.h>
#include <stdlib.h>
struct node
{
	int coeff, exp;
	struct node *ptr;
};

void main()
{
	typedef struct node poly;
	poly *start1=NULL,*start2=NULL,*start3=NULL,*temp,*p,*start;
	int co,ex,i,n,m,x;
	//creating linked list
	printf("Enter number of terms in polynomial 1: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		temp=(poly *)malloc(sizeof(poly));
		printf("\nCoefficient: ");
		scanf("%d",&temp->coeff);
		printf("Exponent: ");
		scanf("%d",&temp->exp);
		temp->ptr=NULL;
		if(start1==NULL)
			start1=temp;
		else 
		{
			p=start1;
			while(p->ptr!=NULL)
			{
				p=p->ptr;
			}
			p->ptr=temp;
		} 
	}
	//displaying linked list
	printf("\nPolynomial 1: ");
	if(start1==NULL)
			printf("List empty\n");
	else 
	{
		p=start1;
		while(p->ptr!=NULL)
		{
			printf("%dx^%d + ",p->coeff,p->exp);
			p=p->ptr;
		}
		printf("%dx^%d\n\n",p->coeff,p->exp);
		printf("Test");
	}
	//creating linked list
	printf("Enter number of terms in polynomial 2: ");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		temp=(poly *)malloc(sizeof(poly));
		printf("\nCoefficient: ");
		scanf("%d",&temp->coeff);
		printf("Exponent: ");
		scanf("%d",&temp->exp);
		temp->ptr=NULL;
		if(start2==NULL)
			start2=temp;
		else 
		{
			p=start2;
			while(p->ptr!=NULL)
			{
				p=p->ptr;
			}
			p->ptr=temp;
		} 
	}
	//displaying linked list
	printf("\nPolynomial 2: ");
	if(start2==NULL)
			printf("List empty\n");
	else 
	{
		p=start2;
		while(p->ptr!=NULL)
		{
			printf("%dx^%d + ",p->coeff,p->exp);
			p=p->ptr;
		}
		printf("%dx^%d\n\n",p->coeff,p->exp);
	}
	//addition
	while((start1!=NULL)&&(start2!=NULL))
	{
		if(start1->exp==start2->exp)
		{
			temp=(poly *)malloc(sizeof(poly));
			temp->coeff=start1->coeff+start2->coeff;
			temp->exp=start1->exp;
			temp->ptr=NULL;
			start1=start1->ptr;
			start2=start2->ptr;
		}
		else if(start1->exp>start2->exp)
		{
			temp=(poly *)malloc(sizeof(poly));
			temp->coeff=start1->coeff;
			temp->exp=start1->exp;
			temp->ptr=NULL;
			start1=start1->ptr;
		}
		else
		{
			temp=(poly *)malloc(sizeof(poly));
			temp->coeff=start2->coeff;
			temp->exp=start2->exp;
			temp->ptr=NULL;
			start2=start2->ptr;
		}
		
		if(start3==NULL)
		{
			start3=temp;
		}
		else 
		{
			p=start3;
			while(p->ptr!=NULL)
			{
				p=p->ptr;
			}
			p->ptr=temp;
		} 
	}
	while(start1!=NULL)
	{
		temp=(poly *)malloc(sizeof(poly));
		temp->coeff=start1->coeff;
		temp->exp=start1->exp;
		temp->ptr=NULL;
		start1=start1->ptr;
		if(start3==NULL)
		{
			start3=temp;
		}
		else 
		{
			p=start3;
			while(p->ptr!=NULL)
			{
				p=p->ptr;
			}
			p->ptr=temp;
		} 	
	}
	while(start2!=NULL)
	{
		temp=(poly *)malloc(sizeof(poly));
		temp->coeff=start2->coeff;
		temp->exp=start2->exp;
		temp->ptr=NULL;
		start2=start2->ptr;
		if(start3==NULL)
		{
			start3=temp;
		}
		else 
		{
			p=start3;
			while(p->ptr!=NULL)
			{
				p=p->ptr;
			}
			p->ptr=temp;
		} 	
	}
	//displaying linked list
	printf("\nSum: ");
	if(start3==NULL)
			printf("List empty\n");
	else 
	{
		p=start3;
		while(p->ptr!=NULL)
		{
			printf("%dx^%d + ",p->coeff,p->exp);
			p=p->ptr;
		}
		p->ptr=temp;
		printf("%dx^%d\n\n",p->coeff,p->exp);
	}		
}