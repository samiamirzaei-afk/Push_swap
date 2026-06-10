#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#include "push.h"

int	*ft_argv_to_array(int argc, char **argv, int *size)
{
	int i;
	int k;
	int *result;

	result = malloc((argc - 3) *sizeof(int));
	if(!result)
		return(NULL);
	i = 2;
	k = 0;
	while (i < argc)
	{
		result[k] = atoi(argv[i]);
		i++;
		k++;
	}
	*size = k;	
//	printf("size: '%d'\n", k);
	k = 0;
/*
	while(k < argc - 1)
	{
		printf("result[%d]:%d\n", k, result[k]);
		k++;
	}
*/
	return(result);

}

