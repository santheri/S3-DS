#include<stdio.h>
void main()
{
int n,a[10],high,low,mid,key,i,flag=0,temp,j;
printf("\nEnter the size of the array\n");
scanf("%d",&n);
printf("\nEnter the elements\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(a[i]>a[i+1])
{
temp=a[i];
a[i]=a[i+1];
a[i+1]=temp;
}
}
}
low=0;
high=n-1;
printf("\nEnter the key element\n");
scanf("%d",&key);
while(low<=high)
{
mid=(low+high)/2;
if(a[mid]==key)
{
flag=1;
break;
}
else if(a[mid]>key)
{
high=mid-1;
}
else
{
low=mid+1;
}
}
if(flag==1)
printf("\nElement is found at position %d",mid+1);
else
printf("\nElement not found\n");
}