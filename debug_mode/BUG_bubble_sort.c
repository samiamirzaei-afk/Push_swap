/*
	1- scan through the list and find the smallest number.
	2- if a[0] > a[1], SA
	3-RRA or RA to get the smallest possible number to a[0], then push to stack B.
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "push.h"

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

void	ft_bubble(t_arrays list, short option, t_ops **all_ops)
{
	int smallest;
	int small_i;
	
	
	ft_show_two(list.array_a, list.array_b, list.size_a + list.size_b);
	while(1)
	{
		smallest = ft_small(list.array_a, list.size_a, &small_i);
		if((list.size_a >= 2) && list.array_a[0] > list.array_a[1])
			ft_swap(list.array_a, "sa\n", option, all_ops);
		if(list.array_a[0] == smallest)
			ft_pb(&list, "pb\n", option, all_ops);
		if(list.size_a == 0)
			break ;
		smallest = ft_small(list.array_a, list.size_a, &small_i);
		if ((list.array_a[0] != smallest))
		{
			if(small_i <= (list.size_a / 2))
				ft_ra(&list, "ra\n", option, all_ops);
			else
				ft_rra(&list, "rra\n", option, all_ops);
		}
	
		if(0 == ft_sort(list.array_a, list.size_a))
			break;
	}
	while(list.size_b)
		ft_pa(&list, "pa\n", option, all_ops);
	return ;
}

void	bubble_main(int *array_oa, int size, short option, t_ops **all_ops)
{
	t_arrays list;
	int i;
	
	i = 0;
	list.array_b = malloc((size + 1) * sizeof(int));
	if(!list.array_b)
		free(array_oa);
	while(i < size)
	{
		list.array_b[i] = 0;
		i++;
	}
	list.array_a = array_oa;
	list.size_a = size;
	list.size_b = 0;
	if(size <= 5)
		five_sort(list, option, all_ops);
	else
//	ft_show_two(list.array_a, list.array_b, list.size_a);
		ft_bubble(list, option, all_ops);
//	ft_show_two(list.array_a, list.array_b, list.size_a);
//	ft_show_one(list.array_a, list.size_a);
	free(list.array_a);
	free(list.array_b);
}
/*
void	bubble_main(int *array_a, int size, short option)
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

	if(size <= 5)
		five_sort(array_a, array_b, size, option);
	else
//	ft_show_two(array_a, array_b, size);
		ft_bubble(array_a, array_b, size, option);
//	ft_show_two(array_a, array_b, size);
//	ft_show_one(array_a, size);
	free(array_a);
	free(array_b);
}
*/
