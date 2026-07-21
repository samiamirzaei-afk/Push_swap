#include "push.h"

int	radix_main(int *array, int size, short option, t_ops **all_ops)
{
	t_list *head;
	t_list *ptr;
	t_list *start;
	t_list *list_b;

	int i;

	i = 0;
	head = NULL;
	list_b = NULL;
	if(list_maker(array, size, &head) == 0)
			return(write(1, "Error_C\n", 8), -1);
	start = head;

///*
	ptr = head;
	for(i = 0; ptr != NULL; i++)
	{
		printf("list[%d]: %d\n", i , ptr->num);
		ptr = ptr->next;
	}
//*/
//	list_rotate(&head);
	list_pb(&head, &list_b);
	list_pb(&head, &list_b);
	printf("\n");
///*
	ptr = head;
	for(i = 0; ptr != NULL; i++)
	{
		printf("list[%d]: %d\n", i , ptr->num);
		ptr = ptr->next;
	}
	printf("\n now list_b:\n");
	ptr = list_b;
	for(i = 0; ptr != NULL; i++)
	{
		printf("list[%d]: %d\n", i , ptr->num);
		ptr = ptr->next;
	}
//*/

	ft_lstclear(&head);
	free(array);
	return(1);
}
