/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:18:08 by yson              #+#    #+#             */
/*   Updated: 2021/07/20 00:05:51 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		head = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		(*lst) = head;
	}
	(*lst) = 0;
}
