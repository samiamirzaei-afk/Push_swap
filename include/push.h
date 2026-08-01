/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push.h                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/27 16:27:26 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/31 22:13:48 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "bench.h"
# include "qol.h"
# include "sort.h"
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

# ifndef PUSH_PRINT_OPERATIONS
#  define PUSH_PRINT_OPERATIONS 1
# endif
# define OP_TYPE_COUNT 11

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

typedef enum e_op_type
{
	op_type_sa,
	op_type_sb,
	op_type_ss,
	op_type_pa,
	op_type_pb,
	op_type_ra,
	op_type_rb,
	op_type_rr,
	op_type_rra,
	op_type_rrb,
	op_type_rrr,
	op_type_count
}					t_op_type;

typedef struct s_ps
{
	t_stack			a;
	t_stack			b;
	t_mode			mode;
	t_i32			bench;
	t_i32			adaptive;
	t_f32			disorder;
	t_u64			operations;
	t_u64			op_stats[OP_TYPE_COUNT];
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

void				back_search(t_ps *ps, t_i32 biggest);
void				chuck_end(t_ps *ps);
void				five_sort(t_ps *ps);
void				front_search(t_ps *ps, t_i32 biggest);
void				ft_2bubble(t_ps *ps, t_i32 smallest, t_i32 small_i);
t_i32				ft_list_big(t_stack *stack, t_i32 *big_i);
void				ft_next_push(t_ps *ps, t_i32 big_i, t_i32 biggest);
t_i32				ft_small(t_stack *stack, t_i32 *small_i);
t_i32				ft_sqrt_start(t_i32 number);
void				ft_chuck_find(t_ps *ps, t_i32 min_size, t_i32 max_size,
						t_i32 chunk_size);
void				emit_operation(t_ps *ps, const char *name, t_op_type type);
void				exec_reverse_rotate(t_stack *stack);
void				exec_rotate(t_stack *stack);
void				exec_swap(t_stack *stack);
t_i32				ft_max_bits(t_i32 num);
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
void				radix_indexer(t_stack *stack);
void				radix_indexer_2(t_stack *stack, t_i32 smallest);
void				radix_main(t_ps *ps);
void				radix_main_2(t_ps *ps, t_i32 max_bits);

#endif
