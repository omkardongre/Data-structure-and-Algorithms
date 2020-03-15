#include<stdio.h>
#include <time.h> 
#define N 4
int root;
int visited_all=(1<<N)-1;
int path[16][N];
int dp[16][N];
int dist[N][N] = {
       			{0,	20,	42,	25},
       			{20,	0,	30,	34},
        		{42,	30,	0,	10},
        		{25,	34,	10,	0}
		  };

void initisation();
int tsp(int mask,int source);
void display();
void display_path(int source);

int main()
{
	

	int i,j,cost=0,mask;
	initisation();	
	printf("\n Enter starting vertex\t: ");
	scanf("%d",&root);
	root=root-1;
	mask= 1<<root;
	cost=tsp(mask,root);
	printf("\n Minimum distance\t: %d\n",cost);
	display_path(root);

	return 0;
}

int tsp(int mask,int source)
{
	
	
	if(mask==visited_all)
	{
		
		return dist[source][root];
	}
		
	else if (dp[mask][source]!=-1)
	{
		return dp[mask][source];
	
	}
	
	int ans=999,minAns=0,i,k;
	for(i=0;i<4;i++)
	{

		if((mask&(1<<i))==0)
		{
			minAns=dist[source][i]+tsp(mask|(1<<i),i);
			if(ans>minAns)
			{
				ans=minAns;				
				k=i;			
			}
		}
	}
	
	path[mask][source]=k;
	return dp[mask][source]=ans;
						
}
void initisation()
{
	for(int i=0;i< (1<<N);i++ )
	{
		for(int j=0;j<N;j++)
		{
			dp[i][j]=-1;
			path[i][j]=-1;		
		}
	}
}

void display_path(int source)
{
	int count=0,i=0;
	int brr[N];
	for(i=0;i<N;i++)
	{
		brr[i]=-1;
	}

	printf("\n shortest path\t\t: %d ->",source+1);
	while(count<N-1)
	{
		for(i=0;i<(1<<N);i++)
		{
			if(path[i][source]!=-1 && brr[path[i][source]]==-1)
			{
				brr[path[i][source]]++;
				source=path[i][source];
				printf(" %d -> ",source+1);
				count++;

				break;
			}
		}
	}
	printf("%d\n\n",root+1);	

}
/*output
om@om-Vostro-3558:~/Desktop$ gcc tsp.c
om@om-Vostro-3558:~/Desktop$ ./a.out

 Enter starting vertex	: 1

 Minimum distance	: 85

 shortest path		: 1 -> 2 ->  3 ->  4 -> 1

om@om-Vostro-3558:~/Desktop$ ./a.out

 Enter starting vertex	: 3

 Minimum distance	: 85

 shortest path		: 3 -> 2 ->  1 ->  4 -> 3

om@om-Vostro-3558:~/Desktop$ ./a.out

 Enter starting vertex	: 4

 Minimum distance	: 85

 shortest path		: 4 -> 1 ->  2 ->  3 -> 4


*/

