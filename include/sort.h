/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort.h                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/27 16:27:45 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/27 16:27:46 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

typedef struct s_ps	t_ps;

void				adaptive_sort(t_ps *ps);
void				bubble_sort(t_ps *ps);
void				chunk_sort(t_ps *ps);
void				radix_sort(t_ps *ps);
void				selection_sort(t_ps *ps);

#endif
