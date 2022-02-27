/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:41:24 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 12:17:06 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_pop(t_stack *stack)
{
	t_node	*temp;

	temp = stack->top;
	if (!(&(stack->top)))
		return (NULL);
	if (stack->top->next == NULL && stack->top->prev == NULL)
		stack->top = NULL;
	else
	{
		stack->top->next->prev = NULL;
		stack->top->next = temp->next;
		stack->top = stack->top->next;
	}
	return (temp);
}

void	push_stack(t_info *info, char *data)
{
	long long	ll;

	ll = ft_atoi_ad(data);
	if (ll < -2147483648 || ll > 2147483647)
		error();
	aft_lstadd_back(&info->a->top, aft_lstnew((int)ll));
	info->size_a++;
}

void	push_top(t_stack *send, t_stack *receive)
{
	if (!send | !send->top)
		return ;
	aft_lstadd_front(&receive->top, ft_pop(send));
}
