/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:19:16 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 12:13:45 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*aft_lstnew(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = content;
	return (node);
}

t_node	*aft_lstlast(t_node *lst)
{
	t_node	*curr;

	if (!lst)
		return (0);
	curr = lst;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

void	aft_lstadd_front(t_node **lst, t_node *new)
{
	if (!new)
		return ;
	if (*lst)
	{
		new->next = (*lst);
		(*lst)->prev = new;
	}
	else
	{
		(*lst) = new;
		(*lst)->next = NULL;
	}
	(*lst) = NULL;
	(*lst) = new;
}

void	aft_lstadd_back(t_node **lst, t_node *new)
{
	if (!new)
		return ;
	if (*lst)
	{
		new->prev = aft_lstlast(*lst);
		aft_lstlast(*lst)->next = new;
	}
	else
	{
		(*lst) = new;
		(*lst)->prev = NULL;
	}
	new->next = NULL;
}
