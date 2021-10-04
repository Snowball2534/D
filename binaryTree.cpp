#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
typedef struct node{
	char data;
	struct node* lchild;
	struct node* rchild;
}BTree;

#define EleType BTree*

typedef struct
{
	EleType data[MAXSIZE];
	int top;
}SqStack;
//Establish a sequence stack 
bool SqStack_Initiate(SqStack *& x)
{
	x=(SqStack *)malloc(sizeof(SqStack));
	if(x==NULL)
	{
	return false;}
	else{
		x->top=-1;
		return true;
	}
}
//Destroy the sequence stack
bool SqStack_Destroy(SqStack *& x)
{
	free(x);
	x=NULL;
	return true;
}
//Pop the top from the stack
bool SqStack_Pop(SqStack *&x,EleType &e)
{
	if(x->top==-1)
	{
		return false;
	}
	else
	{
		e=x->data[x->top--];
		return true;
	}
}
//Push the element into the stack
bool SqStack_Push(SqStack *&x,EleType e)
{
	if(x->top==MAXSIZE-1)
	{
		return false;
	}
	else
	{
		x->data[++x->top]=e;
		return true;
	}
}
//Get the top from the sequence stack
bool SqStack_GetTop(SqStack *&x,EleType &e)
{
	if(x->top==-1)
	{
		return false;
	}
	else
	{
		e=x->data[x->top];
		return true;
	}
 }
//Judge if the stack is empty or not
 bool SqStack_IfEmpty(SqStack *x)
 {
 	if(x->top==-1)
 	{
 		return true;
	 }
	 else{
	 	return false;
	 }
 }
//Establish a binary tree
bool BTree_Initiate(BTree *&x,char* str)
{
	int j=0,flag=-1;
	SqStack *p;
	BTree *w,*e;
	
	if(SqStack_Initiate(p)==0)
	{
		return false;
	}
	if(str[j]=='\0')
	{
		x=NULL;
		SqStack_Destroy(p);
		return true;
	}
	else{
	while(str[j]!='\0')
	{
	switch(str[j])
	{
		case '(':
		flag=0;
		SqStack_Push(p,w);
		break;
		case ',':
		flag=1;
		break;
		case ')':
		SqStack_Pop(p,w);
		break;
		default:
		w=(BTree *)malloc(sizeof(BTree));
		if(w==NULL)
		{
			SqStack_Destroy(p);
			return false;
		}
		w->data=str[j];
		w->lchild=w->rchild=NULL;
		if(flag==0)
		{
			SqStack_GetTop(p,e);
			e->lchild=w;
		}
		else if(flag==1)
		{
			SqStack_GetTop(p,e);
			e->rchild=w;
		}
		else
		{
			x=w;
		}
		break;	
		}
		j++;	
	}}
	SqStack_Destroy(p);
	return true;
}
//Print a binary tree
void BTree_Display(BTree *x)
{
	if(x!=NULL)
	{
		printf("%c",x->data);
		if(x->lchild!=NULL||x->rchild!=NULL)
		{
			printf("(");
	        BTree_Display(x->lchild);
	        if(x->rchild!=NULL)
	        {
	        	printf(",");
	        	BTree_Display(x->rchild);}
			printf(")");		    
			}
	}
}
//Destroy the binary tree
void BTree_Destroy(BTree *&x)
{
	if(x!=NULL)
	{
		BTree_Destroy(x->lchild);
		BTree_Destroy(x->rchild);
		free(x);
		x=NULL;
	}
}

bool PreOrder1(BTree *x)
{
	if(x==NULL)
	{
		printf("\n");
		return true;
	}
	
	SqStack* p;
	BTree *b=x;
	
	if(SqStack_Initiate(p)==0)
	{
		return false;
	}
	SqStack_Push(p,b);
	while(!SqStack_IfEmpty(p))
	{
		SqStack_Pop(p,b);
		printf("%c",b->data);
		if(b->rchild!=NULL)
		{SqStack_Push(p,b->rchild);}
		if(b->lchild!=NULL)
		{SqStack_Push(p,b->lchild);}
	} 
	printf("\n");
	SqStack_Destroy(p);

      return true;
}

bool PreOrder2(BTree *x)
{
	if(x==NULL)
	{
		printf("\n");
		return true;
	}
	
	BTree *b=x;
	SqStack* p;
	
	if(SqStack_Initiate(p)==0)
	{
		return false;
	}
	SqStack_Push(p,b);
	do{
		SqStack_Pop(p,b);
		while(b!=NULL){
		printf("%c",b->data);
		if(b->rchild!=NULL)
		{SqStack_Push(p,b->rchild);}
		b=b->lchild;}
	}
	while(!SqStack_IfEmpty(p));
	printf("\n");
	SqStack_Destroy(p);
	
	return true;
}

bool InOrder1(BTree *x)
{
	if(x==NULL)
	{
		printf("\n");
		return true;
	}
	
	SqStack *p;
	BTree *b=x;
	bool flag;
	
	if(SqStack_Initiate(p)==0)
	{
		return false;
	}
	do
	{
		while(b!=NULL)
		{
			SqStack_Push(p,b);
			b=b->lchild;
	    }
	    flag=true;
	    while(!SqStack_IfEmpty(p)&&flag)
	    {
	    	SqStack_Pop(p,b);
	    	printf("%c",b->data);
			if(b->rchild!=NULL)
			{
				flag=false;
				SqStack_Push(p,b->rchild);
				b=b->rchild->lchild;
			}
		}}while(!SqStack_IfEmpty(p));
		printf("\n");
	SqStack_Destroy(p);
	
	return true;
}

bool InOrder2(BTree *x)
{
	if(x==NULL)
	{
		printf("\n");
		return true;
	}
	
	BTree *b=x;
	SqStack *p;
	
	if(SqStack_Initiate(p)==0)
	{
	return false;	
	}
	
	while(!SqStack_IfEmpty(p)||b!=NULL)
	{
		while(b!=NULL)
		{
			SqStack_Push(p,b);
			b=b->lchild;
		}
		if(!SqStack_IfEmpty(p))
		{
			SqStack_Pop(p,b);
			printf("%c",b->data);
			b=b->rchild;
		}
	}
	printf("\n");
	SqStack_Destroy(p);
	
	return true;
 } 
 
bool PostOrder(BTree *x)
{
	if(x==NULL)
	{
		printf("\n");
		return true;
	}
	
	BTree *b=x,*r;
	SqStack *p;
	bool flag;
	
	if(SqStack_Initiate(p)==0)
	{
		return false;
	}
	
	do{
		while(b!=NULL)
		{
			SqStack_Push(p,b);
			b=b->lchild;
		}
		r=NULL;
		flag=true;
		while(!SqStack_IfEmpty(p)&&flag)
		{
			SqStack_GetTop(p,b);
			if(b->rchild==NULL||b->rchild==r)
			{
			    SqStack_Pop(p,b);   
				printf("%c",b->data);
				r=b;
			}
			else
			{
			    b=b->rchild;
				flag=false;
			}
		}
	}while(!SqStack_IfEmpty(p));
	SqStack_Destroy(p);
	printf("\n");
	
	return true;
}

BTree* BTree_FindNode(BTree *x,SqStack *&q,char e)
{
	BTree *p,*temp;
	
	if(x==NULL)
	{
		return NULL;
	}
    else
    {
    	SqStack_Push(q,x);
	}
	if(x->data==e)
	{
		return x;
	}
	if(x->lchild!=NULL)
	{
		p=BTree_FindNode(x->lchild,q,e);
		if(p!=NULL)
		{
		return p;
		}
	}
		p=BTree_FindNode(x->rchild,q,e);
		if(p==NULL)
		{
			SqStack_Pop(q,temp);
		}
	    return p;
}

bool BTree_FindPath(BTree *x)
{
	SqStack *q,*p;
	BTree* y;
	char c;
	
	printf("Please input the element you want to search:\n");
	c=getchar();
	
	if(SqStack_Initiate(q)==0||SqStack_Initiate(p)==0)
	{
		printf("Mistake!\n");
		return false;
	}
				if(BTree_FindNode(x,q,c)==NULL)
				{printf("No such element!\n");}
				else{
					while(SqStack_Pop(q,y))
					{SqStack_Push(p,y);}
					while(SqStack_Pop(p,y))
					{
						printf("%c",y->data);
					}
					printf("\n");
				}
	SqStack_Destroy(q);
	SqStack_Destroy(p);
	return true;
}

int main() {
	BTree *x;
	char a[50];
	int i;
	char c;
	
	printf("Welcome to the binary tree system!\n");
	printf("Please input the binary tree you need to establish:\n");
	gets(a);
	if(BTree_Initiate(x,a)==1)
	{
		BTree_Display(x);
		printf("\n");
		printf("Successfully established!\n");
	}
	else
	{
		printf("Failed in establishing!\n");
		exit(1);
	}
	while(1){
		printf("1.Go through in preorder\n");
		printf("2.Go through in inorder\n");
		printf("3.Go through in postorder\n");
		printf("4.Find the path to the certain node\n");
		printf("5.Quit\n");
		printf("Please input the instruction:\n");
		scanf("%d",&i);
		getchar();

		switch(i)
		{
			case 1:
				   printf("Method 1:");
				   PreOrder1(x);
				   printf("Method 2:");
				   PreOrder2(x);
			       break;
			case 2:
			       printf("Method 1:");
				   InOrder1(x);
				   printf("Method 2:");
				   InOrder2(x);
			       break;
			case 3:PostOrder(x);
			       break;
			case 4:
                   BTree_FindPath(x);
			       break;
			case 5:
			       BTree_Destroy(x);
				   return 0; 
		}
	}
}
