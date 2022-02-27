/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_size_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:40:20 by yson              #+#    #+#             */
/*   Updated: 2021/11/19 02:25:18 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	screen_size_check(t_mlx *target)
{
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(target->mlx, &screen_width, &screen_height);
	if (target->map.height * CELL_SIZE > screen_height)
		error_exit("Error! Height of map is too large.");
	if (target->map.width * CELL_SIZE > screen_width)
		error_exit("Error! Error! Width of map is too large.");
}
