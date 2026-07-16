#include "t_head.h"


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


int **ft_free_rad(int **result, int i)
{
	while(i > 0)
	{
		free(result[i]);
		i--;
	}
	free(result);
	return(NULL);
}

int **ft_double_array(int size_a)
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

void    ft_print_radix(int **array, int size)
{
    int i;

    for(i = 0; i < size; i++)
        printf("array[%d]=%d\n", i, array[i][0]);
}


