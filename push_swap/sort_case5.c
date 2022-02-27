/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:18:00 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 16:52:08 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_info *info, int size, int min, int max)
{
	t_node	*curr;
	int		pb;

	pb = 0;
	min = get_min_data(info->a->top, 5);
	max = get_max_data(info->a->top, 5);
	while (size-- && pb < 2)
	{
		curr = info->a->top;
		if (curr->data == max || curr->data == min)
		{
			op_pb(info);
			pb++;
		}
		else
			op_ra(info);
	}
	sort_three_a(info);
	sort_two(info, 'b');
	op_sa(info);
	op_ra(info);
}
