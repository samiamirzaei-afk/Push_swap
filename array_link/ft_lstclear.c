/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:41:01 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/06 09:41:02 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **head, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*ptr2;

	if (!head || !del)
		return ;
	ptr = *head;
	while (ptr != NULL)
	{
		ptr2 = ptr;
		ptr = ptr->next;
		if (ptr2->content)
			del(ptr2->content);
		free(ptr2);
	}
	*head = NULL;
}
