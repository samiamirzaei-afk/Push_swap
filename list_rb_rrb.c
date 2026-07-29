#include "push.h"

//anchor should be the start node; first to last;
void	list_rb(t_list **current, short option, t_ops **all_ops)
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
	write(1, "rb\n", 3);
}
//last to first
void	list_rrb(t_list **current, short option, t_ops **all_ops)
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
	write(1, "rrb\n", 4);
}
