#include "push.h"

int	*ft_argv_to_array(int argc, char **argv, int *size)
{
	int i;
	int k;
	int *result;

	k = 0;
	i = 0;
	while(argv[i] != NULL)
	{
		if(!ft_isdigit_str(argv[i]))
			k++;
		i++;
	}
	i = 0;
	
	printf("size: '%d'\n", (argc - (k)));
	result = malloc((argc - (k)) *sizeof(int));
	if(!result)
		return(NULL);
	*size = (argc -k);
	i = 0;
	k = 0;
//	printf("argc: %d\n", argc);
	while (i < argc)
	{
		while(argv[i] && !ft_isdigit_str(argv[i]))
		{
//			printf("skipping argv[%d]= %s\n", i, argv[i]);
			i++;
		}
//		printf("i: %d\n", i);
		if(argv[i] == NULL)
			break;
		result[k] = ft_atoi(argv[i]);
//		printf("adding argv[%d] '%s' to result[%d]= %d\n", i, argv[i],k , result[k]);
		i++;
		k++;
	}
	i = 0;
///*
	while(i < k)
	{
		printf("result[%d]:%d\n", i, result[i]);
		i++;
	}
//*/
	return(result);

}

