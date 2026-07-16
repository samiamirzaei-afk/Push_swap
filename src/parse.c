/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parse.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/16 21:45:45 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/16 21:45:45 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include <string.h>

static int	is_flag(const char *arg)
{
	return (!strcmp(arg, "--simple") || !strcmp(arg, "--medium") || !strcmp(arg,
			"--complex") || !strcmp(arg, "--adaptive") || !strcmp(arg,
			"--bench"));
}

static int	set_flag(t_ps *ps, const char *arg)
{
	if (!strcmp(arg, "--simple"))
		ps->mode = SIMPLE;
	else if (!strcmp(arg, "--medium"))
		ps->mode = MEDIUM;
	else if (!strcmp(arg, "--complex"))
		ps->mode = COMPLEX;
	else if (!strcmp(arg, "--adaptive"))
		ps->mode = ADAPTIVE;
	else if (!strcmp(arg, "--bench"))
		ps->bench = 1;
	else
		return (0);
	return (1);
}

static int	duplicate(t_stack *stack, t_i32 value)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		if (node->value == value)
			return (1);
		node = node->next;
	}
	return (0);
}

int	parse_arguments(t_ps *ps, int argc, char **argv)
{
	t_parse_result	parsed;
	int				i;

	ps->mode = ADAPTIVE;
	ps->bench = 0;
	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i]))
			set_flag(ps, argv[i]);
		else if (!strncmp(argv[i], "--", 2))
			return (0);
		else
		{
			parsed = parse_i32(argv[i]);
			if (parsed.status == t_i32_err || duplicate(&ps->a, parsed.value)
				|| !stack_append(&ps->a, parsed.value))
				return (0);
		}
		i++;
	}
	return (ps->a.size > 0);
}
