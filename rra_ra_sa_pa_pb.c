#include "push.h"

void	ft_ra(t_arrays *list, char *command, short option, t_ops **all_ops)
{
	int temp;
	int i;
	int size;

	size = (*list).size_a;
	if(command[0] == '-')
		size = (*list).size_a + (*list).size_b;
	i = 0;
	temp = (*list).array_a[0];
	while(i < size - 1)
	{
		(*list).array_a[i] = (*list).array_a[i + 1];
		i++;
	}
	(*list).array_a[i] = temp;
	if(command[0] == '-')
            return ;
	if(option == BENCH)
	{
		(*all_ops)->ra++;
		write(2, command, 3);
		return ;
	}
	write(1, command, 3);
}

void	ft_rra(t_arrays *list, char *command, short option, t_ops **all_ops)
{
	int temp;
	int i;

	i = (*list).size_a - 1;
	temp = (*list).array_a[(*list).size_a - 1];
	while(0 < i)
	{
//		printf("array_a[%d]:%d = array_[%d]: %d\n ", i, (*list).array_a[i], i - 1, (*list).array_a[i - 1]);
		(*list).array_a[i] = (*list).array_a[i - 1];
		i--;
	}
	(*list).array_a[0] = temp;
	if(command[0] == '-')
			return ; 
	if(option == BENCH)
	{
		(*all_ops)->rra++;
		write(2, command, 4);
		return ;
	}
	write(1, command, 4);
}

void ft_swap(int *array, char *command, short option, t_ops **all_ops)
{
	int temp;

	temp = array[0];
	array[0] = array[1];
	array[1] = temp;
	if(option == BENCH)
	{
		(*all_ops)->sa++;
		write(2, command, 3);
		return ;
	}
	write(1, command, 3);
}

void	ft_pa(t_arrays *list, char *command, short option, t_ops **all_ops)
{
	int i;
	int swap;
	
	if((*list).size_b == 0)
		return ;
	swap = (*list).array_b[0];
	(*list).array_b[0] = 0;
	((*list).size_b)--;
	((*list).size_a)++;
	ft_ra(list, "-", option, all_ops);
	i = (*list).size_a;
	while(0 < i && ( (*list).size_a != 0 && (*list).size_b != 0))
	{
		(*list).array_a[i] = (*list).array_a[i - 1];
		i--;
	}
	i = (*list).size_b;
	(*list).array_a[0] = swap;
	if(option == BENCH)
	{
		(*all_ops)->pa++;
		write(2, command, 3);
		return ;
	}
	write(1, command, 3);
}
void	ft_pb(t_arrays *list, char *command, short option, t_ops **all_ops)
{
	int i;
	int swap;
	
	if((*list).size_a == 0)
		return ;
	swap = (*list).array_a[0];
	(*list).array_a[0] = 0;
	((*list).size_a)--;
	((*list).size_b)++;
	ft_ra(list, "-", option, all_ops);
	i = (*list).size_b;
	while(0 < i && ( (*list).size_a != 0 && (*list).size_b != 0))
	{
		(*list).array_b[i] = (*list).array_b[i - 1];
		i--;
	}
	i = (*list).size_a;
	(*list).array_b[0] = swap;
	if(option == BENCH)
	{
		(*all_ops)->pb++;
		write(2, command, 3);
		return ;
	}
	write(1, command, 3);
}
