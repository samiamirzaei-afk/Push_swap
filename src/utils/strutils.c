/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   strutils.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/16 21:54:40 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/31 22:16:02 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/qol.h"
#include "../../include/strutils.h"

t_i64	ft_strlen(const char *str)
{
	t_i64	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dstc;
	unsigned char	*srcc;

	dstc = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	while (n--)
		*dstc++ = *srcc++;
	return (dst);
}

t_i8	ft_strcmp(const char *s1, const char *s2)
{
	t_i8	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

t_i8	ft_strncmp(const char *s1, const char *s2, t_i8 n)
{
	t_i8	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
