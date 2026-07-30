/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   radix.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/30 17:48:01 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/30 17:48:02 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push.h"

void	radix_main_2(t_ps *ps, t_i32 max_bits)
{
	t_i32	bit;
	t_i32	processed;
	t_i32	size;

	bit = 0;
	size = ps->a.size;
	while (bit < max_bits)
	{
		processed = 0;
		while (processed < size && ps->a.top)
		{
			if ((ps->a.top->index >> bit) & 1)
				op_ra(ps);
			else
				op_pb(ps);
			processed++;
		}
		while (ps->b.size)
			op_pa(ps);
		bit++;
	}
}

void	radix_main(t_ps *ps)
{
	if (ps->a.size <= 5)
	{
		bubble_sort(ps);
		return ;
	}
	radix_indexer(&ps->a);
	radix_main_2(ps, ft_max_bits(ps->a.size));
}

void	radix_sort(t_ps *ps)
{
	if (ps->a.size > 1)
		radix_main(ps);
}
