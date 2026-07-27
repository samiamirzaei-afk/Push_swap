/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bench_stats.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/27 16:30:39 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/27 16:30:40 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push.h"

static void	bench_put_operation(t_u8 *buf, t_i32 *index, const char *name,
		t_u64 count)
{
	bench_put_str(buf, index, name);
	bench_put_u64(buf, index, count);
	bench_put_str(buf, index, "  ");
}

void	bench_operation_stats(t_u8 *buf, t_i32 *index, const t_ps *ps)
{
	bench_put_str(buf, index, "[bench] ");
	bench_put_operation(buf, index, "sa: ", ps->op_stats[op_type_sa]);
	bench_put_operation(buf, index, "sb: ", ps->op_stats[op_type_sb]);
	bench_put_operation(buf, index, "ss: ", ps->op_stats[op_type_ss]);
	bench_put_operation(buf, index, "pa: ", ps->op_stats[op_type_pa]);
	bench_put_operation(buf, index, "pb: ", ps->op_stats[op_type_pb]);
	buf[(*index)++] = '\n';
	bench_put_str(buf, index, "[bench] ");
	bench_put_operation(buf, index, "ra: ", ps->op_stats[op_type_ra]);
	bench_put_operation(buf, index, "rb: ", ps->op_stats[op_type_rb]);
	bench_put_operation(buf, index, "rr: ", ps->op_stats[op_type_rr]);
	bench_put_operation(buf, index, "rra: ", ps->op_stats[op_type_rra]);
	bench_put_operation(buf, index, "rrb: ", ps->op_stats[op_type_rrb]);
	bench_put_operation(buf, index, "rrr: ", ps->op_stats[op_type_rrr]);
	buf[(*index)++] = '\n';
}
