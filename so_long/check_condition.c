/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 02:21:38 by yson              #+#    #+#             */
/*   Updated: 2021/11/19 02:22:08 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_end_check(t_mlx *target, int x, int y)
{
	if (target->map.info[x][y] == '1' || target->map.info[x][y] == 'E')
		return (1);
	return (0);
}

int	check_wall(int keycode, t_mlx *target)
{
	if (keycode == KEY_W && wall_end_check(target,
			target->user.y - 1, target->user.x))
		return (0);
	else if (keycode == KEY_A && wall_end_check(target,
			target->user.y, target->user.x - 1))
		return (0);
	else if (keycode == KEY_D && wall_end_check(target,
			target->user.y, target->user.x + 1))
		return (0);
	else if (keycode == KEY_S && wall_end_check(target,
			target->user.y + 1, target->user.x))
		return (0);
	return (1);
}

int	check_collection(int keycode, t_mlx *target)
{
	if (keycode == KEY_W
		&& target->map.info[target->user.y - 1][target->user.x] == 'C')
		return (1);
	else if (keycode == KEY_A
		&& target->map.info[target->user.y][target->user.x - 1] == 'C')
		return (1);
	else if (keycode == KEY_D
		&& target->map.info[target->user.y][target->user.x + 1] == 'C')
		return (1);
	else if (keycode == KEY_S
		&& target->map.info[target->user.y + 1][target->user.x] == 'C')
		return (1);
	return (0);
}

int	check_end(int keycode, t_mlx *target)
{
	if (target->user.collection > 0)
		return (0);
	if (keycode == KEY_W
		&& target->map.info[target->user.y - 1][target->user.x] == 'E')
		return (1);
	else if (keycode == KEY_A
		&& target->map.info[target->user.y][target->user.x - 1] == 'E')
		return (1);
	else if (keycode == KEY_D
		&& target->map.info[target->user.y][target->user.x + 1] == 'E')
		return (1);
	else if (keycode == KEY_S
		&& target->map.info[target->user.y + 1][target->user.x] == 'E')
		return (1);
	return (0);
}
