/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bench.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/16 22:00:05 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/27 16:31:30 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push.h"
#include "qol.h"

void	print_bench(const t_ps *ps)
{
	t_u8	buf[512];
	t_i32	index;

	if (!ps)
		return ;
	index = 0;
	bench_disorder(buf, &index, ps->disorder);
	bench_strategy(buf, &index, ps->mode, ps->adaptive);
	bench_put_str(buf, &index, "[bench] total_ops: ");
	bench_put_u64(buf, &index, ps->operations);
	buf[index++] = ' ';
	buf[index++] = '\n';
	bench_operation_stats(buf, &index, ps);
	write(STDERR_FILENO, buf, (t_usize)index);
}
