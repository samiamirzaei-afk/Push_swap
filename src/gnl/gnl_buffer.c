/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   gnl_buffer.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      +#+  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/30 18:39:38 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/30 18:52:32 by sfurst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/gnl.h"
#include <stdlib.h>

static t_usize	next_capacity(t_usize current, t_usize required)
{
	t_usize	capacity;
	t_usize	doubled;

	capacity = current;
	if (capacity == 0)
		capacity = LINE_READER_BUFFER_SIZE;
	while (capacity < required)
	{
		doubled = capacity * 2u;
		if (doubled < capacity)
			return (0);
		capacity = doubled;
	}
	return (capacity);
}

bool	ensure_line_capacity(t_line_reader *reader, t_usize required)
{
	t_u8	*new_buffer;
	t_usize	new_capacity;
	t_usize	index;

	if (required <= reader->line_capacity)
		return (true);
	new_capacity = next_capacity(reader->line_capacity, required);
	if (new_capacity == 0)
		return (false);
	new_buffer = (t_u8 *)malloc(new_capacity);
	if (new_buffer == NULL)
		return (false);
	index = 0;
	while (index < reader->line_capacity)
	{
		new_buffer[index] = reader->line_buffer[index];
		index++;
	}
	free(reader->line_buffer);
	reader->line_buffer = new_buffer;
	reader->line_capacity = new_capacity;
	return (true);
}

void	line_reader_init(t_line_reader *reader, t_i32 fd)
{
	reader->fd = fd;
	reader->read_position = 0;
	reader->read_length = 0;
	reader->line_buffer = NULL;
	reader->line_capacity = 0;
	reader->reached_eof = false;
}

void	line_reader_deinit(t_line_reader *reader)
{
	free(reader->line_buffer);
	reader->line_buffer = NULL;
	reader->line_capacity = 0;
	reader->read_position = 0;
	reader->read_length = 0;
	reader->reached_eof = true;
	reader->fd = -1;
}
