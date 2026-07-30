/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   gnl_result.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      +#+  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/30 18:39:38 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/30 18:52:32 by sfurst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/gnl.h"

t_line_result	line_result_simple(t_line_result_tag tag)
{
	t_line_result	result;

	result.tag = tag;
	result.value.error.unused = 0;
	return (result);
}

t_line_result	line_result_line(const t_u8 *data, t_usize length)
{
	t_line_result	result;

	result.tag = line_result_ok;
	result.value.line.data = data;
	result.value.line.length = length;
	return (result);
}

t_line_result	line_reader_finish(t_line_reader *reader, t_usize length)
{
	reader->line_buffer[length] = '\0';
	return (line_result_line(reader->line_buffer, length));
}
