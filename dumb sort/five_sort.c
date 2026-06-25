void ft_three_sort(int *array_a, int size_a)
{
	int small;
	int big;
	int small_i;
	int big_i;
	
	ft_big_small(small, small_i, big, big_i);


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
		if((size_a >= 2) && array_a[0] > array_a[1])
			ft_swap(array_a);
		if(array_a[0] == smallest)
			ft_pb(array_a, array_b, &size_a, &size_b, "pb\n");
		if(size_a == 0)
			break ;
		smallest = ft_small(array_a, size_a, &small_i);
		if ((array_a[0] != smallest))
		{
			if(small_i <= (size_a / 2))
				ft_ra(array_a, size_a, "ra\n");
			else
				ft_rra(array_a, size_a, "rra\n");
		}
	ft_three_sort(array_a, size_a);
	}
	while(size_b)
		ft_pb(array_b, array_a, &size_b, &size_a, "pa\n");

	return ;


}
