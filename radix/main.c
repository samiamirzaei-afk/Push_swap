/*
	1- scan through the list and find the smallest number.
	2- if a[0] > a[1], SA
	3-RRA to get the smallest possible number to a[0], then push to stack B.
*/

#include "t_head.h"


int ft_small(int *array, int size, int *small_i)
{
	int small;
	int i;

	i = 0;
	*small_i = 0;
	small = array[0];
	while(i < size)
	{
		if(small > array[i])
		{
			small = array[i];	
			*small_i = i;
		}
		i++;
	}

	return(small);
}


int ft_big(int *array, int size)
{
	int big;
	int i;

	i = 0;
	big = array[0];
	while(i < size)
	{
		if(big < array[i])
			big = array[i];	
		i++;
	}
	return(big);
}
/*
       // 0 1 2 3 4 5 6 7 
	  9 8 1 4 2 5 7 4
	small = 1
	index = 2
	save = 2
	current = 7
	
	current && save > small;
	current && save == 9
	//
	while(i <  size - 1)
{
	current = 2
	current < save : save = current;
}	
	a[i] != a[index];
	
*/

int ft_small_2(int *array, int size, int smallest)
{
    int i;
    int next_smallest;

    i = 0;
    next_smallest = 0;
    while (i < size)
    {
        if (array[i] > smallest)
        {
            next_smallest = array[i];
            break;
        }
        i++;
    }
    i = 0;
    while (i < size)
    {
        if (array[i] > smallest && array[i] < next_smallest)
            next_smallest = array[i];
        i++;
    }
    return (next_smallest);
}
// 1 3 8 7

int ft_max_bits(int num)
{
	char str[33];
	int i;
	int j;
	
	i = 0;
	j = 0;

	str[32] = '\0';
	
	while(i < 32)
	{
		if(((num >> i) & 1) == 0)
			str[i] = '0';
		else
			str[i] = '1';
		i++;
	}
	printf("str: %s\n", str);
	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == '1')
			j = i;
		i++;
	}
	return (j + 1);
}



void	ft_radix(int *array_a, int *array_b, int size_a)
{
	int **array_radix;
	int size_b;
	int i;
	int smallest;
	int small_i;
	int small;
	int big;
	int max_bit;

	smallest = 0;
	size_b = -1;

	big = ft_big(array_a, size_a);
	max_bit = ft_max_bits(big);
	
	printf("max[%d] bits:%d \n",big, max_bit);
	
	return;

/*
	array_radix = ft_double_array(size_a); 

	i = 0;
	array_radix[i++][0] = ft_small(array_a, size_a, &small_i);
	small = array_a[small_i];
	while(i < size_a - 1)
	{

		small = ft_small_2(array_a, size_a, small);
		array_radix[i++][0] = small;
	}
	array_radix[i][0] = ft_big(array_a, size_a);
	ft_print_radix(array_radix, size_a);	
	ft_free_rad(array_radix, size_a);
*/
}


int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("please provide an argument");
		return (1);
	}
	
	int size;
	int *array_a;
	int *array_b;
	int i;
	int k;
	i = 1;
	k = 0;

	size = argc - 1;
	array_a = malloc((size + 1) * sizeof(int));
	if(!array_a)
		return(0);
	array_b = malloc((size + 1) * sizeof(int));
	if(!array_b)
		return(free(array_a), 0);
	while(argv[i] != NULL)
	{
		array_a[k] = atoi(argv[i]);
		i++;
		k++;
	}
	i = 0;
	while(i < size)
	{
		array_b[i] = 0;
		i++;
	}

	i = 0;

	ft_show_two(array_a, array_b, size);
	ft_radix(array_a, array_b, size);
	free(array_a);
	free(array_b);
}
