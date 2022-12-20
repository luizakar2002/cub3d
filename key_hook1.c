/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:37:05 by lukarape          #+#    #+#             */
/*   Updated: 2022/02/15 19:59:35 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(double s)
{
	if (map.map[(int)(player.y + player.dir_y * s)]
								[(int)(player.x)] == '0')
		player.y += player.dir_y * s;
	if (map.map[(int)(player.y)]
			[(int)(player.x + player.dir_x * s)] == '0')
		player.x += player.dir_x * s;
}

void	move_back(double s)
{
	if (map.map[(int)(player.y - player.dir_y * s)]
								[(int)(player.x)] == '0')
		player.y -= player.dir_y * s;
	if (map.map[(int)(player.y)]
			[(int)(player.x - player.dir_x * s)] == '0')
		player.x -= player.dir_x * s;
}

void	move_left(double s)
{
	if (map.map[(int)(player.y - player.dir_x * s)]
								[(int)(player.x)] == '0')
		player.y -= player.dir_x * s;
	if (map.map[(int)(player.y)]
			[(int)(player.x + player.dir_y * s)] == '0')
		player.x += player.dir_y * s;
}

void	move_right(double s)
{
	if (map.map[(int)(player.y + player.dir_x * s)]
								[(int)(player.x)] == '0')
		player.y += player.dir_x * s;
	if (map.map[(int)(player.y)]
			[(int)(player.x - player.dir_y * s)] == '0')
		player.x -= player.dir_y * s;
}

void	turn_right(double r)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player.dir_y;
	old_plane_x = player.plane_y;
	player.dir_y = player.dir_y * cos(-r) - player.dir_x * sin(-r);
	player.dir_x = old_dir_x * sin(-r) + player.dir_x * cos(-r);
	player.plane_y = player.plane_y * cos(-r) - player.plane_x * sin(-r);
	player.plane_x = old_plane_x * sin(-r) + player.plane_x * cos(-r);
}
