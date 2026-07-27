/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bench_strategy.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/27 16:30:45 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/27 16:30:46 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push.h"

static const char	*bench_mode_name(t_mode mode, t_i32 adaptive)
{
	if (adaptive)
	{
		if (mode == simple)
			return ("Adaptive / Simple O(n²)");
		if (mode == medium)
			return ("Adaptive / Medium O(n√n)");
		if (mode == complex)
			return ("Adaptive / Complex O(n log n)");
		return ("Adaptive");
	}
	if (mode == simple)
		return ("Simple O(n²)");
	if (mode == medium)
		return ("Medium O(n√n)");
	if (mode == complex)
		return ("Complex O(n log n)");
	return ("Adaptive");
}

void	bench_strategy(t_u8 *buf, t_i32 *index, t_mode mode, t_i32 adaptive)
{
	bench_put_str(buf, index, "[bench] strategy: ");
	bench_put_str(buf, index, bench_mode_name(mode, adaptive));
	(*index)++;
	buf[*index - 1] = '\n';
}
