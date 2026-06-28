/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 16:26:30 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/02 16:50:17 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *list)
{
	int		i;
	t_list	*ptr;

	if (!list)
		return (0);
	ptr = list;
	i = 0;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	t_list	*list01;
	t_list	*list02;
	t_list	*list03;
	t_list	*list04;
	t_list	*list05;
	t_list	*list06;

	list01 = malloc(sizeof(t_list));
	list02 = malloc(sizeof(t_list));
	list03 = malloc(sizeof(t_list));
	list04 = malloc(sizeof(t_list));
	list05 = malloc(sizeof(t_list));
	list06 = malloc(sizeof(t_list));
	list01->next = list02;
	list02->next = list03;
	list03->next = list04;
	list04->next = list05;
	list05->next = list06;
	list06->next = NULL;
	printf("%d\n",ft_lstsize(list01));
	return (0);
}
*/
