/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   five_sort.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/30 17:50:18 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/31 22:15:00 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push.h"

static void	ft_big_small(t_stack *stack, t_i32 *small_i, t_i32 *big_i)
{
	t_node	*node;
	t_i32	position;
	t_i32	biggest;

	ft_small(stack, small_i);
	node = stack->top;
	biggest = node->value;
	*big_i = 0;
	position = 0;
	while (node)
	{
		if (node->value > biggest)
		{
			biggest = node->value;
			*big_i = position;
		}
		node = node->next;
		position++;
	}
}

static void	ft_three_sort(t_ps *ps)
{
	t_i32	small_i;
	t_i32	big_i;

	ft_big_small(&ps->a, &small_i, &big_i);
	if (big_i == 2 && small_i == 0)
		return ;
	if (big_i == 0 && small_i == 1)
		op_ra(ps);
	else if (big_i == 1 && small_i == 2)
		op_rra(ps);
	else if (big_i == 2 && small_i == 1)
		op_sa(ps);
	else if (big_i == 1 && small_i == 0)
	{
		op_rra(ps);
		op_sa(ps);
	}
	else if (big_i == 0 && small_i == 2)
	{
		op_sa(ps);
		op_rra(ps);
	}
}

void	five_sort(t_ps *ps)
{
	t_i32	small_i;
	t_i32	smallest;

	while (ps->a.size > 3)
	{
		smallest = ft_small(&ps->a, &small_i);
		if (ps->a.top->value == smallest)
			op_pb(ps);
		if (ps->a.size > 3)
		{
			smallest = ft_small(&ps->a, &small_i);
			if (ps->a.top->value != smallest)
				ft_2bubble(ps, smallest, small_i);
		}
	}
	if (ps->a.size == 3)
		ft_three_sort(ps);
	else if (ps->a.size == 2 && ps->a.top->value > ps->a.top->next->value)
		op_sa(ps);
	while (ps->b.size)
		op_pa(ps);
}
