#pragma once
#define MAXV 10
#define INF 32767
#define InfoType char

typedef struct {
	int no;
	InfoType info[10];
}VertexType;
typedef struct {
	int edge1[MAXV][MAXV];
	int edge2[MAXV][MAXV];
	int v, e;
	VertexType vertex[MAXV];
}Graph;

bool Graph_Establish(Graph*& x);
bool Graph_Destroy(Graph*& x);
bool Graph_Shortest_Distance1(Graph* x, int edge[][MAXV]);
bool Graph_Shortest_Distance2(Graph* x, int edge[][MAXV]);

