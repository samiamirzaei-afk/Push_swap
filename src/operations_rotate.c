/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operations_rotate.c                               :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      +#+  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/16 21:45:37 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/16 21:45:44 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void op_ra(t_ps *ps)
{
	exec_rotate(&ps->a);
	emit_operation(ps, "ra");
}

void op_rb(t_ps *ps)
{
	exec_rotate(&ps->b);
	emit_operation(ps, "rb");
}

void op_rr(t_ps *ps)
{
	exec_rotate(&ps->a);
	exec_rotate(&ps->b);
	emit_operation(ps, "rr");
}

void op_rra(t_ps *ps)
{
	exec_reverse_rotate(&ps->a);
	emit_operation(ps, "rra");
}

void op_rrb(t_ps *ps)
{
	exec_reverse_rotate(&ps->b);
	emit_operation(ps, "rrb");
}
