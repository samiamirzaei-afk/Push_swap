#include "push.h"

void	ft_rb(t_arrays *list, char *command, short option, t_ops **all_ops)
{
	int temp;
	int i;
	int size;

	size = (*list).size_b;
	if(command[0] == '-')
		size = (*list).size_a + (*list).size_b;
	i = 0;
	temp = (*list).array_b[0];
	while(i < size - 1)
	{
		(*list).array_b[i] = (*list).array_b[i + 1];
		i++;
	}
	(*list).array_b[i] = temp;
	if(command[0] == '-')
            return ;
	if(option == BENCH)
	{
		(*all_ops)->rb++;
		write(1, command, 3);
		return ;
	}
	write(1, command, 3);
}

void	ft_rrb(t_arrays *list, char *command, short option, t_ops **all_ops)
{
	int temp;
	int i;

	i = (*list).size_b - 1;
	temp = (*list).array_b[(*list).size_b - 1];
	while(0 < i)
	{
		(*list).array_b[i] = (*list).array_b[i - 1];
		i--;
	}
	(*list).array_b[0] = temp;
	if(command[0] == '-')
			return ; 
	if(option == BENCH)
	{
		(*all_ops)->rrb++;
		write(1, command, 4);
		return ;
	}
	write(1, command, 4);
}
