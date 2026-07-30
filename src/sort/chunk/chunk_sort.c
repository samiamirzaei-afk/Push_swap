/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   chunk_sort.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/30 17:49:38 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/30 17:49:41 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push.h"

void	chunk_sort(t_ps *ps)
{
	t_i32	chunk_size;
	t_i32	min_size;
	t_i32	max_size;
	t_i32	size;

	if (ps->a.size <= 5)
	{
		bubble_sort(ps);
		return ;
	}
	size = ps->a.size;
	chunk_size = ft_sqrt_start(size);
	min_size = 0;
	max_size = chunk_size;
	while (ps->a.size)
	{
		ft_chuck_find(ps, min_size, max_size, chunk_size);
		min_size += chunk_size;
		max_size += chunk_size;
		if (max_size > size)
			max_size = size;
	}
	chuck_end(ps);
}
