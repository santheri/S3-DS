#include <stdio.h>
#include <stdlib.h>
#define N 20
int a[20][20],b[20][20],s1[20][3],s2[20][3],t[20][3],sum[20][3],i,j,k1,k2,k3,m,n;

void create(int array[N][N]);
int represent(int array[N][N],int s[N][3]);
void transpose(int s1[N][3], int t[N][3]);
void add(int s1[N][3],int s2[N][3],int sum[N][3]);

void main()
{
	while(1)
	{	
		int ch;
		printf("MENU\n1. Sparse Matrix\n2. Transpose of Sparse Matrix\n3. Sum of Sparse Matrix\n4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				if((s1[0][0]!=0)&&(s1[0][1]!=0))
				{
					k1=represent(a,s1);
					break;
				}
				else
				{
					printf("Enter the matrix: \n");
					create(a);
					k1=represent(a,s1);
					break;
				}
			case 2:
				if((s1[0][0]!=0)&&(s1[0][1]!=0))
				{
					transpose(s1,t);
					break;
				}
				else
				{
					printf("Enter the matrix: \n");
					create(a);
					k1=represent(a,s1);
					transpose(s1,t);
					break;
				}
			case 3:
				if((s1[0][0]==0)&&(s1[0][1]==0))
				{
					printf("Enter the first matrix: \n");
					create(a);
					k1=represent(a,s1);
				}
				if((s2[0][0]==0)&&(s2[0][1]==0))
				{
					printf("Enter the second matrix: \n");
					create(b);
					k2=represent(b,s2);
				}
				add(s1,s2,sum);	
				break;		
			case 4:
				printf("Exiting program...\n");
				exit(0);
				break;
			default:
				printf("Invalid option! Please try again\n");
		}
	}
	
}
void create(int array[N][N])
{
	printf("Enter the number of rows: ");
	scanf("%d",&m);
	printf("Enter the number of coloumns: ");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&array[i][j]);
	printf("\n");
}
int represent(int array[N][N],int s[N][3])
{
	int k=1;
	s[0][0]=m;
	s[0][1]=n;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(array[i][j]!=0)
			{
				s[k][0]=i;
				s[k][1]=j;
				s[k][2]=array[i][j];
				k++;
			}
	s[0][2]=k-1;
	printf("The sparse matrix: \n");
	for(i=0;i<k;i++)
	{
		for(j=0;j<3;j++)
			printf("%d ",s[i][j]);
		printf("\n");
	}
	printf("\n");
	return k-1;
}
void transpose(int s1[N][3], int t[N][3])
{
	int c=1;
	t[0][0]=n;
	t[0][1]=m;
	t[0][2]=k1;
	for(i=0;i<n;i++)
		for(j=0;j<=k1;j++)
			if(s1[j][1]==i)
			{
				t[c][0]=s1[j][1];
				t[c][1]=s1[j][0];
				t[c][2]=s1[j][2];
				c++;
			}
	printf("Transpose: \n");
	for(i=0;i<=k1;i++)
	{
		for(j=0;j<3;j++)
			printf("%d ",t[i][j]);
		printf("\n");
	}
	printf("\n");
}
void add(int s1[N][3],int s2[N][3],int sum[N][3])
{
	int i=1,j=1,k3=1;
	if((s1[0][0]!=s2[0][0])||(s1[0][1]!=s2[0][1]))
		printf("Cannot perform addition as size of matrix don't match\n");
	else
	{
		sum[0][0]=s1[0][0];
		sum[0][1]=s1[0][1];
		while((i<=k1)&&(j<=k2))
		{
			if(s1[i][0]<s2[j][0])
			{
				sum[k3][0]=s1[i][0];
				sum[k3][1]=s1[i][1];
				sum[k3][2]=s1[i][2];
				i++;
				k3++;
			}
			else if(s1[i][0]>s2[j][0])
			{
				sum[k3][0]=s2[j][0];
				sum[k3][1]=s2[j][1];
				sum[k3][2]=s2[j][2];
				j++;
				k3++;
			}
			else if(s1[i][1]<s2[j][1])
			{
				sum[k3][0]=s1[i][0];
				sum[k3][1]=s1[i][1];
				sum[k3][2]=s1[i][2];
				i++;
				k3++;
			}
			else if(s1[i][1]>s2[j][1])
			{
				sum[k3][0]=s2[j][0];
				sum[k3][1]=s2[j][1];
				sum[k3][2]=s2[j][2];
				j++;
				k3++;
			}
			else
			{
				sum[k3][0]=s1[i][0];
				sum[k3][1]=s1[i][1];
				sum[k3][2]=s1[i][2]+s2[j][2];
				i++;
				j++;
				k3++;
			}
		}
		if(i<=k1)
		{
			sum[k3][0]=s1[i][0];
			sum[k3][1]=s1[i][1];
			sum[k3][2]=s1[i][2];
			i++;
			k3++;
		}
		if(j<=k2)
		{
			sum[k3][0]=s2[j][0];
			sum[k3][1]=s2[j][1];
			sum[k3][2]=s2[j][2];
			j++;
			k3++;
		}
		sum[0][2]=k3-1;
		printf("Sum of sparse matrices: \n");
		for(i=0;i<k3;i++)
		{
			for(j=0;j<3;j++)
				printf("%d ",sum[i][j]);
			printf("\n");
		}
		printf("\n");
		
	}	
	
		
} 