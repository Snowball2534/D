#include<stdio.h>
#include<stdlib.h>
#include"Header_Queue.h"

//Caution!
//The order of arguments keeps consistent with the order of definition in the node-structure
node* Queue_NodeEstablish(int a, int b, int c)
{
	node* temp = (node*)malloc(sizeof(node));
	if (temp == NULL)
	{
		return NULL;
	}
	temp->key = a;
	temp->priority = b;
	temp->pre = c;

	return temp;
}

void swap(Priority_Queue*& x, int j, int k)
{
	node* p = x->data[j];
	x->data[j] = x->data[k];
	x->data[k] = p;
}

void sift_down(Priority_Queue*& x, int i)
{
	if (2 * i + 1 >= x->length)
	{
		return;
	}
	int lchild = 2 * i + 1, rchild = 2 * i + 2, min = i;
	if (lchild < x->length && x->data[lchild]->priority < x->data[min]->priority)
	{
		min = lchild;
	}
	if (rchild < x->length && x->data[rchild]->priority < x->data[min]->priority)
	{
		min = rchild;
	}
	if (i != min)
	{
		swap(x, min, i);
		sift_down(x, min);
	}
}

void sift_up(Priority_Queue*& x, int i)
{
	if (i == 0)
	{
		return;
	}
	int parent = (i - 1) / 2;

	if (x->data[parent]->priority > x->data[i]->priority)
	{
		swap(x, parent, i);
		sift_up(x, parent);
	}
}

void Heapify(Priority_Queue*& x)
{
	for (int i = (x->length - 1) / 2; i >= 0; i--)
	{
		sift_down(x, i);
	}
}

bool Queue_Establish(Priority_Queue*& x)
{
	x = (Priority_Queue*)malloc(sizeof(Priority_Queue));
	if (x == NULL)
	{
		return false;
	}
	x->length = 0;
	return true;
}

bool Queue_Destroy(Priority_Queue*& x)
{
	for (int i = 0; i < x->length; i++)
	{
		free(x->data[i]);
	}
	free(x);
	x = NULL;
	return true;
}

bool Enqueue(Priority_Queue*& x, node* p)
{
	if (x->length == MAXSIZE)
	{
		return false;
	}
	x->data[x->length] = p;
	sift_up(x, x->length);
	x->length++;
	return true;
}

node* Dequeue(Priority_Queue*& x)
{
	if (x->length == 0)
	{
		return NULL;
	}
	node* p = x->data[0];
	x->data[0] = x->data[--(x->length)];
	sift_down(x, 0);
	return p;
}

bool Queue_IfEmpty(Priority_Queue*& x)
{
	if (x->length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}