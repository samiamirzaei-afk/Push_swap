/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   radix_index.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/30 17:47:24 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/30 17:47:45 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push.h"

t_i32	ft_max_bits(t_i32 num)
{
	t_i32	bits;

	bits = 0;
	while (num)
	{
		num >>= 1;
		bits++;
	}
	if (!bits)
		bits = 1;
	return (bits);
}

t_i32	ft_next_small(t_stack *stack, t_i32 smallest)
{
	t_node	*node;
	t_i32	next_smallest;
	bool	found;

	node = stack->top;
	next_smallest = 0;
	found = false;
	while (node)
	{
		if (node->value > smallest && (!found || node->value < next_smallest))
		{
			next_smallest = node->value;
			found = true;
		}
		node = node->next;
	}
	return (next_smallest);
}

void	radix_indexer_2(t_stack *stack, t_i32 smallest)
{
	t_node	*node;
	t_i32	rank;

	rank = 1;
	while (rank < stack->size)
	{
		smallest = ft_next_small(stack, smallest);
		node = stack->top;
		while (node && node->value != smallest)
			node = node->next;
		if (node)
			node->index = rank++;
	}
}

void	radix_indexer(t_stack *stack)
{
	t_node	*node;
	t_i32	smallest;

	node = stack->top;
	smallest = node->value;
	while (node)
	{
		if (node->value < smallest)
			smallest = node->value;
		node = node->next;
	}
	node = stack->top;
	while (node && node->value != smallest)
		node = node->next;
	if (node)
		node->index = 0;
	radix_indexer_2(stack, smallest);
}
