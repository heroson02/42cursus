/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case3_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:58:50 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 12:21:23 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_case123_b(t_info *info)
{
	if (info->size_b == 3)
	{
		op_rb(info);
		op_sb(info);
		return ;
	}
	op_sb(info);
	op_rb(info);
	op_sb(info);
	op_rrb(info);
	op_sb(info);
}

void	sort_case312_b(t_info *info)
{
	if (info->size_b == 3)
	{
		op_rrb(info);
		op_sb(info);
		return ;
	}
	op_rb(info);
	op_sb(info);
	op_rrb(info);
}

void	sort_case213_b(t_info *info)
{
	if (info->size_b == 3)
	{
		op_rrb(info);
		return ;
	}
	op_rb(info);
	op_sb(info);
	op_rrb(info);
	op_sb(info);
}

void	sort_case231_b(t_info *info)
{
	op_sb(info);
}

void	sort_case132_b(t_info *info)
{
	if (info->size_b == 3)
	{
		op_rb(info);
		return ;
	}
	op_sb(info);
	op_rb(info);
	op_sb(info);
	op_rrb(info);
}
