
#include "push.h" 

short	ft_array_check(int *array, int size)
{
	int i;
	int k;
	i = 0;
	while(i < size - 1)
	{
		k = i + 1;
		while(k < size)
		{
//	printf("comapring index[%d] & [%d] are the same: %d | %d\n",i , k, array[i], array[k]);
			if(array[i] == array[k])
			{
	printf("*** ERROR ***\nindex[%d] & [%d] are the same: %d | %d\n",i , k, array[i], array[k]);
				return(-1);
			}
			k++;
		}
		i++;
	}
	return(1);
}
