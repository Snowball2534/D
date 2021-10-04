#pragma once
#define MAXSIZE 50

//Caution!
//The order of parameters keeps consistent with the order of arguments in the Queue_NodeEstablish-function
typedef struct {
	int key;
	int priority;
	int pre;
}node;

typedef struct {
	node* data[MAXSIZE];
	int length;
}Priority_Queue;


//Caution!
//The order of arguments keeps consistent with the order of definition in the node-structure
node* Queue_NodeEstablish(int a, int b, int c);


bool Queue_Establish(Priority_Queue*& x);
bool Queue_Destroy(Priority_Queue*& x);
bool Queue_IfEmpty(Priority_Queue*& x);
bool Enqueue(Priority_Queue*& x, node* p);
node* Dequeue(Priority_Queue*& x);

