#include "push.h"

void	ft_ra(int *array_a, int size, char *command, short option)
{
	int temp;
	int i;

	i = 0;
	temp = array_a[0];

	while(i < size - 1)
	{
		array_a[i] = array_a[i + 1];
		i++;
	}
	array_a[i] = temp;
	if(command[0] == '-')
		return ; 
	if(option == BENCH)
	{
		write(2, command, 4);
		return ;
	}
	write(1, command, 4);
}

void	ft_rra(int *array_a, int size, char *command, short option)
{
	int temp;
	int i;

	i = size;
	temp = array_a[size - 1];

	while(0 < i)
	{
		array_a[i] = array_a[i - 1];
		i--;
	}
	array_a[0] = temp;
	if(command[0] == '-')
		return ; 
	if(option == BENCH)
	{
		write(2, command, 4);
		return ;
	}
	write(1, command, 4);
}

void ft_swap(int *array, char *command, short option)
{
	int temp;

	temp = array[0];
	array[0] = array[1];
	array[1] = temp;
	if(option == BENCH)
	{
		write(2, command, 3);
		return ;
	}
	write(1, command, 3);
}

void	ft_pb(t_arrays *list, char *command, short option)
{
	int i;
	int swap;
	
	if((*list).size_a == 0)
		return ;
	swap = (*list).array_a[0];
	(*list).array_a[0] = 0;
	((*list).size_a)--;
	((*list).size_b)++;
	ft_ra((*list).array_a, ((*list).size_a + (*list).size_b), "-", option);
	i = (*list).size_b;
	while(0 < i && ( (*list).size_a != 0 && (*list).size_b != 0))
	{
		(*list).array_b[i] = (*list).array_b[i - 1];
		i--;
	}
	i = (*list).size_a;
	(*list).array_b[0] = swap;
	if(command[0] == '-')
		return ; 
	if(option == BENCH)
	{
		write(2, command, 3);
		return ;
	}
	write(1, command, 3);
}
