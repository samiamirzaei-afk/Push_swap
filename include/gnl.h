/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   gnl.h                                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/30 18:36:31 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/30 18:59:00 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "qol.h"
# include <stdbool.h>
# include <unistd.h>

# define LINE_READER_BUFFER_SIZE 4096u

typedef enum e_line_result_tag
{
	line_result_ok,
	line_result_eof,
	line_result_error,
	line_result_out_of_memory
}						t_line_result_tag;

typedef struct s_line_view
{
	const t_u8			*data;
	t_usize				length;
}						t_line_view;

typedef struct s_line_error
{
	t_i32				unused;
}						t_line_error;

typedef union u_line
{
	t_line_view			line;
	t_line_error		error;
}						t_line;

typedef struct s_line_result
{
	t_line_result_tag	tag;
	t_line				value;
}						t_line_result;

typedef struct s_line_reader
{
	t_i32				fd;
	t_u8				read_buffer[LINE_READER_BUFFER_SIZE];
	t_usize				read_position;
	t_usize				read_length;
	t_u8				*line_buffer;
	t_usize				line_capacity;
	bool				reached_eof;
}						t_line_reader;

void					line_reader_deinit(t_line_reader *reader);
void					line_reader_init(t_line_reader *reader, t_i32 fd);
t_line_result			line_reader_next(t_line_reader *reader);
t_line_result			line_result_line(const t_u8 *data, t_usize length);
t_line_result			line_result_simple(t_line_result_tag tag);
t_line_result			line_reader_finish(t_line_reader *reader,
							t_usize length);
t_line_result_tag		line_reader_refill(t_line_reader *reader);
t_line_result_tag		line_reader_append(t_line_reader *reader,
							t_usize *length, bool *ended);
bool					ensure_line_capacity(t_line_reader *reader,
							t_usize required);

#endif
