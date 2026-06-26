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

void	ft_bubble(int *array_a, int *array_b, int size_a)
{
	int smallest;
	int small_i;
	int size_b;

	if(size_a <= 5)
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

void	bubble_main(int *array_a, int size)
{
	
	int *array_b;
	int i;
	i = 1;

	array_b = malloc((size + 1) * sizeof(int));
	if(!array_b)
		free(array_a);
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
