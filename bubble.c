#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int	*ft_array(int argc, char **argv)
{
	int i;
	int k;
	int *result;

	result = malloc((argc - 1) *sizeof(int));
	if(!result)
		return(NULL);
	i = 1;
	k = 0;
	while (i < argc)
	{
		result[k] = atoi(argv[i]);
		i++;
		k++;
	}
	k = 0;
	while(k < argc - 1)
	{
		printf("result[%d]:%d\n", k, result[k]);
		k++;
	}
	return(result); 
}


int	main(int argc, char **argv)
{
        if (argc < 2)
        {
                printf ("please provide 2 or more numbers [...]\n");
                return (1);
        }
	int i;
	int *array;
	i = 1;

	array = ft_array(argc, argv);
	
}

