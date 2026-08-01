/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_adaptive.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/27 16:29:07 by sfurst           #+#    #+#              */
/*   Updated: 2026/08/01 18:21:09 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"
#include "../include/sort.h"

void	adaptive_sort(t_ps *ps)
{
	if (ps->disorder < 0.2)
	{
		ps->mode = simple;
		return (bubble_sort(ps));
	}
	else if (ps->disorder < 0.5)
	{
		ps->mode = medium;
		return (chunk_sort(ps));
	}
	else
	{
		ps->mode = complex;
		return (radix_sort(ps));
	}
}
