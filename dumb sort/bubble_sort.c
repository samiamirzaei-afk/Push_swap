/*

int temp
5 - 3
temp = 3
3 - 2

	5 3 2 7 9 6 4 1
	3 5 2 7 9 6 4 1
	1 3 5 2 7 9 6 4
	3 5 2 7 9 6 4   (1)
	4 3 5 2 7 9 6	(1)
	3 4 5 2 7 9 6	(1)
	6 3 4 5 2 7 9	(1)
	3 6 4 5 2 7 9	(1)
	9 3 6 4 5 2 7	(1)
	3 9 6 4 5 2 7	(1)
	7 3 9 6 4 5 2   (1)
	3 7 9 6 4 5 2	(1)
	2 3 7 9 6 4 5	(1)
	3 7 9 6 4 5     (2 1)
	7 9 6 4 5	(3 2 1)
	5 7 9 6 4	(3 2 1)
	4 5 7 9 6 	(3 2 1)
	5 7 9 6		(4 3 2 1)
	7 9 6		(5 4 3 2 1)
	6 7 9		(5 4 3 2 1)
	7 9		(6 5 4 3 2 1)
	9		(7 6 5 4 3 2 1)
			(9 7 6 5 4 3 2 1)
	9
	7 9
	6 7 9
	5 6 7 9
	4 5 6 7 9
	3 4 5 6 7 9
	2 3 4 5 6 7 9
	1 2 3 4 5 6 7 9
	
	9 7 5 3 1 2 4 6 8
	7 9 5 3 1 2 4 6 8
	8 7 9 5 3 1 2 4 6
	7 8 9 5 3 1 2 4 6
	6 7 8 9 5 3 1 2 4
	4 6 7 8 9 5 3 1 2
	2 4 6 7 8 9 5 3 1
	1 2 4 6 7 8 9 5 3
	2 4 6 7 8 9 5 3 (1)
	4 6 7 8 9 5 3 (2 1)
	3 4 6 7 8 9 5 (2 1)
	4 6 7 8 9 5 (3 2 1)
	6 7 8 9 5 (4 3 2 1)
	
	
	
	1 2 3 4 5 6 9 8 
	
	5 9 1 8 2 7 3 6 4
	9 5 1 8 2 7 3 6 4
	4 9 5 1 8 2 7 3 6
	6 4 9 5 1 8 2 7 3
	4 6 9 5 1 8 2 7 3
	3 4 6 9 5 1 8 2 7
	7 3 4 6 9 5 1 8 2
	3 7 4 6 9 5 1 8 2
	2 3 7 4 6 9 5 1 8
	8 2 3 7 4 6 9 5 1
	2 8 3 7 4 6 9 5 1
	1 2 8 3 7 4 6 9 5
	2 8 3 7 4 6 9 5 (1)
	8 3 7 4 6 9 5 (2 1)
	3 8 7 4 6 9 5 (2 1)
	8 7 4 6 9 5 (3 2 1)
	5 8 7 4 6 9 (3 2 1)
	9 5 8 7 4 6 (3 2 1)
	5 9 8 7 4 6 (3 2 1)
	6 5 9 8 7 4 (3 2 1)
	5 6 9 8 7 4 (3 2 1)
	4 5 6 9 8 7 (3 2 1)
	5 6 9 8 7 (4 3 2 1)
	6 9 8 7 (5 4 3 2 1)
	9 8 7 (6 5 4 3 2 1)
	8 9 7 (6 5 4 3 2 1)
	7 8 9 (6 5 4 3 2 1)
	8 9 (7 6 5 4 3 2 1)
	9 (8 7 6 5 4 3 2 1)
	(9 8 7 6 5 4 3 2 1)
	9
	8 9
	7 8 9
	6 7 8 9
	5 6 7 8 9
	4 5 6 7 8 9
	3 4 5 6 7 8 9
	2 3 4 5 6 7 8 9
	1 2 3 4 5 6 7 8 9
	
	
	
			
	 
	
	
	
	1 5 3 2 7 9 6 4
	5 3 2 7 9 6 4 	(1)	
	3 5 2 7 9 6 4 	(1)
	4 3 5 2 7 9 6   (1)
	3 4 5 2 7 9 6   (1)
	6 3 4 5 2 7 9   (1)
	3 6 4 5 2 7 9   (1)
	9 3 6 4 5 2 7   (1)
	3 9 6 4 5 2 7   (1)
	7 3 9 6 4 5 2   (1)
	3 7 9 6 4 5 2   (1)
	2 3 7 9 6 4 5   (1)
	3 7 9 6 4 5   (2 1)
	7 9 6 4 5   (3 2 1)
	5 7 9 6 4   (3 2 1)
	4 5 7 9 6   (3 2 1)
	5 7 9 6   (4 3 2 1)
	7 9 6   (5 4 3 2 1)
	6 7 9   (5 4 3 2 1)
	7 9   (6 5 4 3 2 1)
	9   (7 6 5 4 3 2 1)
	  (9 7 6 5 4 3 2 1)
	9   (7 6 5 4 3 2 1)
	7 9   (6 5 4 3 2 1)
	6 7 9   (5 4 3 2 1)
	5 6 7 9   (4 3 2 1)
	4 5 6 7 9   (3 2 1)
	3 4 5 6 7 9   (2 1)
	2 3 4 5 6 7 9   (1)
	1 2 3 4 5 6 7 9

	1- scan through the list and find the smallest number.
	2- if a[0] > a[1], SA
	3-RRA to get the smallest possible number to a[0], then push to stack B.

*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"

void	ft_show_two(int *arrayA, int *arrayB, int size)
{
	int i;
	i = 0;

	while(i < size)
	{
		printf("arrayA[%d]=%d\n", i, arrayA[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while(i < size)
	{
		printf("arrayB[%d]=%d\n", i, arrayB[i]);
		i++;
	}
}

void	ft_show_one(int *arraya, int size)
{
	int i;
	i = 0;

	while(i < size)
	{
		printf("arrayA[%d]=%d\n", i, arraya[i]);
		i++;
	}
	printf("\n");
	i = 0;
}


int ft_small(int *array, int size)
{
	int small;
	int i;

	i = 0;
	small = array[0];
	while(i < size)
	{
		if(small > array[i])
		{
				small = array[i];	
		}
		i++;
	}
//	printf("\nsmallest: %d\n", smallest);
	return(small);
}

//	5 3 2 7 9 6 4 1
void	ft_pb(int *arrayA, int *arrayB, int sizeA, int sizeB)
{
	int i;
	int swap;

	swap = array[0];
	
	i= 0;
	sizeA--;
	sizeB++;
	

}
void	ft_bubble(int *arrayA, int *arrayB, int sizeA)
{
	int smallest;
	int i;
	int sizeB;
	int full_size;

	full_size = sizeA;
	sizeB = 0;

	i = i;
	
	while(1)
	{
		smallest = ft_small(arrayA, sizeA);
		
		if((sizeA >= 2) && arrayA[0] > arrayA[1])
			ft_pb(arrayA, arrayB, sizeA, sizeB);
	}

}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("please provide an argument");
		return (1);
	}
	
	int size;
	int *arrayA;
	int *arrayB;
	int i;
	int k;
	i = 1;
	k = 0;

	size = argc - 1;
	arrayA = malloc(size * sizeof(int));
	arrayB = malloc(size * sizeof(int));
	while(argv[i] != NULL)
	{
		arrayA[k] = atoi(argv[i]);
		i++;
		k++;
	}
	i = 0;
	while(i < size)
	{
		arrayB[i] = 0;
		i++;
	}

	i = 0;

	ft_show(arrayA, arrayB, size);
	return(0);

	ft_bubble(arrayA, arrayB, size);

}
