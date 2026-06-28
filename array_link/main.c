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

	head = NULL;	
	i = 1;
	size = argc - 1;
	head = ptr;
	while(argv[i] != NULL)
	{
		ptr = ft_lstnew(ft_atoi(argv[i]));
		if(ptr == NULL)
		{
//        		ft_free_all(head);
        		return(0) ;
		}
//		printf("current ptr->num: %d\n", ptr->num);
//		printf("current head: %d\n", head->num);
		ptr = ptr->next;
		i++;
	}
	ptr = head;
	printf("current ptr->num: %d\n", ptr->num);

	for(i = 0; ptr->next != NULL; i++)
	{
		printf("link[%d]: %d\n", i, ptr->num);
		ptr = ptr->next;
	}
}

