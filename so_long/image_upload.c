/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_upload.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:47:47 by yson              #+#    #+#             */
/*   Updated: 2021/11/19 02:14:21 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_upload(t_mlx *target)
{
	int	x;
	int	y;

	target->image.character_right = mlx_xpm_file_to_image(target->mlx,
			"image/mario100_right.xpm", &x, &y);
	target->image.character_left = mlx_xpm_file_to_image(target->mlx,
			"image/mario100_left.xpm", &x, &y);
	target->image.character_face = mlx_xpm_file_to_image(target->mlx,
			"image/mario100_face.xpm", &x, &y);
	target->image.character_back = mlx_xpm_file_to_image(target->mlx,
			"image/mario100_back.xpm", &x, &y);
	target->image.background = mlx_xpm_file_to_image(target->mlx,
			"image/grass100.xpm", &x, &y);
	target->image.collection = mlx_xpm_file_to_image(target->mlx,
			"image/coin100.xpm", &x, &y);
	target->image.wall = mlx_xpm_file_to_image(target->mlx,
			"image/brick100.xpm", &x, &y);
	target->image.exit = mlx_xpm_file_to_image(target->mlx,
			"image/flag100.xpm", &x, &y);
}
