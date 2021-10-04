#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

typedef struct
{
	char num[20];
	char name[25];
}Info;

typedef struct node
{
    Info i;
	struct node *next;
}LinkNode;

bool LinkList_Initiate(LinkNode *&x)
{
	x=(LinkNode *)malloc(sizeof(LinkNode));
	if(x==NULL)
	{
		return false;
	}
	x->next=NULL;
	return true;
}

bool LinkList_Destroy(LinkNode *&x)
{
	LinkNode *pre=x,*p=x->next;
	if(p!=NULL)
	{
		free(pre);
		pre=p;
		p=p->next;
	}
	free(pre);
	x=NULL;
	return true;
}

int linklist_search(LinkNode *x,char* key,LinkNode *&e)
{
	LinkNode *p=x->next;
	int c=1;
	
    while(p!=NULL&&strcmp(key,p->i.num))
	{
		c++;
		p=p->next;
		}	
	if(p==NULL)
	{
		e=NULL;
		return 0;
	}
	else
	{
		e=p;
		return c;
	}
}

bool linknode_display(LinkNode *x,int c)
{
    printf("NO.%d\n",c);
	printf("NAME:%s\n",x->i.name);
	printf("NUMBER:%s\n",x->i.num);
	return true;
}

bool linknode_input(LinkNode *&x)
{
	printf("NAME:\n");
	gets(x->i.name);
	printf("NUMBER:\n");
	gets(x->i.num);
	return true;
}

bool LinkList_Search(LinkNode *x)
{
	char a[25];
	LinkNode *temp;
	int c;
	
	printf("Please input the number you want to search:\n");
	gets(a);
	if(c=linklist_search(x,a,temp))
	{
     	printf("Following is the related information:\n");
        linknode_display(temp,c);
		return true;
	}
	else
	{
        printf("No such contact!\n");
        return false;
	}
}

bool LinkList_Modify(LinkNode *&x)
{
	char a[25];
	LinkNode *temp;
	int c;
	
	printf("Please input the number you want to modify:\n");
	gets(a);
	if(c=linklist_search(x,a,temp))
	{
     	printf("Following is the related information:\n");
        linknode_display(temp,c);
		printf("Please input the new information\n");
		linknode_input(temp);
		return true;
	}
	else
	{
        printf("No such contact!\n");
        return false;
	}
}

bool LinkList_Delete(LinkNode *&x)
{
	LinkNode *pre=x,*p=x->next;
	int c=1,instruct;
	char a[25];
	
	printf("Please input the number you want to delete:\n");
	gets(a);
	
    while(p!=NULL&&strcmp(a,p->i.num))
	{
		c++;
		p=p->next;
		pre=pre->next;
	}	
	if(p==NULL)
	{
		printf("No such contact!\n");
		return false;
	}
	else
	{
		printf("Following is the related information:\n");
	    linknode_display(p,c);
	    printf("Are you sure to delete the contact?\n");
	    printf("If yes,please input 1\n");
	    printf("If no,please input 0\n");
	    scanf("%d",&instruct);
	    getchar();
	    if(instruct)
	    { pre->next=p->next;
		  free(p);
		  return true;
	    }
	    else
	    {
	    	return true;
		}
	}
}

bool LinkList_Display(LinkNode *x)
{
	if(x->next==NULL)
	{
		printf("No contact!\n");
		return true;
	}
	
	int c=1;
	LinkNode *p=x->next;
	while(p)
	{
		linknode_display(p,c);
		c++;
		p=p->next;
	}
    return true;
}

bool LinkList_Insert(LinkNode *&x)
{
	LinkNode *temp;
	
	temp=(LinkNode *)malloc(sizeof(LinkNode));
	if(temp==NULL)
	{
		return false;
	}
    printf("Please input information:\n");
    linknode_input(temp);
	temp->next=x->next;
	x->next=temp;
	
	return true;
}

int main()
{
	int i;
	LinkNode *L;
	
	if(!LinkList_Initiate(L))
	{
		exit(0);
	}
    printf("Welcome to the phone contact system\n");
    printf("1.Establish one new phone contact\n");
    printf("2.Delete the phone contact\n");
    printf("3.Modify the phone contact\n");
    printf("4.Search for one phone contact\n");
    printf("5.Display all the phone contacts\n");
    printf("6.Quit\n");
    
    while(1)
    {
    	printf("Please input the instruction\n");
    	scanf("%d",&i);
    	getchar();
    	
    	switch (i)
    	{
    		case 1:if(!LinkList_Insert(L))
			{
				exit(0);
			}
    		       break;
    		case 2:LinkList_Delete(L);
    		       break;
    		case 3:LinkList_Modify(L);
    		       break;
    		case 4:LinkList_Search(L);
    		       break;
    		case 5:LinkList_Display(L);
    		       break;
    		case 6:LinkList_Destroy(L);
    		       return 0;
		}
	}
}
