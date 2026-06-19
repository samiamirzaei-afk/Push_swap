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

	i = 0;
	mistake = 0;
	size_f = size;
	while(i <= size - 1)
	{
		if(array[i] > array[i+1])
				mistake += 1;
		i++;
	}
	return(mistake / (size_f - 1));
}
