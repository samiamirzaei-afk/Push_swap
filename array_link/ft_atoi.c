/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:48:47 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/06 17:18:40 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static int	ft_negative_add(const char *str, int *i)
{
	int	negative;

	negative = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			negative *= -1;
		*i += 1;
	}
	return (negative);
}

static int	ft_isspace(char letter)
{
	if ((letter >= '\t' && letter <= '\r') || letter == ' ')
		return (1);
	return (-1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	result_l;
	int	result;

	if (!str)
		return (0);
	i = 0;
	negative = 0;
	result_l = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	negative = ft_negative_add(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result_l = (result_l * 10) + (str[i] - '0');
		i++;
	}
	result = result_l;
	return (result * negative);
}
/*
#include <stdio.h>
#include <stdlib.h>





int	main(void)
{
	int		i;
	char	str[] = {"0123456789"};
	char	str2[20] = {"2"};
	char	str3[] = {"0123456789"};
	char	str4[20] = {"2"};
	int		len;
	int		ft_len;
	char	str21[20] = {"      53g345"};
	char	str41[20] = {"      53g345"};
	char	str11[] = {""};
	char	str211[20] = {""};
	char	str311[] = {""};
	char	str411[20] = {""};
	char	str12[] = {"-2147483648"};
	char	str312[] = {"-2147483648"};
	char	sstr33[13] = {"2147483647"};
	char	sstr55[13] = {"2147483647"};
	char	sstr44[] = {"214748364252352352352352711111"};
	char	sstr66[] = {"214748364252352352352352711111"};

	i = 0;
	printf("strings before: '%s'\n", str);
	len = atoi(str);
	ft_len = ft_atoi(str3);
	printf("atoi:'%d'\n",len);
	printf("ft_atoi:'%d'\n\n",ft_len);
	printf("\n\n");
	printf("strings before: '%s'\n", str21);
	len = atoi(str21);
	ft_len = ft_atoi(str41);
	printf("atoi:'%d'\n",len);
	printf("ft_atoi:'%d'\n\n",ft_len);
	printf("\n\n");
	printf("strings before: '%s'\n", str11);
	len = atoi(str211);
	ft_len = ft_atoi(str411);
	printf("atoi:'%d'\n",len);
	printf("ft_atoi:'%d'\n\n",ft_len);
	printf("\n\n");
	printf("strings before: '%s'\n", str12);
	len = atoi(str12);
	ft_len = ft_atoi(str312);
	printf("strrchr:'%d'\n",len);
	printf("ft_strrchr:'%d'\n\n",ft_len);
		printf("\n\n");
	printf("strings before:'%s'\n", sstr33);
	len = atoi(sstr33);
	ft_len =ft_atoi(sstr55);
	printf("strrchr: '%d'\n",len);
	printf("ft_strrchr: '%d'\n\n", ft_len);
		printf("\n\n");
	printf("strings before:'%s'\n", sstr44);
	len = atoi(sstr44);
	ft_len =ft_atoi(sstr66);
	printf("strrchr: '%d'\n",len);
	printf("ft_strrchr: '%d'\n\n", ft_len);
}
*/
