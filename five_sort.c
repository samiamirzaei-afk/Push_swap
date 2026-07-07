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

void ft_three_sort_2(t_arrays *list, t_big_small var, short option)
{
	if(var.big_i == 1 && var.small_i == 0)
	{
		ft_rra(list, "rra\n", option);
		ft_swap((*list).array_a, "sa\n", option);
		return ;	
	}	
	if(var.big_i == 0 && var.small_i == 2)
	{
		ft_swap((*list).array_a, "sa\n", option);
		ft_rra(list, "rra\n", option);
		return ;	
	}	
}
void ft_three_sort(t_arrays list, short option)
{
	t_big_small var;

	ft_big_small(list.array_a, list.size_a, &var);
	if(var.big_i == 2 && var.small_i == 0)
		return ;
	if(var.big_i == 0 && var.small_i == 1)
	{
		ft_ra(&list, "ra\n", option);
		return ;	
	}	
	if(var.big_i == 1 && var.small_i == 2)
	{
		ft_rra(&list, "rra\n", option);
		return ;	
	}	
	if(var.big_i == 2 && var.small_i == 1)
	{
		ft_swap(list.array_a, "sa\n", option);
		return ;	
	}
	ft_three_sort_2(&list ,var, option);
}


void five_sort(t_arrays list, short option)
{
	int smallest;
	int small_i;

	ft_show_one(list.array_a, list.size_a + list.size_b);
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
				ft_ra(&list, "ra\n", option);
			else
				ft_rra(&list, "rra\n", option);
		}
	}
	ft_three_sort(list, option);
	while(list.size_b)
		ft_pa(&list, "pa\n", option);
	ft_show_one(list.array_a, list.size_a + list.size_b);
	return ;
}
