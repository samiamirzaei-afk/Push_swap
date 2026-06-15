
#include "push.h"

/*
--adaptive = 1
--complex = 2
--medium  = 3
--simple = 4
--bench = 5
*/

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}


int ft_version_finder(char *str)
{
	if(ft_strcmp(str, ADA) == 0)
			return(ADAPTIVE);
	if(ft_strcmp(str, COM) == 0)
			return(COMPLEX);
	if(ft_strcmp(str, MED) == 0)
			return(MEDIUM);
	if(ft_strcmp(str, SIM) == 0)
			return(SIMPLE);
	if(ft_strcmp(str, BEN) == 0)
			return(BENCH);
	return(-1);
}

int ft_found_flag(char *str)
{
	int i;
	
	i = 0;

	while(str[i] == '-')
			i++;
	if(i == 2)
		return(ft_version_finder(str));
	return(0);

}

int ft_flag(char **argv, short *flags)
{
	int i;
	int k;

	i = 1;
	k = 0;


	while(argv[i] != NULL && k < FLAG_SIZE)
	{
			flags[k] = ft_found_flag(argv[i]);
			if((flags[k]) == -1)
				return(-1);
			if((flags[k]) > 0)
					k++;
			i++;
	}
	return(0);
}
