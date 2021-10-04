#include<stdio.h>
#include"Header_Graph.h"


int main(void)
{
	int instruct;
	Graph* g;
	Graph_Establish(g);
	printf("***Welcome to the Map_Search system***\n");
	printf("1.Search time commitement from one place\n");
	printf("2.Search time commitement from one palce to another place\n");
	printf("3.Search trip cost from one place\n");
	printf("4.Search trip cost from one place to another place\n");
	printf("5.Quit the system\n");
	while (1)
	{
		printf("Please input the insruction:\n");
		scanf("%d", &instruct);
		switch (instruct)
		{
		case 1:
			Graph_Shortest_Distance2(g, g->edge2);
			break;
		case 2:
			Graph_Shortest_Distance1(g, g->edge2);
			break;
		case 3:
			Graph_Shortest_Distance2(g, g->edge1);
			break;
		case 4:
			Graph_Shortest_Distance1(g, g->edge1);
			break;
		case 5:
			Graph_Destroy(g);
			return 0;
		}
	}
}
