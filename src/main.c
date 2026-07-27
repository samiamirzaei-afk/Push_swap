/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/16 21:45:37 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/27 16:26:55 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"
#include <stdbool.h>

static void	init_ps(t_ps *ps)
{
	*ps = (t_ps){0};
}

static void	sort_stack(t_ps *ps)
{
	if (ps->mode == simple)
		bubble_sort(ps);
	else if (ps->mode == medium)
		chunk_sort(ps);
	else if (ps->mode == complex)
		radix_sort(ps);
	else
		adaptive_sort(ps);
}

static bool	run_push_swap(t_ps *ps, int argc, char **argv)
{
	if (argc < 2 || !parse_arguments(ps, argc, argv))
		return (0);
	assign_indexes(ps);
	ps->disorder = ft_disorder(&ps->a);
	if (!is_sorted(&ps->a))
		sort_stack(ps);
	if (ps->bench)
		print_bench(ps);
	return (1);
}

int	main(int argc, char **argv)
{
	t_ps	ps;
	int		success;

	init_ps(&ps);
	success = run_push_swap(&ps, argc, argv);
	if (!success)
		write(STDERR_FILENO, "Error\n", 6);
	stack_clear(&ps.a);
	stack_clear(&ps.b);
	return (!success);
}
