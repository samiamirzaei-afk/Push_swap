#include "push.h"

int	*ft_argv_to_array(int argc, char **argv, int *size)
{
	int i;
	int k;
	int *result;
	short flag_index[FLAG_SIZE];

	k = 0;
	i = 0;
	while(argv[i] != NULL && k < FLAG_SIZE)
	{
		if(ft_found_flag(argv[i]))
			flag_index[k] = i;
				k++;
		i++;
	}
	i = 0;

	result = malloc((argc - (2 + k)) *sizeof(int));
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
	printf("size: '%d'\n", k);
	k = 0;
///*
	while(k < argc - 2)
	{
		printf("result[%d]:%d\n", k, result[k]);
		k++;
	}
//*/
	return(result);

}

