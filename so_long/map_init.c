/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:23:18 by yson              #+#    #+#             */
/*   Updated: 2021/11/19 02:22:41 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_mlx *target)
{
	int	width;
	int	height;

	width = target->map.width * CELL_SIZE;
	height = target->map.height * CELL_SIZE;
	target->mlx = mlx_init();
	target->win = mlx_new_window(target->mlx, width, height, "so_long");
}
