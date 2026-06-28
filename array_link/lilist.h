/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:07:33 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/06 17:23:38 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LILIST_H
# define LILIST_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int		num;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_front( t_list **list, t_list *new);
int		ft_lstsize(t_list *list);
t_list	*ft_lstlast(t_list *list);
void	ft_lstadd_back(t_list **list, t_list *new);
void	ft_lstdelone(t_list *trash, void (*del)(void*));
void	ft_lstclear(t_list **head, void (*del)(void*));
void	ft_lstiter(t_list *list, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
			void (*del)(void *));
int	ft_atoi(char *str);

#endif
