/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:33:00 by yson              #+#    #+#             */
/*   Updated: 2021/11/19 02:22:31 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	target;

	if (argc != 2)
	{
		write(1, "Please put a map file only.\n", 28);
		return (0);
	}
	read_map(argv[1], &target);
	check_map(&target);
	map_init(&target);
	image_upload(&target);
	draw_map(&target);
	mlx_hook(target.win, KEY_PRESS, 0, &key_press, &target);
	mlx_hook(target.win, KEY_EXIT, 0, &quit_game, &target);
	mlx_loop(target.mlx);
}
