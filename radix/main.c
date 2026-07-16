/*
	1- scan through the list and find the smallest number.
	2- if a[0] > a[1], SA
	3-RRA to get the smallest possible number to a[0], then push to stack B.
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


void	ft_show_two(int *arrayA, int *arrayB, int size)
{
	int i;
	i = 0;

	while(i < size)
	{
		printf("arrayA[%d]=%d\n", i, arrayA[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while(i < size)
	{
		printf("arrayB[%d]=%d\n", i, arrayB[i]);
		i++;
	}
	printf("\n");
}

void	ft_show_one(int *arraya, int size)
{
	int i;
	i = 0;

	while(i < size)
	{
		printf("arrayA[%d]=%d\n", i, arraya[i]);
		i++;
	}
	printf("\n");
	i = 0;
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


int ft_small_2(int *array, int size, int *small_i)
{
	int small;
	int i;
	int save;
	int current;

	i = 0;
	small = array[*small_i];
	current = array[i];
	if(current == small)
		i++;
	save = array[i];
	while(i < size)
	{
		current = array[i];
		if(current < save && current > small)
		{
			save = array[i];
			*small_i = i;
		}
		i++;
	}
	return(save);
}


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


int **ft_free_rad(int **result, int i)
{
	while(i > 0)
	{
		free(result[i]);
		i--;
	}
	free(result);
}

int	**ft_double_array(int size_a)
{
	int **result;
	int i;

	result = malloc(size_a * sizeof(int*));
	if(result == NULL)
		return(NULL);
	i = 0;
	while(i < size_a)
	{
		result[i] = malloc(1 * sizeof(int));
		if(result[i] == NULL)
			return(ft_free_rad(result, i));
		i++;
	}
	return(result);
}
void	ft_print_radix(int **array, int size)
{
	int i;

	for(i = 0; i < size; i++)
		printf("array[%d]=%d\n", i, array[i][0]);
}

void	ft_radix(int *array_a, int *array_b, int size_a)
{
	int **array_radix;
	int size_b;
	int i;
	int smallest;
	int small_i;

	smallest = 0;
	size_b = -1;

	array_radix = ft_double_array(size_a); 

	i = 0;
	array_radix[i++][0] = ft_small(array_a, size_a, &small_i);
	while(i < size_a - 1)
	{
		array_radix[i++][0] = ft_small_2(array_a, size_a, &small_i);
	}
	array_radix[i][0] = ft_big(array_a, size_a);
	ft_print_radix(array_radix, size_a);	


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
