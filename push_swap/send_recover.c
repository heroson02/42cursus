/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_recover.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:42:59 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 12:18:42 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	recover_stack_ra(t_info *info, t_value *var)
{
	int	rrr;
	int	ra;

	rrr = var->rb;
	ra = var->ra - rrr;
	if (info->check > 0)
	{
		while (rrr--)
			op_rrr(info);
		while (ra--)
			op_rra(info);
	}
	else
	{
		while (rrr--)
			op_rrb(info);
	}
}

void	recover_stack_rb(t_info *info, t_value *var)
{
	int	rrr;
	int	rb;

	rrr = var->ra;
	rb = var->rb - rrr;
	if (info->check > 0)
	{
		while (rrr--)
			op_rrr(info);
		while (rb--)
			op_rrb(info);
	}
	else
	{
		rrr = var->rb;
		while (rrr--)
			op_rrb(info);
	}
}

void	send_a_to_b(t_info *info, t_value *var)
{
	if (info->a->top->data > var->pivot1)
	{
		op_ra(info);
		var->ra++;
	}
	else
	{
		op_pb(info);
		var->pb++;
		if (info->b->top->data > var->pivot2)
		{
			op_rb(info);
			var->rb++;
		}
	}
}

void	send_b_to_a(t_info *info, t_value *var)
{
	if (info->b->top->data <= var->pivot2)
	{
		op_rb(info);
		var->rb++;
	}
	else
	{
		op_pa(info);
		var->pa++;
		if (info->a->top->data <= var->pivot1)
		{
			op_ra(info);
			var->ra++;
		}
	}
}
