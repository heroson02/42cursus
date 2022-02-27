/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:34:59 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 16:52:32 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_value(t_value *value)
{
	value->pa = 0;
	value->pb = 0;
	value->ra = 0;
	value->rb = 0;
	value->pivot1 = 0;
	value->pivot2 = 0;
}

void	set_pivot(t_stack *stack, int size, t_value *var)
{
	long	max;
	long	min;

	max = get_max_data(stack->top, size);
	min = get_min_data(stack->top, size);
	var->pivot1 = (min + max) / 2;
	var->pivot2 = (min + var->pivot1) / 2;
}

void	sort_a_to_b(t_info *info, int size)
{
	t_value	var;

	if (check_special_num(info, size, 'a'))
		return ;
	init_value(&var);
	set_pivot(info->a, size, &var);
	while (size--)
		send_a_to_b(info, &var);
	if (var.ra > var.rb)
		recover_stack_ra(info, &var);
	else
		recover_stack_rb(info, &var);
	sort_a_to_b(info, var.ra);
	sort_b_to_a(info, var.rb);
	sort_b_to_a(info, var.pb - var.rb);
}

void	sort(t_info *info, int size)
{
	if (size == 5)
		sort_five(info, size, 0, 0);
	else
		sort_a_to_b(info, size);
}
