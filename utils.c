/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 10:51:04 by ammirzae          #+#    #+#             */
/*   Updated: 2026/06/19 12:46:50 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_isdigit_plus(int num)
{
	short result;
	
	result = ft_issymbol(num);
	if ((num >= '0' && num <= '9') || result == 1)
		return (1);
	return (0);
}
//-
int	ft_isdigit_str(char *str)
{
	int	i;
	int	sign;

	sign = 0;
	i = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		sign = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
	{
		if (i == 1 && sign == 1)
			return (0);
		return (1);
	}
	return (0);
}

int	ft_isdigit(int num)
{
	if ((num >= '0' && num <= '9'))
		return (1);
	return (0);
}
int	ft_isalpha(int number)
{
	if (number >= 'A' && number <= 'z')
	{
		if (!(number >= '[' && number <= '`'))
			return (1);
	}
	return (0);
}
