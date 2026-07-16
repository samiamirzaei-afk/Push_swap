/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operations_reverse.c                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/16 21:45:37 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/16 22:05:03 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push.h"

void	op_rrr(t_ps *ps)
{
	exec_reverse_rotate(&ps->a);
	exec_reverse_rotate(&ps->b);
	emit_operation(ps, "rrr");
}
