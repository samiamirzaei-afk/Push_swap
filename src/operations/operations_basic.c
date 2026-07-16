/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operations_basic.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/16 21:45:37 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/16 22:04:49 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push.h"

void	op_sa(t_ps *ps)
{
	exec_swap(&ps->a);
	emit_operation(ps, "sa");
}

void	op_sb(t_ps *ps)
{
	exec_swap(&ps->b);
	emit_operation(ps, "sb");
}

void	op_ss(t_ps *ps)
{
	exec_swap(&ps->a);
	exec_swap(&ps->b);
	emit_operation(ps, "ss");
}

void	op_pa(t_ps *ps)
{
	t_node	*node;

	if (ps->b.size)
	{
		node = ps->b.top;
		ps->b.top = node->next;
		node->next = ps->a.top;
		ps->a.top = node;
		ps->b.size--;
		ps->a.size++;
	}
	emit_operation(ps, "pa");
}

void	op_pb(t_ps *ps)
{
	t_node	*node;

	if (ps->a.size)
	{
		node = ps->a.top;
		ps->a.top = node->next;
		node->next = ps->b.top;
		ps->b.top = node;
		ps->a.size--;
		ps->b.size++;
	}
	emit_operation(ps, "pb");
}
