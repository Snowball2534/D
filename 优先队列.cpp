#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50
#define EleType int

typedef struct{
	int priority;
	EleType key;
}node;

typedef struct{
	node* data[MAXSIZE];
	int length;
}Priority_Queue;

node* queue_input(void)
{
	node* temp=(node *)malloc(sizeof(node));
	if(temp==NULL)
	{
		exit(0);
	}
	printf("Please input the number and priority of the node:\n");
	scanf("%d %d",&(temp->key),&(temp->priority));
	return temp;
}

void swap(Priority_Queue *&x,int j,int k)
{
	node *p=x->data[j];
	x->data[j]=x->data[k];
	x->data[k]=p;
}

void swift_down(Priority_Queue *&x,int i)
{
	if(2*i+1>=x->length)
	{
		return;
	}
	int lchild=2*i+1,rchild=2*i+2,max=i;
	if(lchild<x->length&&x->data[lchild]->priority>x->data[max]->priority)
	{
		max=lchild;
	}
	if(rchild<x->length&&x->data[rchild]->priority>x->data[max]->priority)
	{
		max=rchild;
	}
	if(i!=max)
	{
		swap(x,max,i);
		swift_down(x,max);
	}
}

void swift_up(Priority_Queue *&x,int i)
{
	if(i==0)
	{
		return;
	}
	int parent=(i-1)/2;
	
	if(x->data[parent]->priority<x->data[i]->priority)
	{
		swap(x,parent,i);
		swift_up(x,parent);
	}
}

void Heapify(Priority_Queue *&x)
{
	for(int i=(x->length-1)/2;i>=0;i--)
	{
		swift_down(x,i);
	}
}

bool Queue_Establish(Priority_Queue *&x)
{
	x=(Priority_Queue *)malloc(sizeof(Priority_Queue));
	if(x==NULL)
	{
		return false;
	}
	int n;
	printf("Please input the number of nodes you want to initialize the queue:\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		x->data[i]=queue_input();
	} 
	x->length=n;
	Heapify(x);
	return true;
}

bool Queue_Destroy(Priority_Queue *&x)
{
	for(int i=0;i<x->length;i++)
	{
		free(x->data[i]);
	}
	free(x);
	x=NULL;
	return true;
}

int Queue_Length(Priority_Queue *x)
{
	printf("The length is %d\n",x->length);
	return x->length;
}

bool Enqueue(Priority_Queue *&x)
{
	if (Queue_Length(x) == MAXSIZE)
	{
		return false;
	}
	x->data[x->length]=queue_input();
	swift_up(x,x->length);
	x->length++;
	return true;
}

bool Dequeue(Priority_Queue *&x)
{
	if (Queue_Length(x) == 0)
	{
		return false;
	}
	printf("NO.%d\n",x->data[0]->key);
	printf("Priority:%d\n",x->data[0]->priority);
	x->data[0]=x->data[--(x->length)];
	swift_down(x,0);
	return true;
}

int queue_search(Priority_Queue *x,int k)
{
	int i=0;
	while(i<x->length&&x->data[i]->key!=k)
	{
		i++;
	}
	if(i==x->length)
	{
		return -1;
	}
	else{
		return i;
	}
}
bool Queue_Search(Priority_Queue *x)
{
	int i,k;
	printf("Please input the number of node you want to search:\n");
	scanf("%d",&k);
	i=queue_search(x,k);
	if(i==-1)
	{
		printf("No such element!\n");
		return false;
	}
	printf("No.%d\n",x->data[i]->key);
	printf("Priority:%d\n",x->data[i]->priority);
	return true;
}

bool Queue_Modify(Priority_Queue *&x)
{
	int k,i;
	printf("Please input the number you want to modify:\n");
	scanf("%d",&k);
	i=queue_search(x,k);
	if(i==-1)
	{
		printf("No such element!\n");
		return false;
	}
	printf("Following is the related information:\n");
	printf("NO.%d\n",x->data[i]->key);
	printf("Priority:%d\n",x->data[i]->priority);
	printf("Please input the new priority:\n");
	scanf("%d",&x->data[i]->priority);
	swift_down(x,i);
	swift_up(x,i);
	return true;
}
//Call the function when testing
void queue_display(Priority_Queue *&x)
{
	for(int i=0;i<x->length;i++)
	{
		printf("%d %d\n",x->data[i]->key,x->data[i]->priority);
	}
}

int main()
{
	int instruct,n;
	Priority_Queue *x;
	Queue_Establish(x);
	printf("***Welcome to the priority queue system***\n");
	printf("1.Enqueue\n");
	printf("2.Dequeue\n");
	printf("3.Length of the queque\n");
	printf("4.Search the queque\n");
	printf("5.Modify the queue\n");
	printf("6.Quit\n");
	while(1)
	{
		printf("Please input the instruction:\n");
		scanf("%d",&instruct);
	switch(instruct)
	{
		case 1:Enqueue(x);
		       break;
	    case 2:Dequeue(x);
	           break;
	    case 3:Queue_Length(x);
	           break;
	    case 4:Queue_Search(x);
	           break;
	    case 5:Queue_Modify(x);
	           break;
	    case 6:Queue_Destroy(x);
		       return 0;
		case 7:queue_display(x);
		       break;
	}
}
 } 
