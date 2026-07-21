#include "push.h"

void	list_swap(t_list **current, t_list **target)
{
	int temp;

	temp = (*current)->num;
	(*current)->num = (*target)->num;
	(*target)->num = temp;
}
//anchor should be the start node;
void	list_rotate(t_list **current)
{
	t_list *start_node;
	t_list *anchor;
	
	anchor = (*current);
	
	while((*current)->next != NULL)
		(*current) = (*current)->next;
	//printf("value:%d\n", (*current)->num);
	start_node = anchor->next;
	anchor->next = NULL;
	(*current)->next = anchor;
	(*current) = start_node;
}
//
void	list_re_rotate(t_list **current)
{
	t_list *start_node;
	t_list *anchor;
	
	anchor = (*current);
	while((*current)->next->next != NULL)
		(*current) = (*current)->next;
	//printf("value:%d\n", (*current)->num);
	start_node = (*current)->next;
	(*current)->next = NULL;
	start_node->next = anchor;
	(*current) = start_node;	
}

void	list_pa(t_list **list_a, t_list **list_b)
{
	t_list *anchor;

	if(*list_b)
		return ;	
	anchor = (*list_b);
	*list_b = (*list_b)->next;
	if(*list_a)
	{
		(*list_a) = anchor;
		(*list_a)->next = NULL;
		return ;
	}
	anchor->next = (*list_a);
	(*list_a) = anchor;
}

void	list_pb(t_list **list_a, t_list **list_b)
{
	t_list *anchor;
	
	
	if(*list_a == NULL)
		return ;
	anchor = (*list_a);
	(*list_a) = (*list_a)->next;
	if(*list_b == NULL)
	{
		(*list_b) = anchor;
		(*list_b)->next = NULL;
		return ;
	}
	anchor->next = (*list_b);
	(*list_b) = anchor;
	
}
