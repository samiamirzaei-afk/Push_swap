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
#include <unistd.h>

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
	printf("\n");
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
//				*index = i;
		}
		i++;
	}
//	printf("\nsmallest: %d\n", smallest);
	return(small);
}

void	ft_pb(int *array_a, int *array_b, int *size_a, int *size_b, char *command)
{
	int i;
	int swap;
	
	if(*size_a == 0)
		return ;
	swap = array_a[0];
	array_a[0] = 0;
	(*size_a)--;
	(*size_b)++;
	
//	if(small_p <= ((*size_a + *size_b)/2))
//		ft_rra(array_a, (*size_a + *size_b), "-");
//	else
	ft_ra(array_a, (*size_a + *size_b), "-");
	i = *size_b;
	while(0 < i)
	{
		array_b[i] = array_b[i - 1];
		i--;
	}
	i = *size_a;
	array_b[0] = swap;
	write(1, &command[0], 3);
}

void ft_swap(int *array)
{
	int temp;

	temp = array[0];
	array[0] = array[1];
	array[1] = temp;
	write(1, "sa\n", 3);

}
// 
void	ft_bubble(int *array_a, int *array_b, int size_a)
{
	int smallest;
	int small_p;
	int i;
	int size_b;
	int full_size;

	full_size = size_a;
	size_b = 0;

	i = 0;
//	printf("full: %d\n", full_size);


	while(1)
	{
		smallest = ft_small(array_a, size_a);
		
		if((size_a >= 2) && array_a[0] > array_a[1])
				ft_swap(array_a);
		if(array_a[0] == smallest)
		{
			ft_pb(array_a, array_b, &size_a, &size_b, "pb\n");
			smallest = ft_small(array_a, size_a);
		}
		if(size_a == 0)
				break ;

		if ((array_a[0] != smallest))
				ft_ra(array_a, (size_a + size_b), "-");
/*		if ((array_a[0] != smallest))
		{
			if(small_p <= ((size_a + size_b)/2))
				ft_rra(array_a, (size_a + size_b), "-");
			else
				ft_ra(array_a, (size_a + size_b), "-");
		}
*/
	}
	while(size_b)
	{
		ft_pb(array_b, array_a, &size_b, &size_a, "pa\n");
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("please provide an argument");
		return (1);
	}
	
	int size;
	int *array_a;
	int *array_b;
	int i;
	int k;
	i = 1;
	k = 0;

	size = argc - 1;
	array_a = malloc(size * sizeof(int));
	array_b = malloc(size * sizeof(int));
	while(argv[i] != NULL)
	{
		array_a[k] = atoi(argv[i]);
		i++;
		k++;
	}
	i = 0;
	while(i < size)
	{
		array_b[i] = 0;
		i++;
	}

	i = 0;

//	ft_show_two(array_a, array_b, size);

	ft_bubble(array_a, array_b, size);
//	ft_show_two(array_a, array_b, size);

}
