/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:42:29 by yson              #+#    #+#             */
/*   Updated: 2021/11/19 02:21:22 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	user_move(int keycode, t_mlx *target)
{
	if (check_end(keycode, target))
		game_clear(target);
	if (!check_wall(keycode, target))
		return ;
	if (check_collection(keycode, target))
		target->user.collection--;
	draw_bg(target, target->user.x, target->user.y);
	target->map.info[target->user.y][target->user.x] = '0';
	if (keycode == KEY_W)
		target->user.y--;
	else if (keycode == KEY_A)
		target->user.x--;
	else if (keycode == KEY_S)
		target->user.y++;
	else if (keycode == KEY_D)
		target->user.x++;
	print_movement(++target->user.movement);
	target->map.info[target->user.y][target->user.x] = 'P';
	draw_player(target, target->user.x, target->user.y, keycode);
}

int	key_press(int keycode, t_mlx *target)
{
	if (keycode == KEY_ESC)
		quit_game(target);
	else if (keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_A || keycode == KEY_D)
		user_move(keycode, target);
	return (0);
}
