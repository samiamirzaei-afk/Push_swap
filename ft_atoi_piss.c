#include <unistd.h>
#include <stdio.h>

int	ft_np_check(char *str, int *i)
{
	int negative_i;

	negative_i = 0;
	while(str[*i] == '+' || str[*i] == '-')
	{
		if(str[*i] == '-')
			negative_i++;
		*i = *i + 1;
	}
	if(negative_i % 2 != 0)
		return (-1);
	return(1);
}

void	ft_isspace(char *str, int *i)
{
	while (str[*i] >= '\t' && str[*i] <= '\r' || str[*i] == ' ')
		*i = *i + 1;
}

int	ft_atoi(char *str)
{
	int i;
	int n_p;
	int result;

	i = 0;
	n_p = 1;
	result = 0;
	ft_isspace(str, &i);
	n_p = ft_np_check(str, &i);
	while(str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if(n_p == -1)
		return(result * -1);
	return(result);
}

int	main(int argc, char ** argv)
{
	if (argc != 2)
	{
		printf("need one argument\n");
		return (1);
	}
	int	result;
	result = ft_atoi(argv[1]);
	printf("result: '%d'", result);
}
