/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   gnl_read.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/30 18:39:38 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/30 19:01:40 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/gnl.h"

static t_usize	line_newline(const t_line_reader *reader, t_usize available)
{
	const t_u8	*buffer;
	t_usize		index;

	buffer = reader->read_buffer + reader->read_position;
	index = 0;
	while (index < available && buffer[index] != '\n')
		index++;
	return (index);
}

t_line_result_tag	line_reader_refill(t_line_reader *reader)
{
	t_iptr	amount_read;

	reader->read_position = 0;
	reader->read_length = 0;
	if (reader->reached_eof)
		return (line_result_eof);
	amount_read = (t_iptr)read(reader->fd, reader->read_buffer,
			LINE_READER_BUFFER_SIZE);
	if (amount_read < 0)
		return (line_result_error);
	if (amount_read == 0)
	{
		reader->reached_eof = true;
		return (line_result_eof);
	}
	reader->read_length = (t_usize)amount_read;
	return (line_result_ok);
}

static void	line_copy(t_line_reader *reader, t_usize *length, t_usize chunk)
{
	t_usize	index;

	index = 0;
	while (index < chunk)
	{
		reader->line_buffer[*length
			+ index] = reader->read_buffer[reader->read_position + index];
		index++;
	}
	*length += chunk;
	reader->read_position += chunk;
}

t_line_result_tag	line_reader_append(t_line_reader *reader, t_usize *length,
		bool *ended)
{
	t_usize	available;
	t_usize	chunk;

	available = reader->read_length - reader->read_position;
	chunk = line_newline(reader, available);
	if (*length == (t_usize)-1 || chunk > (t_usize)-1 - *length - 1u)
		return (line_result_out_of_memory);
	if (!ensure_line_capacity(reader, *length + chunk + 1u))
		return (line_result_out_of_memory);
	line_copy(reader, length, chunk);
	*ended = reader->read_position < reader->read_length
		&& reader->read_buffer[reader->read_position] == '\n';
	if (*ended)
	{
		reader->read_position++;
		if (*length > 0 && reader->line_buffer[*length - 1u] == '\r')
			(*length)--;
	}
	return (line_result_ok);
}
