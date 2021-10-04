#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int num;
	struct node *next;
} LinkNode;

bool LinkList_Initiate(LinkNode *&x)
{
	x=(LinkNode *)malloc(sizeof(LinkNode));
	if(x==NULL)
	{
		return false;
	}
	x->next=x;       //Cycling Linked List 
	return true;
}

bool LinkList_Destroy(LinkNode *&x)
{
	LinkNode *pre=x,*p=x->next;
	if(p!=x)       //Cycling Linked List
	{
		free(pre);
		pre=p;
		p=p->next;
	}
	free(pre);
	x=NULL;
	return true;
}

bool LinkList_Insert(LinkNode *&x,int c)
{
	LinkNode *temp;
	
	temp=(LinkNode *)malloc(sizeof(LinkNode));
	if(temp==NULL)
	{
		return false;
	}
    temp->num=c;
	temp->next=x->next;
	x->next=temp;
	
	return true;
}

bool LinkList_Display(LinkNode *x)
{
	LinkNode *p=x->next;
	printf("The left people:\n");
	while(p!=x)
	{
		printf("No.%d  ",p->num);
		p=p->next;
	}
	printf("\n");
	
    return true;
}

int main()
{
	int a;
	int m,n,x=0,y=1,z;
	LinkNode *L,*pre,*p;
	
	printf("Please input the total number of people:\n");
	scanf("%d",&n);
	printf("Please input the mark number:\n");
	scanf("%d",&m);
	z=n-15;
	if(LinkList_Initiate(L)==0)
	{
		exit(0);
	}
	for(int i=n;i>0;i--)
	{
		LinkList_Insert(L,i);
	}
	pre=L;
	p=L->next;
	while(x!=z)
	{
			while(y%m!=0)
		{
			y++;
			pre=pre->next;
			p=p->next;
			if(p==L)
			{
				p=p->next;
				pre=pre->next;
			}
		}
		printf("No.%d should be dragged into the sea\n",p->num);
		pre->next=p->next;
		free(p);
		p=pre->next;
		if(p==L)
			{
				p=p->next;
				pre=pre->next;
			}
		x++;
		y++;
	}
	LinkList_Display(L);
	LinkList_Destroy(L);
	
	return 0;
}
