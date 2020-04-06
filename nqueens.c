#include<stdio.h>
#include<stdbool.h>
#define N 30
static int count;
void SolveNQueen(char board[N][N],int row,int n);
bool CanPlace(char board[N][N],int row,int col,int n);

int main()
{
	char board[N][N];
	int n,i=0,j=0;
	printf("\nEnter no of element : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++){
			board[i][j]='_';
		}
	}	

	SolveNQueen(board,0,n);
	printf("\nPossible no. of position of queen in %d*%d chess board are %d\n",n,n,count);
	
	return 0;
}

void SolveNQueen(char board[N][N],int row,int n)
{
	if(row==n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf(" %c\t",board[i][j]);
			}
			printf("\n\n");
		}
		++count;
		printf("\n");
		return ;		
	}

	for(int pos=0;pos<n;pos++)
	{
		if(CanPlace(board,row,pos,n))
		{
			board[row][pos]='1';
			SolveNQueen(board,row+1,n);
			
		}
		board[row][pos]='_';

	}
	//board[row][n-1]='_';	
}

bool CanPlace(char board[N][N],int row,int col,int n)
{

	int i=0,x=0,y=0;

	//for checking column
	for(i=0;i<row;i++)
	{
		if(board[i][col]=='1')
			return false;

	}

	//for checking top left diagnol
	x=row-1;
	y=col-1;	
	while(x>=0 && y>=0)
	{	
		if(board[x][y]=='1')
			return false;	

		--x;
		--y;
	}	 
	
	//for checking top right diagnol
	x=row-1;
	y=col+1;
	while(x>=0 && y<n)
	{	
		if(board[x][y]=='1')
			return false;	
		--x;
		++y;
	}	 
	return true;	
}

/*
od@od-desktop:~/Desktop$ gcc nqueens.c 
od@od-desktop:~/Desktop$ ./a.out

Enter no of element : 4
 _  1  _  _ 
 _  _  _  1 
 1  _  _  _ 
 _  _  1  _ 


 _  _  1  _ 
 1  _  _  _ 
 _  _  _  1 
 _  1  _  _ 


Possible no. of position of queen in 4*4 chess board are 2

*/
