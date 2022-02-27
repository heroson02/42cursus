/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:09:03 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 01:59:57 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_info *info)
{
	rev_rotate_stack(info->a, info->size_a);
	ft_printf("rra\n");
}

void	op_rrb(t_info *info)
{
	rev_rotate_stack(info->b, info->size_b);
	ft_printf("rrb\n");
}

void	op_rrr(t_info *info)
{
	rev_rotate_stack(info->a, info->size_a);
	rev_rotate_stack(info->b, info->size_b);
	ft_printf("rrr\n");
}
