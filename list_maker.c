#include "lilist.h"


t_list	*ft_lstnew(int content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if(ptr == NULL)
		return(NULL);
	ptr->num = content;
	ptr->next = NULL;
	return (ptr);
}

void	ft_lstadd_back(t_list **head, t_list *new)
{
	t_list	*ptr;
	{
		*head = new;
		return ;
	}
	ptr = *head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
}

void	ft_lstclear(t_list **head)
{
	t_list	*ptr;
	t_list	*ptr2;

	ptr = *head;
	while (ptr != NULL)
	{
		ptr2 = ptr;
		ptr = ptr->next;
		free(ptr2);
	}
	*head = NULL;
}

int	list_maker(int *array, int size, t_list **head)
{
	int i;
	t_list *ptr;
	t_list *temp;

	ptr = NULL;
	i = 0;
	while(i < size)
	{
		ptr = ft_lstnew(array[i]);
		if(ptr == NULL)
		{
			ft_lstclear(head);
        		return(0) ;
		}
		if(*head == NULL)
		{
			*head = ptr;
			temp = ptr;
		}
		else
		{
			temp->next = ptr;
			temp = temp->next;
		}
		i++;
	}
/*
	ptr = *head;
	for(i = 0; ptr != NULL; i++)
	{
		printf("link[%d]: %d\n", i, ptr->num);
		ptr = ptr->next;
	}
*/
	return(1);
}

