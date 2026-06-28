/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 16:24:12 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/06 16:47:35 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **list, t_list *new)
{
	if (!list || !new)
		return ;
	new->next = *list;
	*list = new;
	return ;
}
/*
int	main()
{

	t_list *link01;
	t_list *link02;
	t_list *link03;
	t_list *link04;
	t_list *link05;
	t_list *link06;
	char str01[] = "The ";
	char str02[] = "number ";
	char str03[] = "42";
	char str04[] = "The ";
	char str05[] = "unlimate ";
	char str06[] = "answer? ";

	link01 = ft_lstnew(str01);
	if (!link01)
		return(0);
	link02 = ft_lstnew(str02);
	if (!link02)
		return(0);
	link03 = ft_lstnew(str03);
	if (!link03)
		return(0);
	link04 = ft_lstnew(str04);
	if (!link04)
		return(0);
	link05 = ft_lstnew(str05);
	if (!link05)
		return(0);
	link06 = ft_lstnew(str06);
	if (!link06)
		return(0);

	link01->next = link02;
	link02->next = link03;

	ft_lstadd_front(&link01, link06);
	ft_lstadd_front(&link06, link05);
	ft_lstadd_front(&link05, link04);


	printf("full text:'");
	printf("%s", (char*)(link04->content));
	printf("%s", (char*)(link04->next->content));
	printf("%s", (char*)(link04->next->next->content));
	printf("%s", (char*)(link04->next->next->next->content));
	printf("%s", (char*)(link04->next->next->next->next->content));
printf("%s'\n", (char*)(link04->next->next->next->next->next->content));
}
*/
