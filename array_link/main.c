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

	if (!head || !new)
		return ;
	if (*head == NULL)
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

int    main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("please provide an argument");
		return (1);
	}
	int size;
	int i;
	t_list *head;
	t_list *ptr;

	ptr = NULL;
	i = 1;
	size = argc - 1;
	while(argv[i] != NULL)
	{
		ptr = ft_lstnew(ft_atoi(argv[i]));
		if(ptr == NULL)
		{
			ft_lstclear(&head);
        		return(0) ;
		}
		if(head == NULL)
			head = ptr;
		else
			ft_lstadd_back(&head, ptr);
		i++;
	}
	ptr = head;
	for(i = 0; ptr != NULL; i++)
	{
		printf("link[%d]: %d\n", i, ptr->num);
		ptr = ptr->next;
	}
	ft_lstclear(&head);
}

