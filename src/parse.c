/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parse.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/16 21:45:45 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/16 22:16:15 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"
#include "../include/strutils.h"
#include <stdbool.h>

static int	is_flag(const char *arg)
{
	return (!ft_strcmp(arg, "--simple") || !ft_strcmp(arg, "--medium")
		|| !ft_strcmp(arg, "--complex") || !ft_strcmp(arg, "--adaptive")
		|| !ft_strcmp(arg, "--bench"));
}

static bool	set_flag(t_ps *ps, const char *arg)
{
	if (!ft_strcmp(arg, "--simple"))
		ps->mode = simple;
	else if (!ft_strcmp(arg, "--medium"))
		ps->mode = medium;
	else if (!ft_strcmp(arg, "--complex"))
		ps->mode = complex;
	else if (!ft_strcmp(arg, "--adaptive"))
		ps->mode = adaptive;
	else if (!ft_strcmp(arg, "--bench"))
		ps->bench = 1;
	else
		return (false);
	return (true);
}

static bool	duplicate(t_stack *stack, t_i32 value)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		if (node->value == value)
			return (true);
		node = node->next;
	}
	return (false);
}

bool	parse_arguments(t_ps *ps, int argc, char **argv)
{
	t_parse_result	parsed;
	int				i;

	ps->mode = adaptive;
	ps->bench = 0;
	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i]))
			set_flag(ps, argv[i]);
		else if (!ft_strncmp(argv[i], "--", 2))
			return (false);
		else
		{
			parsed = parse_i32(argv[i]);
			if (parsed.status == t_i32_err || duplicate(&ps->a, parsed.value)
				|| !stack_append(&ps->a, parsed.value))
				return (false);
		}
		i++;
	}
	return (ps->a.size > 0);
}
