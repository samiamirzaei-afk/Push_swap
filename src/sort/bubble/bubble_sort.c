/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bubble_sort.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/30 17:56:53 by sfurst           #+#    #+#              */
/*   Updated: 2026/08/01 18:42:33 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push.h"

t_i32	ft_small(t_stack *stack, t_i32 *small_i)
{
	t_node	*node;
	t_i32	smallest;
	t_i32	position;

	node = stack->top;
	smallest = node->value;
	*small_i = 0;
	position = 0;
	while (node)
	{
		if (node->value < smallest)
		{
			smallest = node->value;
			*small_i = position;
		}
		node = node->next;
		position++;
	}
	return (smallest);
}

void	ft_2bubble(t_ps *ps, t_i32 smallest, t_i32 small_i)
{
	if (ps->a.top->value != smallest)
	{
		if (small_i <= ps->a.size / 2)
			op_ra(ps);
		else
			op_rra(ps);
	}
}

void	bubble_sort(t_ps *ps)
{
	t_i32	small_i;
	t_i32	smallest;

	if (ps->a.size <= 5)
	{
		five_sort(ps);
		return ;
	}
	while (1)
	{
		smallest = ft_small(&ps->a, &small_i);
		if (ps->a.size >= 2 && ps->a.top->value > ps->a.top->next->value)
			op_sa(ps);
		if (ps->a.top->value == smallest)
			op_pb(ps);
		if (ps->a.size == 0)
			break ;
		smallest = ft_small(&ps->a, &small_i);
		ft_2bubble(ps, smallest, small_i);
		if (is_sorted(&ps->a))
			break ;
	}
	while (ps->b.size)
		op_pa(ps);
}
