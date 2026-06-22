#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


// 0 1 2 3 
// 5 3 2 1  (5)
// 3 3 2 1
// 3 2 2 1
// 3 2 1 1

void	ft_show(int *arraya, int size)
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
// 1 2 3
// 3 4 1
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

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("please provide an argument");
		return (1);
	}
	
	int size;
	int *array_a;
	int i;
	int k;
	i = 1;
	k = 0;

	size = argc - 1;
	array_a = malloc(size * sizeof(int));
	while(argv[i] != NULL)
	{
		array_a[k] = atoi(argv[i]);
		i++;
		k++;
	}
	i = 0;

	ft_show(array_a, size);

	ft_rra(array_a, size);
	ft_show(array_a, size);
	return(0);


}
