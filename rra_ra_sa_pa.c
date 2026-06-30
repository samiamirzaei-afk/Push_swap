#include "push.h"

void	ft_ra(int *array_a, int size, char *command)
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
	if(command[0] != '-')
		write(1, command, 3);
}

void	ft_rra(int *array_a, int size, char *command)
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
	if(command[0] != '-')
		write(1, command, 4);
}

void ft_swap(int *array)
{
	int temp;

	temp = array[0];
	array[0] = array[1];
	array[1] = temp;
	write(1, "sa\n", 3);
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
