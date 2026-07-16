/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   strutils.h                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/16 21:55:14 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/16 22:09:13 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUTILS_H
# define STRUTILS_H

# include "qol.h"

void	*ft_memcpy(void *dst, const void *src, size_t n);
t_i64	ft_strlen(const char *str);

t_i8	ft_strcmp(const char *s1, const char *s2);
t_i8	ft_strncmp(const char *s1, const char *s2, t_i8 n);

#endif
