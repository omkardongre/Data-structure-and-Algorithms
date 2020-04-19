#include<stdio.h>
#define inf 999

void Bellman(int graph[10][10],int dist[10][10],int src,int vertex);
int mindistance(int graph[10][10],int dist[10][10],int j,int i,int vertex);
int negative_cycle(int dist[10][10]);
void display(int matrix[10][10],int r ,int c);
int main()
{
	int graph[10][10]={
				{ 0   ,  6  , 5   , 5   ,  inf , inf , inf },
				{ inf ,  0  , inf , inf , -1   , inf , inf },
				{ inf , -2  , 0   , inf ,  1   , inf , inf },
				{ inf , inf ,-2   , 0   ,  inf , -1  , inf }, 
				{ inf , inf , inf , inf ,  0   , inf , 3   },
				{ inf , inf , inf , inf ,  inf , 0   , 3   },
				{ inf , inf , inf , inf ,  inf , inf  , 0  } 

			};
	
	int dist[10][10]={0};
	int src,dest,vertex=7;
	printf("\n enter source vertex (1-%d):  ",vertex);
	scanf("%d",&src);
	printf("\n enter destination vertex (1-%d):  ",vertex);
	scanf("%d",&dest);
	Bellman(graph,dist,src-1,vertex);
	printf("\n\tInput graph\n");
	display(graph,vertex,vertex);
	printf("\n\tdistance graph\n");
	display(dist,vertex-1,vertex);
	printf("\n shortest distance between vertex  %d and %d is : %d \n",src,dest,dist[vertex-2][dest-1]);
	return 0;
}

void Bellman(int graph[10][10],int dist[10][10],int src,int vertex)
{

	int i=0,j=0;
	for(i=0;i<vertex;i++)
	{
		dist[0][i]=graph[src][i];	
	}
	for(i=1;i<vertex-1;i++)
	{
		for(j=0;j<vertex;j++)
		{
			dist[i][j]=mindistance(graph,dist,j,i,vertex);	
		}
	}	
}



int mindistance(int graph[10][10],int dist[10][10],int j,int i,int vertex)
{
	int p=0,min=dist[i-1][j];
	for(p=0;p<vertex;p++)
	{				
		if((graph[p][j]!=inf && dist[i-1][p]!=inf) && (min>(dist[i-1][p]+graph[p][j])))
			min=dist[i-1][p]+graph[p][j];
	}
	return min;
}

void display(int  matrix[10][10],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("\t%d",matrix[i][j]);			
		}
		printf("\n");
	}
}


/*
om@om-Vostro-3558:~/Desktop$ ./a.out

	om@om-Vostro-3558:~/Desktop$ gcc bellmand\ ford.c 
om@om-Vostro-3558:~/Desktop$ ./a.out 

 enter source vertex (1-7):  1

 enter destination vertex (1-7):  7

	Input graph
	0	6	5	5	999	999	999
	999	0	999	999	-1	999	999
	999	-2	0	999	1	999	999
	999	999	-2	0	999	-1	999
	999	999	999	999	0	999	3
	999	999	999	999	999	0	3
	999	999	999	999	999	999	0

	distance graph
	0	6	5	5	999	999	999
	0	3	3	5	5	4	999
	0	1	3	5	2	4	7
	0	1	3	5	0	4	5
	0	1	3	5	0	4	3
	0	1	3	5	0	4	3

 shortest distance between vertex  1 and 7 is : 3 
om@om-Vostro-3558:~/Desktop$ gcc bellmand\ ford.c 
om@om-Vostro-3558:~/Desktop$ ./a.out 

 enter source vertex (1-7):  3

 enter destination vertex (1-7):  7

	Input graph
	0	6	5	5	999	999	999
	999	0	999	999	-1	999	999
	999	-2	0	999	1	999	999
	999	999	-2	0	999	-1	999
	999	999	999	999	0	999	3
	999	999	999	999	999	0	3
	999	999	999	999	999	999	0

	distance graph
	999	-2	0	999	1	999	999
	999	-2	0	999	-3	999	4
	999	-2	0	999	-3	999	0
	999	-2	0	999	-3	999	0
	999	-2	0	999	-3	999	0
	999	-2	0	999	-3	999	0

 shortest distance between vertex  3 and 7 is : 0 

*/










