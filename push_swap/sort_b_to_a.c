/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:35:36 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 12:21:46 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_to_a(t_info *info, int size)
{
	t_value	var;

	info->check++;
	if (check_special_num(info, size, 'b'))
		return ;
	init_value(&var);
	set_pivot(info->b, size, &var);
	while (size--)
		send_b_to_a(info, &var);
	sort_a_to_b(info, var.pa - var.ra);
	if (var.ra > var.rb)
		recover_stack_ra(info, &var);
	else
		recover_stack_rb(info, &var);
	sort_a_to_b(info, var.ra);
	sort_b_to_a(info, var.rb);
}
