/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:24:29 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 12:25:48 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_values(int value[])
{
	int	i;
	int	j;
	int	tmp;

	i = 5;
	while (--i > 0)
	{
		j = -1;
		while (++j < i)
		{
			if (value[j] > value[j + 1])
			{
				tmp = value[j + 1];
				value[j + 1] = value[j];
				value[j] = tmp;
			}
		}
	}
	return (value[2]);
}

int	get_mid_value_five(t_node *node)
{
	int	i;
	int	value[5];

	i = -1;
	while (++i < 5)
	{
		value[i] = node->data;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (sort_values(value));
}

static void	sort_five_a(int size, t_info *info)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = get_mid_value_five(info->a->top);
	while (size--)
	{
		if (info->a->top->data < mid)
		{
			op_pb(info);
			push++;
		}
		else
		{
			op_ra(info);
			rotate++;
		}
		if (push == 2)
			break ;
	}
	while (rotate--)
		op_rra(info);
}

static void	sort_five_b(int size, t_info *info)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = get_mid_value_five(info->b->top);
	while (size--)
	{
		if (info->b->top->data >= mid)
		{
			op_pa(info);
			push++;
		}
		else
		{
			op_rb(info);
			rotate++;
		}
		if (push == 3)
			break ;
	}
	while (rotate--)
		op_rrb(info);
}

void	hanlde_sort_five(int size, t_info *info, int stack)
{
	if (stack == 'a')
		sort_five_a(size, info);
	else
		sort_five_b(size, info);
	sort_three_a(info);
	sort_two(info, 'b');
}
