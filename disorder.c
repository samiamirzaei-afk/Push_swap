#include "push.h"

/*
function compute_disorder(stack a):
mistakes = 0
total_pairs = 0
for i from 0 to size(a)-1:
for j from i+1 to size(a)-1:
total_pairs += 1
if a[i] > a[j]:
mistakes += 1
return mistakes / total_pairs
*/

float ft_disorder(int *array, int size)
{
	float mistake;
	float size_f;
	int i;
	int j;

	i = 0;
	j = 0;
	mistake = 0;
	size_f = 0;
	while(i < size)
	{
		j = i + 1;
		while(j < size)
		{
//			printf("comparing [%d] with [%d]: %d | %d\n",i , i + 1, array[i], array[j]);
			if(array[i] > array[j])
				mistake++;
			size_f++;
			j++;
		}
//		printf("comparing [%d] with [%d]: %d | %d\n",i , i + 1, array[i], array[i+1]);
		i++;
	}
//	printf("mistake: [%f] / size_f [%f], = %f\n", mistake, size_f - 1, mistake / (size_f));
	return(mistake / (size_f));
}
