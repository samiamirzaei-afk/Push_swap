/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push.h                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/16 21:45:46 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/16 22:15:26 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "qol.h"
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

# ifndef PUSH_PRINT_OPERATIONS
#  define PUSH_PRINT_OPERATIONS 1
# endif

typedef struct s_node
{
	t_i32			value;
	t_i32			index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_i32			size;
}					t_stack;

typedef enum e_mode
{
	simple = 1,
	medium,
	complex,
	adaptive
}					t_mode;

typedef struct s_ps
{
	t_stack			a;
	t_stack			b;
	t_mode			mode;
	t_i32			bench;
	t_f32			disorder;
	t_u64			operations;
}					t_ps;

typedef enum e_t_i32_status
{
	t_i32_ok,
	t_i32_err
}					t_t_i32_status;

typedef struct s_t_i32_result
{
	t_t_i32_status	status;
	t_u64			value;
}					t_t_i32_result;

typedef struct s_parse_result
{
	t_t_i32_status	status;
	t_i32			value;
}					t_parse_result;

t_t_i32_result		ft_parse_uint(const char *str, int is_u32);
bool				parse_arguments(t_ps *ps, int argc, char **argv);
t_parse_result		parse_i32(const char *str);

void				assign_indexes(t_ps *ps);
t_f32				ft_disorder(t_stack *stack);
bool				is_sorted(t_stack *stack);
bool				stack_append(t_stack *stack, t_i32 value);
void				stack_clear(t_stack *stack);

void				emit_operation(t_ps *ps, const char *name);
void				exec_reverse_rotate(t_stack *stack);
void				exec_rotate(t_stack *stack);
void				exec_swap(t_stack *stack);
void				op_pa(t_ps *ps);
void				op_pb(t_ps *ps);
void				op_ra(t_ps *ps);
void				op_rb(t_ps *ps);
void				op_rr(t_ps *ps);
void				op_rra(t_ps *ps);
void				op_rrb(t_ps *ps);
void				op_rrr(t_ps *ps);
void				op_sa(t_ps *ps);
void				op_sb(t_ps *ps);
void				op_ss(t_ps *ps);

void				adaptive_sort(t_ps *ps);
void				chunk_sort(t_ps *ps);
void				print_bench(const t_ps *ps);
void				radix_sort(t_ps *ps);
void				selection_sort(t_ps *ps);

void				print_bench(const t_ps *ps);

#endif
