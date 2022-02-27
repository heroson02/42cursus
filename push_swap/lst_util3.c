/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:44:06 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 12:15:03 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	aft_lstsize(t_node *lst)
{
	int		count;
	t_node	*curr;

	if (!lst)
		return (0);
	count = 0;
	curr = lst;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}

int	aft_lstdata(t_node *lst, int index)
{
	t_node	*curr;
	int		i;

	if (!lst)
		return (0);
	i = 0;
	curr = lst;
	while (curr)
	{
		if (i == index)
			return (i);
		i++;
		curr = curr->next;
	}
	return (0);
}

void	aft_lstread(t_node **lst)
{
	t_node	*curr;

	if (!(*lst))
	{
		ft_printf("List is NULL\n");
		return ;
	}
	curr = (*lst);
	ft_printf("list : ");
	while (curr->next)
	{
		ft_printf("%d->", curr->data);
		curr = curr->next;
	}
	ft_printf("%d", curr->data);
	ft_printf("\n");
}

void	aft_lstread_rev(t_node **lst)
{
	t_node	*curr;

	if (!(*lst))
		return ;
	curr = aft_lstlast(*lst);
	while (curr->prev)
	{
		ft_printf("%d ", curr->data);
		curr = curr->prev;
	}
	ft_printf("%d ", curr->data);
}
