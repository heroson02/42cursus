/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_min_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:38:44 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 12:11:51 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_data(t_node *lst, int size)
{
	int		max;
	t_node	*curr;

	curr = lst;
	max = curr->data;
	while (size--)
	{
		if (curr->data > max)
			max = curr->data;
		if (curr->next)
			curr = curr->next;
		else
			break ;
	}
	return (max);
}

int	get_min_data(t_node *lst, int size)
{
	int		min;
	t_node	*curr;

	curr = lst;
	min = curr->data;
	while (size--)
	{
		if (curr->data < min)
			min = curr->data;
		if (curr->next)
			curr = curr->next;
		else
			break ;
	}
	return (min);
}
