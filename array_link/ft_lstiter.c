/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:41:23 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/06 09:41:24 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *list, void (*f)(void *))
{
	if (!list)
		return ;
	while (list != NULL)
	{
		f(list->content);
		list = list->next;
	}
}
/*
void	f(void *content)
{
	while(content)
	{
		content = '0';
		content += 1;
	}
}
*/
