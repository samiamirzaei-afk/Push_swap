/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bubble_sort.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/30 17:56:53 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/30 17:56:55 by sfurst          ###   ########.fr        */
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

void	ft_2bubble(t_ps *ps, t_i32 position)
{
	if (position <= ps->a.size / 2)
	{
		while (position-- > 0)
			op_ra(ps);
	}
	else
	{
		position = ps->a.size - position;
		while (position-- > 0)
			op_rra(ps);
	}
}

void	ft_bubble(t_ps *ps)
{
	t_i32	small_i;
	t_i32	smallest;

	while (ps->a.size)
	{
		smallest = ft_small(&ps->a, &small_i);
		if (ps->a.size >= 2 && ps->a.top->value > ps->a.top->next->value)
			op_sa(ps);
		if (ps->a.top->value == smallest)
			op_pb(ps);
		if (!ps->a.size)
			break ;
		smallest = ft_small(&ps->a, &small_i);
		if (ps->a.top->value != smallest)
			ft_2bubble(ps, small_i);
		if (is_sorted(&ps->a))
			break ;
	}
}

void	bubble_main(t_ps *ps)
{
	if (ps->a.size <= 5)
		five_sort(ps);
	else
	{
		ft_bubble(ps);
		while (ps->b.size)
			op_pa(ps);
	}
}

void	bubble_sort(t_ps *ps)
{
	if (ps->a.size > 1)
		bubble_main(ps);
}
