/*
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


int ft_small(int *array, int size, int *small_i)
{
	int small;
	int i;

	i = 0;
	*small_i = 0;
	small = array[0];
	while(i < size)
	{
		if(small > array[i])
		{
				small = array[i];
				*small_i = i;
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
	int small_i;
	int size_b;

	if(size_a == 5)
		return(five_sort(array_a, array_b, size_a));
	size_b = 0;

	while(1)
	{
		smallest = ft_small(array_a, size_a, &small_i);
		if((size_a >= 2) && array_a[0] > array_a[1])
			ft_swap(array_a);
		if(array_a[0] == smallest)
			ft_pb(array_a, array_b, &size_a, &size_b, "pb\n");
		if(size_a == 0)
			break ;
		smallest = ft_small(array_a, size_a, &small_i);
		if ((array_a[0] != smallest))
		{
			if(small_i <= (size_a / 2))
				ft_ra(array_a, size_a, "ra\n");
			else
				ft_rra(array_a, size_a, "rra\n");
		}
	}
	while(size_b)
		ft_pb(array_b, array_a, &size_b, &size_a, "pa\n");

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
	array_a = malloc((size + 1) * sizeof(int));
	if(!array_a)
		return(0);
	array_b = malloc((size + 1) * sizeof(int));
	if(!array_b)
		return(free(array_a), 0);
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
//	ft_show_one(array_a, size);
	free(array_a);
	free(array_b);

}
