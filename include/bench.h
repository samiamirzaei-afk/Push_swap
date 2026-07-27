/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bench.h                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/27 16:26:50 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/27 16:26:54 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCH_H
# define BENCH_H

# include "qol.h"

typedef struct s_ps	t_ps;
typedef enum e_mode	t_mode;

void				bench_disorder(t_u8 *buf, t_i32 *index, t_f32 disorder);
void				print_bench(const t_ps *ps);
void				bench_strategy(t_u8 *buf, t_i32 *index, t_mode mode,
						t_i32 adaptive);
void				bench_operation_stats(t_u8 *buf, t_i32 *index,
						const t_ps *ps);
void				bench_put_str(t_u8 *buf, t_i32 *index, const char *str);
void				bench_put_u64(t_u8 *buf, t_i32 *index, t_u64 number);

#endif
