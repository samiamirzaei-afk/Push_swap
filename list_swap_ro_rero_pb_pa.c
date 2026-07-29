#include "push.h"

void	list_swap(t_list **current, t_list **target)
{
	int temp;

	temp = (*current)->num;
	(*current)->num = (*target)->num;
	(*target)->num = temp;
}
//anchor should be the start node; first to last;
void	list_rotate_a(t_list **current, short option, t_ops **all_ops)
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
	if(option == BENCH)
		(*all_ops)->ra++;
	write(1, "ra\n", 3);
}
//last to first
void	list_re_rotate(t_list **current, short option, t_ops **all_ops)
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
	if(option == BENCH)
		(*all_ops)->rra++;
	write(1, "rra\n", 4);
}

void	list_pa(t_list **list_a, t_list **list_b, short option, t_ops **all_ops)
{
	t_list *anchor;

	if(*list_b == NULL)
		return ;	
	anchor = (*list_b);
	*list_b = (*list_b)->next;
	if(option == BENCH)
		(*all_ops)->pa++;
	if(*list_a == NULL)
	{
		(*list_a) = anchor;
		(*list_a)->next = NULL;
		write(1, "pa\n", 3);
		return ;
	}
	anchor->next = (*list_a);
	(*list_a) = anchor;
	write(1, "pa\n", 3);
}

void list_pb(t_list **list_a, t_list **list_b, short option, t_ops **all_ops)
{
	t_list *anchor;
	
	if(*list_a == NULL)
		return ;
	anchor = (*list_a);
	(*list_a) = (*list_a)->next;
	if(option == BENCH)
		(*all_ops)->pb++;
	if(*list_b == NULL)
	{
		(*list_b) = anchor;
		(*list_b)->next = NULL;
		write(1, "pb\n", 3);
		return ;
	}
	anchor->next = (*list_b);
	(*list_b) = anchor;
	write(1, "pb\n", 3);
}
