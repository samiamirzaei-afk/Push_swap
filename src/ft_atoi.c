/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_atoi.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/16 21:45:44 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/16 21:45:44 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

t_t_i32_result	ft_parse_uint(const char *str, int is_u32)
{
	t_t_i32_result	result;
	t_u64			digit;

	result.status = t_i32_err;
	result.value = 0;
	if (!str || !*str)
		return (result);
	while (*str)
	{
		if (!is_digit(*str))
			return (result);
		digit = (t_u64)(*str - '0');
		if (result.value > (UINT64_MAX - digit) / 10)
			return (result);
		result.value = result.value * 10 + digit;
		str++;
	}
	if (is_u32 && result.value > UINT32_MAX)
		return (result);
	result.status = t_i32_ok;
	return (result);
}

t_parse_result	parse_i32(const char *str)
{
	t_parse_result	result;
	t_t_i32_result	parsed;
	const char		*digits;
	t_u64			limit;

	result.status = t_i32_err;
	result.value = 0;
	if (!str || !*str)
		return (result);
	digits = str;
	if (*digits == '+' || *digits == '-')
		digits++;
	parsed = ft_parse_uint(digits, 0);
	if (parsed.status == t_i32_err)
		return (result);
	limit = INT_MAX;
	if (str[0] == '-')
		limit = (t_u64)INT_MAX + 1;
	if (parsed.value > limit)
		return (result);
	if (str[0] == '-')
		result.value = (t_i32)(-(t_i64)parsed.value);
	else
		result.value = (t_i32)parsed.value;
	result.status = t_i32_ok;
	return (result);
}
