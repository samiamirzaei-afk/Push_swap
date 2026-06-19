#include "push.h"

short ft_issymbol(int num)
{
	if(num == '-' || num == '+' || num == FLAG_SYMBOL)	
		return(1);
	return(0);
}
