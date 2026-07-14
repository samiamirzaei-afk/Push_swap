#include "push.h"

void	ft_fill_array(int argc, char **argv, int **result)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < argc)
	{
		while(argv[i] && !ft_isdigit_str(argv[i]))
		{
			i++;
		}
		if(argv[i] == NULL)
			break;
		(*result)[k] = ft_atoi(argv[i]);
		i++;
		k++;
	}
}

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
	result = malloc((argc - (k)) *sizeof(int));
	if(!result)
		return(NULL);
	*size = (argc - k);
	ft_fill_array(argc, argv, &result);
	return(result);
}

