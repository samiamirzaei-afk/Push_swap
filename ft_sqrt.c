#include "push.h"

int sqrt_low(int nb)
{
	int i;
	int answer;

	if(nb <= 3)
		return(1);
	i = 2;
	while(1)
	{
		answer = i * i;
		if(nb == answer)
			return(i);
		if(answer > nb)
			return(i - 1);
		i++;	
	}
}

int sqrt_mid(int nb)
{
	int i;
	int answer;

	i = 10;
	while(1)
	{
		answer = i * i;
		if(nb == answer)
			return(i);
		if(answer > nb)
			return(i - 1);
		i++;	
	}
}

int sqrt_high(int nb)
{
	int i;
	int answer;

	i = 20;
	while(1)
	{
		answer = i * i;
		if(nb == answer)
			return(i);
		if(answer > nb)
			return(i - 1);
		i++;	
	}
}


int ft_sqrt_start(int nb)
{
	if(nb <= 100)
		return(sqrt_low(nb));
	if(nb <= 400)
		return(sqrt_mid(nb));
	return(sqrt_high(nb));
}

/*
int ft_sqrt(int nb)
{
	
	i = nb - 1;
	while( i > 1)
	{
		if(nb % i == 0)
		{
			if(i * i == nb)
				return(i);
		}	
		i--;
	}
	if( i > 2)
	{
		answer = i;
		return(i);
	}
	return(-1);
}

int	main(int argc, char **argv)
{
	int answer;
	int k = 0;

	if(argc < 2)
		return(printf("no argcs\n"));


	answer = ft_sqrt_start(atoi(argv[1]));
	printf("closes to %s is %d[%d]\n", argv[1], answer, answer * answer);

	i = -1
	while(i != 1000)
	{
		answer = ft_sqrt(i);
		if(answer > 0)
		{
			printf("√%d =%d\n", i, answer);
			k++;
		}
		i++;
		if(k % 5 == 0)
		{
			printf("\n");
			k = 1;
		}

	}

}
*/
