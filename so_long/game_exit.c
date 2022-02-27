/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:53:52 by yson              #+#    #+#             */
/*   Updated: 2021/11/19 03:23:37 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit_game(t_mlx *target)
{
	mlx_destroy_image(target->mlx, target->image.background);
	mlx_destroy_image(target->mlx, target->image.character_back);
	mlx_destroy_image(target->mlx, target->image.character_face);
	mlx_destroy_image(target->mlx, target->image.character_left);
	mlx_destroy_image(target->mlx, target->image.character_right);
	mlx_destroy_image(target->mlx, target->image.collection);
	mlx_destroy_image(target->mlx, target->image.exit);
	mlx_destroy_image(target->mlx, target->image.wall);
	mlx_destroy_window(target->mlx, target->win);
	exit(0);
}

void	game_clear(t_mlx *target)
{
	write(1, "Game Clear!\n", 12);
	quit_game(target);
}

void	error_exit(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
	write(1, "\n", 1);
	exit(0);
}
