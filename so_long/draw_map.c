/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:34:06 by yson              #+#    #+#             */
/*   Updated: 2021/11/19 02:10:30 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_map(t_mlx *target)
{
	int	i;
	int	j;

	i = -1;
	while (++i < target->map.height)
	{
		j = -1;
		while (++j < target->map.width)
		{
			if (target->map.info[i][j] == '1')
				draw_wall(target, j, i);
			else if (target->map.info[i][j] == '0')
				draw_bg(target, j, i);
			else if (target->map.info[i][j] == 'C')
				draw_collection(target, j, i);
			else if (target->map.info[i][j] == 'P')
				draw_player(target, j, i, KEY_D);
			else if (target->map.info[i][j] == 'E')
				draw_exit(target, j, i);
		}
	}
	return (1);
}
