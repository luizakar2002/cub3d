/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:36:10 by lukarape          #+#    #+#             */
/*   Updated: 2022/02/15 19:59:29 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode)
{
	mlx_destroy_image(win.mlx, win.data.img);
	if (keycode == 13)
		move_forward(0.5);
	if (keycode == 1)
		move_back(0.5);
	if (keycode == 0)
		move_left(0.5);
	if (keycode == 2)
		move_right(0.5);
	if (keycode == 124)
		turn_right(0.2);
	if (keycode == 123)
		turn_left(0.2);
	if (keycode == 53)
		close_win();
	draw_map();
	return (0);
}

int	close_win(void)
{
	exit(0);
	return (0);
}

void	turn_left(double r)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player.dir_y;
	old_plane_x = player.plane_y;
	player.dir_y = player.dir_y * cos(r) - player.dir_x * sin(r);
	player.dir_x = old_dir_x * sin(r) + player.dir_x * cos(r);
	player.plane_y = player.plane_y * cos(r) - player.plane_x * sin(r);
	player.plane_x = old_plane_x * sin(r) + player.plane_x * cos(r);
}
