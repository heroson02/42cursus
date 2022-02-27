/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:39:25 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 12:15:50 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_info *info)
{
	swap_stack(info->a, info->size_a);
	ft_printf("sa\n");
}

void	op_sb(t_info *info)
{
	swap_stack(info->b, info->size_b);
	ft_printf("sb\n");
}

void	op_ss(t_info *info)
{
	swap_stack(info->a, info->size_a);
	swap_stack(info->b, info->size_b);
	ft_printf("ss\n");
}

void	op_pa(t_info *info)
{
	push_top(info->b, info->a);
	info->size_a++;
	info->size_b--;
	ft_printf("pa\n");
}

void	op_pb(t_info *info)
{
	push_top(info->a, info->b);
	info->size_a--;
	info->size_b++;
	ft_printf("pb\n");
}
