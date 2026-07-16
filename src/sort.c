/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/16 21:45:45 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/16 21:45:45 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static t_i32	min_position(t_stack *stack)
{
	t_node	*node;
	t_i32	best;
	t_i32	pos;
	t_i32	best_pos;

	node = stack->top;
	best = node->value;
	pos = 0;
	best_pos = 0;
	while (node)
	{
		if (node->value < best)
		{
			best = node->value;
			best_pos = pos;
		}
		node = node->next;
		pos++;
	}
	return (best_pos);
}

void	selection_sort(t_ps *ps)
{
	t_i32	pos;

	while (ps->a.size)
	{
		pos = min_position(&ps->a);
		if (pos <= ps->a.size / 2)
			while (pos-- > 0)
				op_ra(ps);
		else
		{
			pos = ps->a.size - pos;
			while (pos-- > 0)
				op_rra(ps);
		}
		op_pb(ps);
	}
	while (ps->b.size)
		op_pa(ps);
}

static t_i32	max_position(t_stack *stack)
{
	t_node	*node;
	t_i32	max;
	t_i32	pos;
	t_i32	best_pos;

	node = stack->top;
	max = node->index;
	pos = 0;
	best_pos = 0;
	while (node)
	{
		if (node->index > max)
		{
			max = node->index;
			best_pos = pos;
		}
		node = node->next;
		pos++;
	}
	return (best_pos);
}

void	chunk_sort(t_ps *ps)
{
	t_i32	chunk;
	t_i32	pushed;
	t_i32	pos;

	chunk = ps->a.size;
	while (chunk * chunk > ps->a.size)
		chunk--;
	chunk = chunk * 3 / 2 + 1;
	pushed = 0;
	while (ps->a.size)
	{
		if (ps->a.top->index <= pushed + chunk)
		{
			op_pb(ps);
			if (ps->b.top->index > pushed)
				op_rb(ps);
			pushed++;
		}
		else
			op_ra(ps);
	}
	while (ps->b.size)
	{
		pos = max_position(&ps->b);
		if (pos <= ps->b.size / 2)
			while (pos-- > 0)
				op_rb(ps);
		else
		{
			pos = ps->b.size - pos;
			while (pos-- > 0)
				op_rrb(ps);
		}
		op_pa(ps);
	}
}

void	radix_sort(t_ps *ps)
{
	t_i32	bit;
	t_i32	rounds;
	t_i32	i;
	t_i32	size;

	size = ps->a.size;
	rounds = 0;
	while ((size - 1) >> rounds)
		rounds++;
	bit = 0;
	while (bit < rounds)
	{
		i = 0;
		while (i++ < size)
		{
			if (((ps->a.top->index >> bit) & 1) == 0)
				op_pb(ps);
			else
				op_ra(ps);
		}
		while (ps->b.size)
			op_pa(ps);
		bit++;
	}
}

void	adaptive_sort(t_ps *ps)
{
	if (ps->disorder < 0.2)
		selection_sort(ps);
	else if (ps->disorder < 0.5)
		chunk_sort(ps);
	else
		radix_sort(ps);
}
