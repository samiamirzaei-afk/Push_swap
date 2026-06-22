void	ft_ra(int *array_a, int size)
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
}

void	ft_rra(int *array_a, int size)
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
}
