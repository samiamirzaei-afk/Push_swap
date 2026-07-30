/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   checker.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/30 19:05:16 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/31 00:04:45 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../include/gnl.h"
#include "../include/push.h"
#include "../include/strutils.h"

static void	init_ps(t_ps *ps)
{
	*ps = (t_ps){0};
}

static bool	execute_instruction(t_ps *ps, const t_u8 *line)
{
	if (ft_strcmp((const char *)line, "sa") == 0)
		op_sa(ps);
	else if (ft_strcmp((const char *)line, "sb") == 0)
		op_sb(ps);
	else if (ft_strcmp((const char *)line, "ss") == 0)
		op_ss(ps);
	else if (ft_strcmp((const char *)line, "pa") == 0)
		op_pa(ps);
	else if (ft_strcmp((const char *)line, "pb") == 0)
		op_pb(ps);
	else if (ft_strcmp((const char *)line, "ra") == 0)
		op_ra(ps);
	else if (ft_strcmp((const char *)line, "rb") == 0)
		op_rb(ps);
	else if (ft_strcmp((const char *)line, "rr") == 0)
		op_rr(ps);
	else if (ft_strcmp((const char *)line, "rra") == 0)
		op_rra(ps);
	else if (ft_strcmp((const char *)line, "rrb") == 0)
		op_rrb(ps);
	else if (ft_strcmp((const char *)line, "rrr") == 0)
		op_rrr(ps);
	else
		return (false);
	return (true);
}

static bool	read_and_exec(t_ps *ps)
{
	t_line_reader	reader;
	t_line_result	result;

	line_reader_init(&reader, STDIN_FILENO);
	while (true)
	{
		result = line_reader_next(&reader);
		if (result.tag != line_result_ok)
			break ;
		if (!execute_instruction(ps, result.value.line.data))
		{
			line_reader_deinit(&reader);
			return (false);
		}
	}
	line_reader_deinit(&reader);
	return (result.tag == line_result_eof);
}

static bool	validate_result(t_ps *ps)
{
	if (is_sorted(&ps->a) && ps->b.size == 0)
	{
		write(1, "OK\n", 3);
		return (true);
	}
	else
	{
		write(1, "KO\n", 3);
		return (false);
	}
}

int	main(int argc, char **argv)
{
	t_ps	ps;
	bool	valid;

	init_ps(&ps);
	if (!parse_arguments(&ps, argc, argv) || !read_and_exec(&ps))
	{
		stack_clear(&ps.a);
		stack_clear(&ps.b);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	valid = validate_result(&ps);
	stack_clear(&ps.a);
	stack_clear(&ps.b);
	return (!valid);
}
