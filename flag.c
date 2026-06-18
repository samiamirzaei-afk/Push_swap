#include "push.h"

/*
--adaptive = 1
--complex = 2
--medium  = 3
--simple = 4
--bench = 5
*/

int flag_logic2(short *flags, short main, int i)
{
	if(main == 0)
	{
		flags[i - 1] = ADAPTIVE;
		return(1);
	}
	return(0);
}

int flag_logic(short *flags)
{
	int i;
	short main;
	short option;

	main = 0;
	option = 0;
	i = 0;
	while(i < FLAG_SIZE)
	{
		if(flags[i] != 0)
		{
			if(flags[i] <= SIMPLE && main == 1)
				return(-1);
			if(flags[i] == BENCH && option == 1)
				return(-1);
			if(flags[i] <= SIMPLE && main == 0)
				main = 1;
			if(flags[i] == BENCH && option == 0)
				option = 1;
		}
		i++;
	}
	return(flag_logic2(flags, main, i));
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
	if(!(ft_isdigit_plus(str[i])))
			return(-1);
	while(str[i] == FLAG_SYMBOL && i != 2)
			i++;
	if(i == 2 && ft_isalpha(str[i + 1]))
		return(ft_version_finder(&str[i]));
	if(!ft_isdigit(str[i]))
			return(-1);
	printf("passed str: %s\n", str);
	return(0);

}

int ft_flag(char **argv, short *flags)
{
	int i;
	int k;

	i = 1;
	k = 0;
	while(argv[i] != NULL)
	{
			flags[k] = ft_found_flag(argv[i]);
			if((flags[k]) == -1)
				return(-1);
			if((flags[k]) > 0)
					k++;
			if(k > FLAG_SIZE)
					return(-1);
			i++;
	}
	if(flag_logic(flags) == -1)
		return(-1);

	return(0);
}
