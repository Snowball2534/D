#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

int main()
{
	bool a[MAXSIZE]={0};
	int n,m,x=0,y=0,z,k=-1;
	
	printf("Please input the total number of people:\n");
	scanf("%d",&n);
	printf("Please input the mark number:\n");
	scanf("%d",&m);
	z=n-15;
	for(int i=0;i<n;i++)
	{
		a[i]=1;
	}
	
	while(x!=z)
	{
		if(++k==n)
		{
			k=0;
		}
		if(a[k]==1)
		{
			y++;
		}
		if(y==m)
		{
			y=0;
			a[k]=0;
			x++;
			printf("NO.%d should be dragged into the sea\n",k+1);
		}
		}
	
	printf("The left people:\n");
	for(int i=0;i<n;i++)
	{
		if(a[i]==1)
		{
		printf("NO.%d  ",i+1);}
		}	
	
	return 0;
}
