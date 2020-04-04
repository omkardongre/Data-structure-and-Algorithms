#include<stdio.h>

void accept(int array[10],int order[10],int n);
void display(int array[10],int n);
void quickSort(int arr[10],int order[10], int low, int high) ;
int partition (int arr[10],int order[10], int low, int high) ;
void swap(int* a, int* b) ;
float MRT(int array[10],int n);


int main()
{
	int array[10],order[10],n,low,high;
	float result;
	printf("Enter no of files : ");
	scanf("%d",&n);
	accept(array,order,n);
	low=0;
	high=n-1;	
	quickSort(array,order,low,high);
	result=MRT(array,n);
	printf("\nMinimun Retrival Time : %f\n",result);
	printf("\nFiles execution order : \n");
	for (int i=0;i<n;i++)
	{
		printf("File%d\n",order[i]);

	}

}


void accept(int array[10],int order[10],int n)
{
	printf("\nEnter File duration: ");
	for (int i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
		order[i]=i+1;
	}
}

void display(int array[10],int n)
{
	
	for (int i=0;i<n;i++)
	{
		printf("%d\t",array[i]);

	}
}

void quickSort(int arr[10],int order[10], int low, int high) 
{ 
 	if (low < high) 
	{ 
	     	 int pi = partition(arr, order,low, high); 
		quickSort(arr,order, low, pi - 1); 
		quickSort(arr,order, pi + 1, high); 
    	} 
} 

int partition (int arr[10],int order[10], int low, int high) 
{ 
 	int pivot = arr[high];     
	int i = (low - 1);
        int temp;  
  
        for (int j = low; j <= high- 1; j++) 
       { 
       		if (arr[j] < pivot) 
        	{ 
         		i++;    
   	      		swap(&arr[i], &arr[j]);
			swap(&order[i],&order[j]);
															 
        	} 
    	} 
    	swap(&arr[i + 1], &arr[high]); 
	swap(&order[i+1],&order[high]);
    	return (i + 1); 
} 
void swap(int* a, int* b) 
{ 
    	int t = *a; 
    	*a = *b; 
    	*b = t; 
} 

float MRT(int array[10],int n)
{
	
	float m=n;
	float result,sum;
	for(int i=0;i<n;i++)
	{
		sum=array[i]*m+sum;
		m=n-i-1;
	}
	result=sum/n;
	return result;


}


