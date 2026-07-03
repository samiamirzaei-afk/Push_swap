#include "push.h"

void ft_print_ops(t_ops **all_ops)
{
	printf(" *** TOTAL OPS ***\n");
	printf("sa:%d sb:%d ss:%d\n", (*all_ops)->sa, (*all_ops)->sb, (*all_ops)->ss);
	printf("ra:%d rb:%d rr:%d\n", (*all_ops)->ra, (*all_ops)->rb, (*all_ops)->rr);
	printf("rra:%d rrb:%d rrr:%d\n", (*all_ops)->rra, (*all_ops)->rrb, (*all_ops)->rrr);
	printf("pa:%d pb:%d\n ", (*all_ops)->pa, (*all_ops)->pb);
	printf("\n");
}

t_ops **ft_op_to_zero(t_ops **all_ops)
{	
	(*all_ops) = malloc(sizeof(t_ops));
	if((*all_ops) == NULL)
		return(NULL);
	(*all_ops)->sa = 0;
	(*all_ops)->sb = 0;
	(*all_ops)->ss = 0;
	(*all_ops)->pa = 0;
	(*all_ops)->pb = 0;
	(*all_ops)->ra = 0;
	(*all_ops)->rb = 0;
	(*all_ops)->rr = 0;
	(*all_ops)->rra = 0;
	(*all_ops)->rrb = 0;
	(*all_ops)->rrr = 0;
	return(all_ops);
}
