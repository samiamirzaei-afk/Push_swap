#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "head.h"

/*
	1 2 3
	
	1 3 2 RA
	2 1 3 sa
	1 2 3
	
	2 1 3 sa
	1 2 3
	
	2 3 1 ra
	1 2 3
	
	3 1 2 RRA
	1 2 3
	
	3 2 1 sa
	2 3 1 ra
	1 2 3
	
	
*/

void ft_big_small(int *array, int size, t_big_small *list) 
{
	int i;

	i = 0;
	list->small_i = 0;
	list->big = 0;
	list->big_i = 0;
	list->small = array[0];
	while(i < size)
	{
		if(list->small > array[i])
		{
				list->small = array[i];
				list->small_i = i;
		}
		if(list->big < array[i])
		{
				list->big = array[i];
				list->big_i = i;
		}
		i++;
	}
}


/*
        int small;
        int big;
        int small_i;
        int big_i
*/

void ft_three_sort_2(int *array_a, int size_a, t_big_small list)
{
	if(list.big_i == 1 && list.small_i == 0)
	{
		ft_rra(array_a, size_a, "rra\n");
		ft_swap(array_a);
		return ;	
	}	
	if(list.big_i == 0 && list.small_i == 2)
	{
		ft_swap(array_a);
		ft_rra(array_a, size_a, "rra\n");
		return ;	
	}	
}
void ft_three_sort(int *array_a, int size_a)
{
	t_big_small list;

	ft_big_small(array_a, size_a, &list);
	if(list.big_i == 2 && list.small_i == 0)
		return ;
	if(list.big_i == 0 && list.small_i == 1)
	{
		ft_ra(array_a, size_a, "ra\n");
		return ;	
	}	
	if(list.big_i == 1 && list.small_i == 2)
	{
		ft_rra(array_a, size_a, "rra\n");
		return ;	
	}	
	if(list.big_i == 2 && list.small_i == 1)
	{
		ft_swap(array_a);
		return ;	
	}
	ft_three_sort_2(array_a, size_a, list);
}


void five_sort(int *array_a, int *array_b, int size_a)
{
	int smallest;
	int small_i;
	int size_b;

	size_b = 0;
	while(size_a > 3)
	{
		smallest = ft_small(array_a, size_a, &small_i);
		if(array_a[0] == smallest)
			ft_pb(array_a, array_b, &size_a, &size_b, "pb\n");
		smallest = ft_small(array_a, size_a, &small_i);
		if ((array_a[0] != smallest && size_a > 3))
		{
			if(small_i <= (size_a / 2))
				ft_ra(array_a, size_a, "ra\n");
			else
				ft_rra(array_a, size_a, "rra\n");
		}
	}
	ft_three_sort(array_a, size_a);
	while(size_b)
		ft_pb(array_b, array_a, &size_b, &size_a, "pa\n");
	return ;
}
