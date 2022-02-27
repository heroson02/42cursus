/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:09:42 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 12:17:23 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack *stack, int size)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next || size <= 1)
		return ;
	first = stack->top;
	first->next->prev = NULL;
	stack->top = stack->top->next;
	last = aft_lstlast(stack->top);
	first->prev = last;
	last->next = first;
	first->next = NULL;
}

void	rev_rotate_stack(t_stack *stack, int size)
{
	t_node	*last;
	t_node	*new_last;

	if (!stack || !stack->top || !stack->top->next || size <= 1)
		return ;
	last = aft_lstlast(stack->top);
	last->next = stack->top;
	stack->top->prev = last;
	new_last = last->prev;
	new_last->next = NULL;
	last->prev = NULL;
	stack->top = last;
}
