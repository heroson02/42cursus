/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_condition_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 00:09:29 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 12:26:31 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_check(t_stack *a)
{
	t_node	*curr;

	if (!(a->top))
		return (0);
	curr = a->top;
	while (curr->next)
	{
		if ((curr->data > curr->next->data))
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	dup_check(t_stack *stack)
{
	t_node	*i;
	t_node	*j;

	if (!(stack->top))
		return (0);
	i = stack->top;
	while (i->next)
	{
		j = i->next;
		while (j->next)
		{
			if (i->data == j->data)
				return (1);
			j = j->next;
		}
		if (i->data == j->data)
			return (1);
		i = i->next;
	}
	return (0);
}

void	source_condition_check(t_stack *a)
{
	if (dup_check(a))
		error();
	if (sort_check(a))
		exit(0);
}
