/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operations.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/16 21:45:37 by sfurst           #+#    #+#              */
/*   Updated: 2026/07/16 22:04:32 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push.h"
#include "../../include/strutils.h"

void	emit_operation(t_ps *ps, const char *name)
{
	char	buf[16];
	size_t	len;

	ps->operations++;
	if (!PUSH_PRINT_OPERATIONS)
		return ;
	len = ft_strlen(name);
	ft_memcpy(buf, name, len);
	buf[len] = '\n';
	write(STDOUT_FILENO, buf, len + 1);
}

void	exec_swap(t_stack *stack)
{
	t_node	*second;
	t_i32	value;
	t_i32	index;

	if (stack->size < 2)
		return ;
	second = stack->top->next;
	value = stack->top->value;
	index = stack->top->index;
	stack->top->value = second->value;
	stack->top->index = second->index;
	second->value = value;
	second->index = index;
}

void	exec_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return ;
	first = stack->top;
	last = first;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	exec_reverse_rotate(t_stack *stack)
{
	t_node	*before_last;
	t_node	*last;

	if (stack->size < 2)
		return ;
	before_last = stack->top;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
}
