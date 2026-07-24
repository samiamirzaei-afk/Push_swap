#include "push.h"


int ft_max_bits(int num)
{
	char str[33];
	int i;
	int j;
	
	i = 0;
	j = 0;
	str[32] = '\0';
	while(i < 32)
	{
		if(((num >> i) & 1) == 0)
			str[i] = '0';
		else
			str[i] = '1';
		i++;
	}
	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == '1')
			j = i;
		i++;
	}
	return (j + 1);
}

int ft_next_small(int *array, int size, int smallest)
{
    int i;
    int next_smallest;

    i = 0;
    next_smallest = 0;
    while (i < size)
    {
        if (array[i] > smallest)
        {
            next_smallest = array[i];
            break;
        }
        i++;
    }
    i = 0;
    while (i < size)
    {
        if (array[i] > smallest && array[i] < next_smallest)
            next_smallest = array[i];
        i++;
    }
    return (next_smallest);
}

int radix_indexer_2(t_list **head, int *array, int size, t_rain *va)
{
	va->i = 0;
	va->k = 0;
	while(va->i < size - 1)
	{
		va->ptr = *head;
		va->small = ft_next_small(array, size, va->small);
		va->j = 0;
		while(va->j < size)
		{
			if(va->small == va->ptr->num)
			{	
				va->ptr->index = (va)->k++;
				break;
			}
			va->ptr = va->ptr->next;
			va->j++;
		}
		va->i++;
	}
	return(va->k);
}
int radix_indexer(t_list **head, int *array, int size)
{
	t_rain va;
	
	va.k = 0;
	va.small_i = 0;
	va.j = 0;
	va.ptr = *head;
	va.small = ft_small(array, size, &va.small_i);
	while(va.j < size)
	{
		if(va.small == va.ptr->num)
		{	
				va.ptr->index = va.k++;
				break;
		}
		va.j++;
		va.ptr = va.ptr->next;
	}
	return(radix_indexer_2(head, array, size, &va));
}

int	radix_main_2(t_aso *ar, t_rava *va, t_ops **all_ops)
{

	va->i = 0;
	va->j = 0;
	while(va->i < va->max_bits)
	{
		va->j = 0;
		while(va->j < ar->size && va->list_a != NULL)
		{
			if ((((va->list_a->index >> va->i) & 1) != 0))
				list_rotate_a(&va->list_a, ar->option, all_ops);
			else
				list_pb(&va->list_a, &va->list_b, ar->option, all_ops);
			va->j++;
		}
		while(va->list_b != NULL)
			list_pa(&va->list_a, &va->list_b, ar->option, all_ops);
		va->i++;
	}
	return(ft_lstclear(&va->list_a), free(ar->array), 1);
}

int	radix_main(int *array, int size, short option, t_ops **all_ops)
{
	t_rava va;
	t_aso ar;

	if(size <= 5)
		return(bubble_main(array, size, option, all_ops), 1);
	va.list_a = NULL;
	va.list_b = NULL;
	if(list_maker(array, size, &va.list_a) == 0)
			return(free(array), write(1, "Error_C\n", 8), -1);
	va.big = radix_indexer(&va.list_a, array, size);
	va.max_bits = ft_max_bits(va.big);
	ar.array = array;
	ar.size = size;
	ar.option = option;
	return(radix_main_2(&ar, &va, all_ops));
}
