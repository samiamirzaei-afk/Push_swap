/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bench_format.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/27 16:30:31 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/27 16:30:32 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push.h"

void	bench_put_str(t_u8 *buf, t_i32 *index, const char *str)
{
	while (*str)
	{
		buf[*index] = (t_u8)str[0];
		str++;
		(*index)++;
	}
}

static void	bench_put_char(t_u8 *buf, t_i32 *index, t_u8 character)
{
	buf[*index] = character;
	(*index)++;
}

void	bench_put_u64(t_u8 *buf, t_i32 *index, t_u64 number)
{
	t_u8	digits[20];
	t_i32	count;

	count = 0;
	if (number == 0)
		bench_put_char(buf, index, '0');
	while (number > 0)
	{
		digits[count++] = (t_u8)(number % 10 + '0');
		number /= 10;
	}
	while (count > 0)
		bench_put_char(buf, index, digits[--count]);
}

void	bench_disorder(t_u8 *buf, t_i32 *index, t_f32 disorder)
{
	t_i32	whole;
	t_i32	fraction;

	disorder *= 100.0f;
	whole = (t_i32)disorder;
	fraction = (t_i32)((disorder - whole) * 100.0f + 0.5f);
	if (fraction >= 100)
	{
		whole++;
		fraction -= 100;
	}
	bench_put_str(buf, index, "[bench] disorder: ");
	bench_put_u64(buf, index, (t_u64)whole);
	bench_put_char(buf, index, '.');
	if (fraction < 10)
		bench_put_char(buf, index, '0');
	bench_put_u64(buf, index, (t_u64)fraction);
	bench_put_str(buf, index, "%\n");
}
