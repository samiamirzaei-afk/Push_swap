/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   chunk_utils.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/30 17:48:43 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/30 17:49:05 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push.h"

t_i32	ft_sqrt(t_i32 number)
{
	t_i32	root;

	root = 1;
	while ((root + 1) * (root + 1) <= number)
		root++;
	return (root);
}

t_i32	ft_sqrt_start(t_i32 number)
{
	if (number <= 100)
		return (ft_sqrt(number));
	if (number <= 400)
		return (ft_sqrt(number));
	return (ft_sqrt(number));
}

t_i32	ft_list_big(t_stack *stack, t_i32 *big_i)
{
	t_node	*node;
	t_i32	biggest;
	t_i32	position;

	node = stack->top;
	biggest = node->index;
	*big_i = 0;
	position = 0;
	while (node)
	{
		if (node->index > biggest)
		{
			biggest = node->index;
			*big_i = position;
		}
		node = node->next;
		position++;
	}
	return (biggest);
}

void	back_search(t_ps *ps, t_i32 biggest)
{
	while (ps->b.top->index != biggest)
		op_rrb(ps);
}

void	front_search(t_ps *ps, t_i32 biggest)
{
	while (ps->b.top->index != biggest)
		op_rb(ps);
}
