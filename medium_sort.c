#include "push.h"

static int	ft_find_min_index(int *array_a, int size_a)
{
	int	min;
	int	min_index;
	int	i;

	min = array_a[0];
	min_index = 0;
	i = 1;
	while (i < size_a)
	{
		if (array_a[i] < min)
		{
			min = array_a[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

static void	ft_rotate_min_to_top(int *array_a, int size_a, int min_index)
{
	while (min_index > 0)
	{
		ft_ra(array_a, size_a, "ra\n");
		min_index--;
	}
	while (min_index < 0)
	{
		ft_rra(array_a, size_a, "rra\n");
		min_index++;
	}
}

static void	ft_push_min_to_b(int *array_a, int *array_b, int *size_a, int *size_b)
{
	int	min_index;

	min_index = ft_find_min_index(array_a, *size_a);
	if (min_index <= *size_a / 2)
		ft_rotate_min_to_top(array_a, *size_a, min_index);
	else
		ft_rotate_min_to_top(array_a, *size_a, min_index - *size_a);
	ft_pb(array_a, array_b, size_a, size_b, "pb\n");
}

static void	ft_push_back_to_a(int *array_a, int *array_b, int *size_a, int *size_b)
{
	while (*size_b > 0)
		ft_pb(array_b, array_a, size_b, size_a, "pa\n");
}

void	ft_sqrt_sort(int *array_a, int size)
{
	int	*array_b;
	int	size_a;
	int	size_b;

	if (size <= 1)
		return ;
	array_b = malloc(sizeof(int) * (size + 1));
	if (!array_b)
		return ;
	memset(array_b, 0, sizeof(int) * (size + 1));
	size_a = size;
	size_b = 0;
	while (size_a > 0)
		ft_push_min_to_b(array_a, array_b, &size_a, &size_b);
	ft_push_back_to_a(array_a, array_b, &size_a, &size_b);
	free(array_b);
}
