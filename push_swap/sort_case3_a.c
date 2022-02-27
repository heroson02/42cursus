/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case3_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:58:56 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 12:21:05 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_case321_a(t_info *info)
{
	if (info->size_a == 3)
	{
		op_sa(info);
		op_rra(info);
		return ;
	}
	op_sa(info);
	op_ra(info);
	op_sa(info);
	op_rra(info);
	op_sa(info);
}

void	sort_case312_a(t_info *info)
{
	if (info->size_a == 3)
		op_ra(info);
	else
	{
		op_sa(info);
		op_ra(info);
		op_sa(info);
		op_rra(info);
	}
}

void	sort_case213_a(t_info *info)
{
	op_sa(info);
}

void	sort_case231_a(t_info *info)
{
	if (info->size_a == 3)
		op_rra(info);
	else
	{
		op_ra(info);
		op_sa(info);
		op_rra(info);
		op_sa(info);
	}
}

void	sort_case132_a(t_info *info)
{
	if (info->size_a == 3)
	{
		op_rra(info);
		op_sa(info);
		return ;
	}
	op_ra(info);
	op_sa(info);
	op_rra(info);
}
