/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   chunk_push.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/30 17:48:49 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/30 17:49:15 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push.h"

void	ft_next_push(t_ps *ps, t_i32 big_i, t_i32 biggest)
{
	if (big_i > ps->b.size / 2)
		back_search(ps, biggest);
	else
		front_search(ps, biggest);
	op_pa(ps);
}

void	chuck_end(t_ps *ps)
{
	t_i32	big_i;
	t_i32	biggest;

	while (ps->b.size)
	{
		biggest = ft_list_big(&ps->b, &big_i);
		ft_next_push(ps, big_i, biggest);
	}
}

void	ft_chuck_find(t_ps *ps, t_i32 min_size, t_i32 max_size,
		t_i32 chunk_size)
{
	t_i32	pushed;

	pushed = 0;
	while (pushed < chunk_size && ps->a.size)
	{
		if (ps->a.top->index >= min_size && ps->a.top->index < max_size)
		{
			op_pb(ps);
			pushed++;
		}
		else
			op_ra(ps);
	}
}
