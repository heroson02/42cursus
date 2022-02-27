/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_low_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:42:05 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 12:25:23 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_info *info, int stack)
{
	if (stack == 'a')
	{
		if (info->a->top->data > info->a->top->next->data)
			op_sa(info);
	}
	else
	{
		if (info->b->top->data < info->b->top->next->data)
			op_sb(info);
		op_pa(info);
		op_pa(info);
	}
}

int	sort_low_num(t_info *info, int size, int stack)
{
	if (size == 1)
	{
		if (stack == 'b')
			op_pa(info);
		return (1);
	}
	else if (size == 2)
	{
		sort_two(info, stack);
		return (1);
	}
	else if (size == 3)
	{
		if (stack == 'a')
			sort_three_a(info);
		else
			sort_three_b(info);
		return (1);
	}
	else
		return (0);
}

void	sort_four_a(t_info *info)
{
	t_node	*curr;
	t_value	var;
	int		tmp;

	init_value(&var);
	var.pivot1 = get_min_data(info->a->top, 4);
	tmp = info->size_a;
	while (tmp--)
	{
		curr = info->a->top;
		if (curr->data == var.pivot1)
			break ;
		else
			op_ra(info);
	}
	op_pb(info);
	sort_three_a(info);
	op_pa(info);
}

int	check_special_num(t_info *info, int size, int stack)
{
	if (size <= 3)
	{
		sort_low_num(info, size, stack);
		return (1);
	}
	else if (size == 4 && stack == 'a' && info->size_a == 4)
	{
		sort_four_a(info);
		return (1);
	}
	else if (size == 5)
	{
		hanlde_sort_five(size, info, stack);
		return (1);
	}
	else
		return (0);
}
