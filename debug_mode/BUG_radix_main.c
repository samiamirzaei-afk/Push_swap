#include "push.h"


//0 for value, 1 for index as well
void list_show_one(t_list **head, int option)
{
	int i;
	t_list *ptr;

	ptr = *head;
	if(option == 0)
	{
		for(i = 0; ptr != NULL; i++)
		{
			printf("list[%d]: %d\n", i , ptr->num);
			ptr = ptr->next;
		}
	}
	if(option == 1)
	{
		for(i = 0; ptr != NULL; i++)
		{
			printf("list[%d][i:%d] : %d\n", i , ptr->index, ptr->num);
			ptr = ptr->next;
		}
	}
	printf("\n");
}
//0 for value, 1 for index as well
void list_show_two(t_list **list_a, t_list **list_b, int option)
{
	int i;
	t_list *ptr;

	ptr = *list_a;
	if(option == 0)
	{
		for(i = 0; ptr != NULL; i++)
		{
			printf("list_A[%d]: %d\n", i , ptr->num);
			ptr = ptr->next;
		}
	}
	if(option == 1)
	{
		for(i = 0; ptr != NULL; i++)
		{
			printf("list_A[%d][i:%d] : %d\n", i , ptr->index, ptr->num);
			ptr = ptr->next;
		}
	}
	printf("\n");
	ptr = *list_b;
	if(option == 0)
	{
		for(i = 0; ptr != NULL; i++)
		{
			printf("list_B[%d]: %d\n", i , ptr->num);
			ptr = ptr->next;
		}
	}
	if(option == 1)
	{
		for(i = 0; ptr != NULL; i++)
		{
			printf("list_B[%d][i:%d] : %d\n", i , ptr->index, ptr->num);
			ptr = ptr->next;
		}
	}
	printf("\n");
}

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


int radix_indexer(t_list **head, int *array, int size)
{
	int small_i;
	int small;
	int i;
	int j;
	int k;

	t_list *ptr;
	k = 0;
	ptr = *head;
	small_i = 0;
	small = ft_small(array, size, &small_i);
	j = 0;
	while(j < size)
	{
		if(small == ptr->num)
		{	
				ptr->index = k++;
				break;
		}
		j++;
		ptr = ptr->next;
	}
	i = 0;
	while(i < size - 1)
	{
		ptr = *head;
		small = ft_next_small(array, size, small);
		j = 0;
		while(j < size)
		{
			if(small == ptr->num)
			{	
				ptr->index = k++;
				break;
			}
			ptr = ptr->next;
			j++;
		}
		i++;
	}
	return(k);
}

int	radix_main(int *array, int size, short option, t_ops **all_ops)
{
	t_list *list_a;
	t_list *list_b;
	int big;
	int max_bits;
	int i;
	int j;

	if(size <= 5)
		return(bubble_main(array, size, option, all_ops), 1);
	i = 0;
	j = 0;
	list_a = NULL;
	list_b = NULL;
	if(list_maker(array, size, &list_a) == 0)
			return(write(1, "Error_C\n", 8), -1);
	big = radix_indexer(&list_a, array, size);
//	list_show_two(&list_a, &list_b, 1);
	max_bits = ft_max_bits(big);
//	printf("max[%d] bits:%d \n",big, max_bits);
//	list_show_one(&list_a);

	while(i < max_bits)
	{
		j = 0;
		while(j < size && list_a != NULL)
		{
//			printf("list[i:%d] : %d\n", list_a->index, list_a->num);
			if ((((list_a->index >> i) & 1) != 0))
				list_rotate_a(&list_a, option, all_ops);
			else
				list_pb(&list_a, &list_b, option, all_ops);
			j++;
	//		list_show_two(&list_a, &list_b, 1);
		}
		while(list_b != NULL)
			list_pa(&list_a, &list_b, option, all_ops);
		i++;
	}

//			list_show_two(&list_a, &list_b, 1);

	ft_lstclear(&list_a);
	free(array);
	return(1);
}
