#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m, n, i, j;
	printf("Enter the dimensions of the matrices:- ");
	scanf("%d %d", &m, &n);
	int  *A= (int *)malloc(m* n* sizeof(int));
	int  *B= (int *)malloc(m* n* sizeof(int));
	int  *C= (int *)malloc(m* n* sizeof(int));
	
	printf("Enter the elements in matrix A:-\n");
	for( i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%d", A+ i*n + j);
		}
	}
	printf("Enter the elements in matrix B:-\n");
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%d", B+ i*n + j);
		}
	}
	printf("Sparse matrix of A:-\nRow\tcolumn\tvalue\n");
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
		    if(*(A+ i*n + j)!= 0)
		    {
		    	printf("%d\t%d\t%d\n", i+1, j+1, *(A+ i*n + j));
			}
		}
	}
	printf("Sparse matrix of B:-\nRow\tcolumn\tvalue\n");
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
		    if(*(B+ i*n + j)!= 0)
		    {
		    	printf("%d\t%d\t%d\n", i+1, j+1, *(B+ i*n + j));
			}
		}
	}
	printf("Sum of A and B is:-\n");
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
		    if(*(A+ i*n + j)!= 0 || *(B+ i*n + j)!= 0)
		    {
		    	*(C+ i*n + j)= *(A+ i*n + j)+ *(B+ i*n + j);
		    	printf("%d\t%d\t%d\n", i+1, j+1, *(C+ i*n + j));
			}
		}
	}
	return 0;
}
