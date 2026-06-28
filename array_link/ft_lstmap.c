/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:41:39 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/07 16:17:31 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr_copy;
	t_list	*start;
	void	*temp;

	if (!list || !f || !del)
		return (NULL);
	ptr_copy = list;
	start = NULL;
	while (list)
	{
		temp = f(list->content);
		ptr_copy = ft_lstnew(temp);
		if (ptr_copy == NULL)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, ptr_copy);
		list = list->next;
	}
	return (start);
}

/*
t_list	*ft_lstmap(t_list *list, void *(*ft_f)(void *), void(*del)(void*))
{
	t_list	*ptr_copy;
	t_list	*ptr;

	if(!list || ft_f)
		return (NULL);
	ptr_copy = NULL;
	while(list)
	{
		ptr = ft_lstnew(ft_f(list->content));
		if (!ptr)
		{
			ft_lstclear(&ptr, del);
			return (NULL);
		}
		ft_lstadd_back(&ptr_copy, ptr);
		lst = lst->next;
	}
	return(copy);
}
*/

/*
static t_list	*list_maker(void)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if(ptr = NULL)
		return (NULL);
	return(ptr);
}


static t_list	*copy_maker(t_list *list, void *(*ft_f)(void *))
{
	t_list	*ptr_copy;
	t_list	*ptr_list;
	t_list	*copy_start;

	ptr_copy = list;
	ptr_list = list;
	copy_start = ptr1;
	ptr_copy->content = ft_f(list->content);
	while(ptr_list != NULL)
	{
		ptr_copy = list_maker();
		if(ptr_copy)
			return(NULL);
		ptr_copy->content = (char *)ft_f(ptr_list->content);
		if(ptr_copy)
		{
			ft_lstclear(
			return(NULL);
		}
		ptr_list = ptr_list->next;
		ptr_copy->next = ptr_list;
		ptr_copy = ptr_list
	}
	return (copy_start);
}

t_list	*ft_lstmap(t_list *list, void *(*ft_f)(void *), void(*del)(void*))
{
	t_list	*ptr1;
	t_list	*ptr2;
	t_list	*copy;

	if(!list)
		return (NULL);
	copy = copy_maker(list, ft_f);
	if(!copy)
		return (NULL);
	ptr1 = list;
	ptr2 = list;
	while(ptr1 != NULL)
	{
		if(ptr1->content)
			del(ptr1->content);
		ptr1 = ptr1->next;
		free(ptr2);
		ptr2 = ptr1;
	}
	return(copy);
}
*/
