/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   list.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/16 21:45:44 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/16 21:45:44 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	stack_append(t_stack *stack, t_i32 value)
{
	t_node	*node;
	t_node	*last;

	node = malloc(sizeof(*node));
	if (!node)
		return (0);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	if (!stack->top)
		stack->top = node;
	else
	{
		last = stack->top;
		while (last->next)
			last = last->next;
		last->next = node;
	}
	stack->size++;
	return (1);
}

void	stack_clear(t_stack *stack)
{
	t_node	*next;

	while (stack->top)
	{
		next = stack->top->next;
		free(stack->top);
		stack->top = next;
	}
	stack->size = 0;
}

int	is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node && node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

int	assign_indexes(t_ps *ps)
{
	t_node	*node;
	t_node	*other;
	t_i32	index;

	node = ps->a.top;
	while (node)
	{
		index = 0;
		other = ps->a.top;
		while (other)
		{
			if (other->value < node->value)
				index++;
			other = other->next;
		}
		node->index = index;
		node = node->next;
	}
	return (1);
}

/* Inversion ratio, kept on the linked-list representation. */
t_f32	ft_disorder(t_stack *stack)
{
	t_node	*left;
	t_node	*right;
	t_u64	inversions;
	t_u64	pairs;

	inversions = 0;
	pairs = 0;
	left = stack->top;
	while (left)
	{
		right = left->next;
		while (right)
		{
			pairs++;
			if (left->value > right->value)
				inversions++;
			right = right->next;
		}
		left = left->next;
	}
	if (!pairs)
		return (0);
	return ((t_f32)inversions / (t_f32)pairs);
}
