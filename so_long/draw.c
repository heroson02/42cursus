/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:43:12 by yson              #+#    #+#             */
/*   Updated: 2021/11/19 02:12:05 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(t_mlx *target, int x, int y)
{
	mlx_put_image_to_window(target->mlx, target->win,
		target->image.wall, x * CELL_SIZE, y * CELL_SIZE);
}

void	draw_bg(t_mlx *target, int x, int y)
{
	mlx_put_image_to_window(target->mlx, target->win,
		target->image.background, x * CELL_SIZE, y * CELL_SIZE);
}

void	draw_collection(t_mlx *target, int x, int y)
{
	draw_bg(target, x, y);
	mlx_put_image_to_window(target->mlx, target->win,
		target->image.collection, x * CELL_SIZE, y * CELL_SIZE);
}

void	draw_player(t_mlx *target, int x, int y, int keycode)
{
	draw_bg(target, x, y);
	if (keycode == KEY_D)
		mlx_put_image_to_window(target->mlx, target->win,
			target->image.character_right, x * CELL_SIZE, y * CELL_SIZE);
	else if (keycode == KEY_A)
		mlx_put_image_to_window(target->mlx, target->win,
			target->image.character_left, x * CELL_SIZE, y * CELL_SIZE);
	else if (keycode == KEY_W)
		mlx_put_image_to_window(target->mlx, target->win,
			target->image.character_back, x * CELL_SIZE, y * CELL_SIZE);
	else if (keycode == KEY_S)
		mlx_put_image_to_window(target->mlx, target->win,
			target->image.character_face, x * CELL_SIZE, y * CELL_SIZE);
	else
		return ;
}

void	draw_exit(t_mlx *target, int x, int y)
{
	draw_bg(target, x, y);
	mlx_put_image_to_window(target->mlx, target->win,
		target->image.exit, x * CELL_SIZE, y * CELL_SIZE);
}
