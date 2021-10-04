#include<stdio.h>
#include<stdlib.h>
#include"Header_Graph.h"
#include"Header_Queue.h"

int dis1[MAXV][MAXV];
int path1[MAXV][MAXV];
int dis2[MAXV];
int path2[MAXV];

bool Graph_Establish(Graph*& x)
{
	x = (Graph*)malloc(sizeof(Graph));
	if (x == NULL)
	{
		return false;
	}

	int i = 0, n = 0, c = 0, temp;

	printf("****Start input the map****\n");
	printf("Please input the total number of places you would like to input:\n");
	scanf("%d", &n);
	x->v = n;
	printf("First,input the place name:\n");
	while (i < n)
	{
		scanf("%s", x->vertex[i].info);
		x->vertex[i].no = i + 1;
		i++;
	}

	printf("Second,input the distance matrix:\n");
	for (int j = 0; j < i; j++)
	{
		for (int k = 0; k < i; k++)
		{
			scanf("%d", &temp);
			if (temp < 0)
			{
				x->edge1[j][k] = INF;
			}
			else {
				x->edge1[j][k] = temp;
			}
			if (x->edge1[j][k] > 0 && x->edge1[j][k] != INF)
			{
				c++;
			}
		}
	}
	x->e = c;

	printf("Third,input the time matrix:\n");
	for (int j = 0; j < i; j++)
	{
		for (int k = 0; k < i; k++)
		{
			scanf("%d", &temp);
			if (temp < 0)
			{
				x->edge2[j][k] = INF;
			}
			else {
				x->edge2[j][k] = temp;
			}
		}
	}

	printf("The map is:\n");
	for (int j = 0; j < i; j++)
	{
		printf("Location%d: %s\n", x->vertex[j].no, x->vertex[j].info);
	}
	printf("The distance matrix:\n");
	for (int j = 0; j < i; j++)
	{
		for (int k = 0; k < i; k++)
		{
			if (x->edge1[j][k] == INF)
			{
				printf("  ¡Þ");
			}
			else
			{
				printf("%3d ", x->edge1[j][k]);
			}
		}
		printf("\n");
	}
	printf("The time matrix:\n");
	for (int j = 0; j < i; j++)
	{
		for (int k = 0; k < i; k++)
		{
			if (x->edge2[j][k] == INF)
			{
				printf("  ¡Þ");
			}
			else
			{
				printf("%3d ", x->edge2[j][k]);
			}
		}
		printf("\n");
	}

	return true;
}

bool Graph_Destroy(Graph*& x)
{
	free(x);
	x = NULL;
	return true;
}

bool Graph_Floyd(Graph* x, int edge[][MAXV])
{
	int i, j, k, temp;

	for (i = 0; i < x->v; i++)
	{
		for (j = 0; j < x->v; j++)
		{
			dis1[i][j] = edge[i][j];
			if (edge[i][j] != 0 && edge[i][j] != INF)
			{
				path1[i][j] = i;
			}
			else {
				path1[i][j] = -1;
			}
		}
	}
	for (k = 0; k < x->v; k++)
	{
		for (i = 0; i < x->v; i++)
		{
			for (j = 0; j < x->v; j++)
			{
				temp = dis1[i][k] + dis1[k][j];
				if (temp < dis1[i][j])
				{
					dis1[i][j] = temp;
					path1[i][j] = path1[k][j];
				}
			}
		}
	}
	return true;
}

bool Graph_Shortest_Distance1(Graph* x, int edge[][MAXV])
{
	int d[MAXV];
	int i, p1, p2, v1, v2;
	Graph_Floyd(x, edge);

	printf("Please input the serial number of two places you want to calculate:\n");
	scanf("%d %d", &p1, &p2);
	v1 = p1 - 1;
	v2 = p2 - 1;

	if (dis1[v1][v2] == INF)
	{
		printf("There is no path between two places!\n");
	}
	else {
		printf("The distance of %s and %s is: %d\n", x->vertex[v1].info, x->vertex[v2].info, dis1[v1][v2]);
		printf("The path is:\n");
		d[0] = v2;
		i = 1;
		while (path1[v1][v2] != v1)
		{
			d[i] = path1[v1][v2];
			v2 = d[i];
			i++;
		}
		d[i] = v1;//The path has been stored into the array in the reverse order
		for (; i >= 0; i--)
		{
			printf("%s\n", x->vertex[d[i]].info);
		}
	}

	return true;
}

bool Graph_Dijkstra1(Graph* x, int edge[][MAXV], int v)
{
	int set[MAXV];
	int i, j, k, temp, min, p;

	for (i = 0; i < x->v; i++)//Initialize the value
	{
		set[i] = 1;
		dis2[i] = INF;
		path2[i] = -1;
	}
	path2[v] = 0;
	dis2[v] = 0;
	set[v] = 0;

	for (i = 0; i < x->v - 1; i++)
	{
		for (j = 0; j < x->v; j++)//Update the distance
		{
			if (edge[v][j] != INF && edge[v][j] != 0)
			{
				temp = edge[v][j] + dis2[v];
				if (temp < dis2[j])
				{
					dis2[j] = temp;
					path2[j] = v;
				}
			}
		}
		min = INF;
		for (k = 0; k < x->v; k++)//Find the minimum 
		{
			if (set[k] == 1 && dis2[k] <= min)
			{
				min = dis2[k];
				p = k;
			}
		}
		set[p] = 0;
		v = p;
	}
	return true;
}

bool Graph_Dijkstra2(Graph* x, int edge[][MAXV], int v)
{
	Priority_Queue* p;
	if (Queue_Establish(p) == false)
	{
		return false;
	}
	int set[MAXSIZE];
	int i, flag, h = v;
	node* temp;

	for (i = 0; i < x->v; i++)//Initialize the value
	{
		set[i] = 1;
		dis2[i] = INF;
		path2[i] = -1;
	}

	//Initialize the queue
	temp = Queue_NodeEstablish(v, 0, v);
	Enqueue(p, temp);

	while (Queue_IfEmpty(p) != true)
	{
		temp = Dequeue(p);
		if (set[temp->key] == 1)
		{
			h = temp->key;
			dis2[h] = temp->priority;
			path2[h] = temp->pre;
			set[h] = 0;
			for (i = 0; i < x->v; i++)
			{
				if (edge[h][i] != INF && edge[h][i] != 0)
				{
					temp = Queue_NodeEstablish(i, dis2[h] + edge[h][i], h);
					if (temp == NULL)
					{
						return false;
					}
					Enqueue(p, temp);
				}
			}
		}
	}

	Queue_Destroy(p);
	return true;
}

bool Graph_Shortest_Distance2(Graph* x, int edge[][MAXV])
{
	int p, v, i, j, k, n;
	int d[MAXV];
	printf("Please input the serial number of place you want to start:\n");
	scanf("%d", &p);
	for (n = 0; n < 2; n++)
	{
		v = p - 1;
		for (i = 0; i < x->v; i++)
		{
			d[i] = 0;
		}
		if (n == 0)
		{
			Graph_Dijkstra1(x, edge, v);
		}
		else
		{
			Graph_Dijkstra2(x, edge, v);
		}

		printf("Following is the result:\n");
		for (i = 0; i < x->v; i++)
		{
			if (i == v || dis2[i]==INF )
			{
				continue;
			}
			printf("Position%d %s\n", x->vertex[i].no, x->vertex[i].info);
			printf("The shortest distance: %d\n", dis2[i]);
			printf("The path is: \n");
			d[0] = i;
			j = i;
			k = 1;
			while (path2[j] != v)
			{
				d[k] = path2[j];
				j = path2[j];
				k++;
			}
			d[k] = v;//The path has been stored into the array in reverse order
			for (; k >= 0; k--)
			{
				printf("%s  \n", x->vertex[d[k]].info);
			}
		}
	}
	return true;
}
