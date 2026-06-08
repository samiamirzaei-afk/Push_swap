
#include "push.h"

/*
--adaptive = 1
--complex = 2
--medium        = 3
--simple = 4
--bench = 5
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char)s1[i] != '\0' || (unsigned char)s2[i] != '\0')
		&& i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int ft_flag(char *str)
{
	int i;
	short result;

	i = 0;


	while(1)
	{
		result = ft_strncmp(str, ADA);
		if(result == 0)
			return(ADAPTIVE);
	
	}


}
