/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:58:28 by lukarape          #+#    #+#             */
/*   Updated: 2022/02/15 20:00:32 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_colors(t_vars *v, int *x, int *y)
{
	if (*y < v->draw_start)
		my_mlx_pixel_put(&win.data, *x, *y, map.ceiling);
	if (*y >= v->draw_start && *y <= v->draw_end)
		attach_textures(v, x, y);
	if (*y > v->draw_end && *y < win.screen_width)
		my_mlx_pixel_put(&win.data, *x, *y, map.floor);
}

void	attach_textures(t_vars *v, int *x, int *y)
{
	v->tex_y = (int)v->tex_pos & (TEXSIDE - 1);
	v->tex_pos += v->step;
	if (v->side == 0)
	{
		if (v->step_x > 0)
			my_mlx_pixel_put(&win.data, *x, *y,
				get_pixel(&win.south, v->tex_x, v->tex_y));
		else
			my_mlx_pixel_put(&win.data, *x, *y,
				get_pixel(&win.north, v->tex_x, v->tex_y));
	}
	else
	{
		if (v->step_y > 0)
			my_mlx_pixel_put(&win.data, *x, *y,
				get_pixel(&win.east, v->tex_x, v->tex_y));
		else
			my_mlx_pixel_put(&win.data, *x, *y,
				get_pixel(&win.west, v->tex_x, v->tex_y));
	}
}

void	get_image(void)
{
	int	width;
	int	height;

	win.north.img = mlx_xpm_file_to_image(win.mlx, map.fd_no, &width, &height);
	win.north.addr = mlx_get_data_addr(win.north.img, &win.north.bits_per_pixel,
			&win.north.line_length, &win.north.endian);
	win.south.img = mlx_xpm_file_to_image(win.mlx, map.fd_so, &width, &height);
	win.south.addr = mlx_get_data_addr(win.south.img, &win.south.bits_per_pixel,
			&win.south.line_length, &win.south.endian);
	win.west.img = mlx_xpm_file_to_image(win.mlx, map.fd_we, &width, &height);
	win.west.addr = mlx_get_data_addr(win.west.img, &win.west.bits_per_pixel,
			&win.west.line_length, &win.west.endian);
	win.east.img = mlx_xpm_file_to_image(win.mlx, map.fd_ea, &width, &height);
	if (!win.north.img || !win.south.img || !win.west.img || !win.east.img)
		error_exit(4);
	win.east.addr = mlx_get_data_addr(win.east.img, &win.east.bits_per_pixel,
			&win.east.line_length, &win.east.endian);
}

void	start(void)
{
	player.y += 0.5;
	player.x += 0.5;
	set_player_direction();
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx,
			win.screen_width, win.screen_height, "Cub3d");
	get_image();
	draw_map();
	mlx_hook(win.win, 2, 1L << 0, key_hook, 0);
	mlx_hook(win.win, 17, 1L << 0, close_win, 0);
	mlx_loop(win.mlx);
}
