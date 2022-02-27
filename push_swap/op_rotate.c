/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:07:29 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 12:47:30 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_info *info)
{
	rotate_stack(info->a, info->size_a);
	ft_printf("ra\n");
}

void	op_rb(t_info *info)
{
	rotate_stack(info->b, info->size_b);
	ft_printf("rb\n");
}

void	op_rr(t_info *info)
{
	rotate_stack(info->a, info->size_a);
	rotate_stack(info->b, info->size_b);
	ft_printf("rr\n");
}
