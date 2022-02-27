/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:14:26 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 12:14:20 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_lst(t_node *head)
{
	t_node	*curr;
	t_node	*next;

	curr = head;
	if (!curr)
		return ;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

void	free_stack(t_stack *stack)
{
	free_lst(stack->top);
}

void	free_exit(t_stack *stack)
{
	free_stack(stack);
	exit(0);
}
