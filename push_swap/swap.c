/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:20:44 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 12:26:45 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_int(int *a, int *b)
{
	int	temp;

	if (*a == *b)
		return ;
	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap_stack(t_stack *stack, int size)
{
	t_node	**lst;

	if (!(stack->top) || size <= 1)
		return ;
	lst = &(stack->top);
	if (!((*lst)->next) || (*lst)->next == *lst)
		return ;
	ft_swap_int(&((*lst)->data), &((*lst)->next->data));
}
