/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      +#+  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/16 21:45:37 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/16 21:45:44 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include <stdio.h>

void print_bench(const t_ps *ps)
{
	(void)ps;
	fprintf(stderr, "TODO: benchmark output\n");
}

static void init_ps(t_ps *ps)
{
	ps->a.top = NULL;
	ps->a.size = 0;
	ps->b.top = NULL;
	ps->b.size = 0;
	ps->operations = 0;
}

static void sort_stack(t_ps *ps)
{
	if (ps->mode == SIMPLE)
		selection_sort(ps);
	else if (ps->mode == MEDIUM)
		chunk_sort(ps);
	else if (ps->mode == COMPLEX)
		radix_sort(ps);
	else
		adaptive_sort(ps);
}

static int run_push_swap(t_ps *ps, int argc, char **argv)
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

int main(int argc, char **argv)
{
	t_ps ps;
	int  success;

	init_ps(&ps);
	success = run_push_swap(&ps, argc, argv);
	if (!success)
		write(STDERR_FILENO, "Error\n", 6);
	stack_clear(&ps.a);
	stack_clear(&ps.b);
	return (!success);
}
