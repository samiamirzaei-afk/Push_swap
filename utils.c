#include "push.h"

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

int	ft_isdigit_plus(int num)
{
	if ((num >= '0' && num <= '9') || num == FLAG_SYMBOL)
		return (1);
	return (0);
}

int	ft_isalpha(int number)
{
	if (number >= 'A' && number <= 'z')
	{
		if (!(number >= '[' && number <= '`'))
			return (1);
	}
	return (0);
}
