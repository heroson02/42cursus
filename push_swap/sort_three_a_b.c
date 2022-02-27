/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_a_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:24:52 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 12:28:31 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_info *info)
{
	int	arr[3];

	arr[0] = info->a->top->data;
	arr[1] = info->a->top->next->data;
	arr[2] = info->a->top->next->next->data;
	if (arr[0] > arr[1] && arr[1] > arr[2])
		sort_case321_a(info);
	else if (arr[0] > arr[2] && arr[2] > arr[1])
		sort_case312_a(info);
	else if (arr[2] > arr[0] && arr[0] > arr[1])
		sort_case213_a(info);
	else if (arr[1] > arr[0] && arr[0] > arr[2])
		sort_case231_a(info);
	else if (arr[1] > arr[2] && arr[2] > arr[0])
		sort_case132_a(info);
}

void	sort_three_b(t_info *info)
{
	int	arr[3];

	arr[0] = info->b->top->data;
	arr[1] = info->b->top->next->data;
	arr[2] = info->b->top->next->next->data;
	if (arr[2] > arr[1] && arr[1] > arr[0])
		sort_case123_b(info);
	else if (arr[0] > arr[2] && arr[2] > arr[1])
		sort_case312_b(info);
	else if (arr[2] > arr[0] && arr[0] > arr[1])
		sort_case213_b(info);
	else if (arr[1] > arr[0] && arr[0] > arr[2])
		sort_case231_b(info);
	else if (arr[1] > arr[2] && arr[2] > arr[0])
		sort_case132_b(info);
	op_pa(info);
	op_pa(info);
	op_pa(info);
}
