#include "push.h" 



int ft_next_small(int *array, int size, int smallest);
int radix_indexer_2(t_list **head, int *array, int size, t_rain *va);
int radix_indexer(t_list **head, int *array, int size);
/*
{
        int     *array;
        int     size;
        short   option;
}       t_aso;

{
        t_list  *list_a;
        t_list  *list_b;
	int chuck;
	int min_size;
	int max_size;
}       t_med;
*/
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
void	ft_pause(void)
{
	char buffer_get[5];
	static int start = 0;

	buffer_get[4] = '\0';
	if(start == 2)
		return;
	if(start == 0)
		write(1, "press y to continue, x to kill, or s to skip\n", 45), start++;
	else
		write(1, "y? x? s?\n", 9);
	fgets(buffer_get, 3, stdin);
	while(1)
	{
		if(buffer_get[0] == 'y' || buffer_get[0] == 'Y')
		{
			return ;
		}
		if(buffer_get[0] == 'x' || buffer_get[0] == 'X')
			exit(0);
		if(buffer_get[0] == 's' || buffer_get[0] == 'S')
		{	
			start = 2;
		       	return ;
		}
	}
}


int ft_list_big(t_list *head, int *big_i)
{
	int big;
	int i;

	i = 0;
	big = 0;
	while (head != NULL)
	{
		if (head->num > big)
		{
			big = head->num;
			*big_i = i;
		}
		head = head->next;
		i++;
	}
	return(big);
}

void back_search(t_med *va, short option, t_ops **all_ops, int big)
{
	short done;

	done = -1;
	while(done != 1)
	{
		list_rrb(&va->list_b, option, all_ops);
		if (va->list_b->num == big)
		{	
			list_pa(&va->list_a, &va->list_b, option, all_ops);
			 done = 1;
		}
	}
}

void front_search(t_med *va, short option, t_ops **all_ops, int big)
{
	while(1)
	{
		if (va->list_b->num == big)
		{
			 list_pa(&va->list_a, &va->list_b, option, all_ops);
			 return ;
		}
		list_rb(&va->list_b, option, all_ops);
	}	
}

int ft_next_push(t_med *va, short option, t_ops **all_ops, int *big_i, int big)
{
	while(1)
	{	
		if(*big_i > va->max_size / 2)
			return(back_search(va, option, all_ops, big), 1);
		else
			return(front_search(va, option, all_ops, big), 1);
	}	
}

int chuck_end(t_med *va, short option, t_ops **all_ops)
{	
	int big_i;
	int big;

	big_i = 0;
	while(va->list_b != NULL)
	{
		big = ft_list_big(va->list_b, &big_i);
		ft_next_push(va, option, all_ops, &big_i, big);
		(va->max_size)--;
	}
	return(1);
}


int	ft_chuck_find(t_med *va, short option, t_ops **all_ops)
{
	int temp;

	temp = 0;	
	while(temp < va->chunk_size  && va->list_a != NULL)
	{
//		printf("min_size: %d, max_size: %d, current cycle:%d\n", va->min_size, va->max_size, temp);
//	list_show_two(&va->list_a, &va->list_b, 1);
		//	ft_pause();
		while(va->list_a != NULL && va->list_a->index >= va->min_size && va->list_a->index < va->max_size)
		{
//			printf("pushing %d, i:%d\n", va->list_a->num, va->list_a->index);
		//	sleep(1);
			list_pb(&va->list_a, &va->list_b, option, all_ops);
//			list_show_two(&va->list_a, &va->list_b, 1);
			temp++;
		}
			if(va->list_a == NULL)
				return(1) ;
		list_rotate_a(&va->list_a, option, all_ops);
	//	sleep(1);

	}
	return(0);
/*
	the indexing is wrong:
./q.bug 1 3 2 9 8 6 4 0  ++medium
temp: 0, max_size: 2
list_A[0][i:0] : 1
list_A[1][i:2] : 3
list_A[2][i:1] : 2
list_A[3][i:6] : 9
list_A[4][i:5] : 8
list_A[5][i:4] : 6
list_A[6][i:3] : 4
list_A[7][i:0] : 0
*/

	 
}
int	chunk_sort(int *array, int size, short option, t_ops **all_ops)
{
	t_med va;
	int temp;

	temp = size;
	if(size <= 5)
		return(bubble_main(array, size, option, all_ops), 1);
	va.list_a = NULL;
	va.list_b = NULL;
	if(list_maker(array, size, &va.list_a) == 0)
			return(free(array), write(1, "Error\n", 6), -1);
	radix_indexer(&va.list_a, array, size);

	va.chunk_size = ft_sqrt_start(size);
	va.max_size = va.chunk_size;
	va.min_size = 0;
	while(va.list_a != NULL)
	{
		ft_chuck_find(&va, option, all_ops);
		va.min_size += va.chunk_size;
		va.max_size += va.chunk_size;
//		printf("max=%d full size:%d\n", va.max_size, size);
		if(va.max_size > temp)
			va.max_size = temp;
	}
	va.max_size = size;
	chuck_end(&va, option, all_ops);
	list_show_two(&va.list_a, &va.list_b, 1);
	ft_lstclear(&va.list_a);
       	free(array);
	return(1);	

}
