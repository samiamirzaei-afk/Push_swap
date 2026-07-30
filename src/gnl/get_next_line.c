/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/30 18:39:38 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/30 18:59:33 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/gnl.h"

static t_line_result	line_reader_error(t_line_result_tag tag)
{
	return (line_result_simple(tag));
}

t_line_result	line_reader_next(t_line_reader *reader)
{
	t_usize	length;
	bool	ended;
	t_i32	status;

	length = 0;
	while (true)
	{
		if (reader->read_position == reader->read_length)
		{
			status = line_reader_refill(reader);
			if (status == line_result_error)
				return (line_reader_error(status));
			if (status == line_result_eof)
			{
				if (length == 0)
					return (line_reader_error(status));
				return (line_reader_finish(reader, length));
			}
		}
		status = line_reader_append(reader, &length, &ended);
		if (status != line_result_ok)
			return (line_reader_error(status));
		if (ended)
			return (line_reader_finish(reader, length));
	}
}
