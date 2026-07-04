#include "push.h"

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

void ft_three_sort_2(int *array_a, int size_a, t_big_small list, short option)
{
	if(list.big_i == 1 && list.small_i == 0)
	{
		ft_rra(array_a, size_a, "rra\n", option);
		ft_swap(array_a, "sa\n", option);
		return ;	
	}	
	if(list.big_i == 0 && list.small_i == 2)
	{
		ft_swap(array_a, "sa\n", option);
		ft_rra(array_a, size_a, "rra\n", option);
		return ;	
	}	
}
void ft_three_sort(int *array_a, int size_a, short option)
{
	t_big_small list;

	ft_big_small(array_a, size_a, &list);
	if(list.big_i == 2 && list.small_i == 0)
		return ;
	if(list.big_i == 0 && list.small_i == 1)
	{
		ft_ra(array_a, size_a, "ra\n", option);
		return ;	
	}	
	if(list.big_i == 1 && list.small_i == 2)
	{
		ft_rra(array_a, size_a, "rra\n", option);
		return ;	
	}	
	if(list.big_i == 2 && list.small_i == 1)
	{
		ft_swap(array_a, "sa\n", option);
		return ;	
	}
	ft_three_sort_2(array_a, size_a, list, option);
}


void five_sort(t_arrays list, short option)
{
	int smallest;
	int small_i;

	list.size_b = 0;
	while(list.size_a > 3)
	{
		smallest = ft_small(list.array_a, list.size_a, &small_i);
		if(list.array_a[0] == smallest)
			ft_pb(&list, "pb\n", option);
		smallest = ft_small(list.array_a, list.size_a, &small_i);
		if ((list.array_a[0] != smallest && list.size_a > 3))
		{
			if(small_i <= (list.size_a / 2))
				ft_ra(list.array_a, list.size_a, "ra\n", option);
			else
				ft_rra(list.array_a, list.size_a, "rra\n", option);
		}
	}
	ft_three_sort(list.array_a, list.size_a, option);
	while(list.size_b)
		ft_pb(&list, "pa\n", option);
	return ;
}
