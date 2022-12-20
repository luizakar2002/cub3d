/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:58:17 by lukarape          #+#    #+#             */
/*   Updated: 2022/02/15 20:00:25 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_vars(t_vars *v, int *x)
{
	v->camera_x = 2 * *x / (double)win.screen_width - 1;
	v->ray_dir_x = player.dir_y + player.plane_y * v->camera_x;
	v->ray_dir_y = player.dir_x + player.plane_x * v->camera_x;
	v->map_x = (int)player.y;
	v->map_y = (int)player.x;
	v->delta_dist_x = sqrt(1 + (v->ray_dir_y * v->ray_dir_y)
			/ (v->ray_dir_x * v->ray_dir_x));
	v->delta_dist_y = sqrt(1 + (v->ray_dir_x * v->ray_dir_x)
			/ (v->ray_dir_y * v->ray_dir_y));
	v->hit = 0;
}

void	step_calculation(t_vars *v)
{
	if (v->ray_dir_x < 0)
	{
		v->step_x = -1;
		v->side_dist_x = (player.y - v->map_x) * v->delta_dist_x;
	}
	else
	{
		v->step_x = 1;
		v->side_dist_x = (v->map_x + 1.0 - player.y) * v->delta_dist_x;
	}
	if (v->ray_dir_y < 0)
	{
		v->step_y = -1;
		v->side_dist_y = (player.x - v->map_y) * v->delta_dist_y;
	}
	else
	{
		v->step_y = 1;
		v->side_dist_y = (v->map_y + 1.0 - player.x) * v->delta_dist_y;
	}
}

void	perform_dda(t_vars *v)
{
	if (v->side_dist_x < v->side_dist_y)
	{
		v->side_dist_x += v->delta_dist_x;
		v->map_x += v->step_x;
		v->side = 0;
	}
	else
	{
		v->side_dist_y += v->delta_dist_y;
		v->map_y += v->step_y;
		v->side = 1;
	}
	if (map.map[v->map_x][v->map_y] == '1')
		v->hit = 1;
}

void	distance(t_vars *v)
{
	if (v->side == 0)
		v->perp_wall_dist = (v->map_x - player.y
				+ (1 - v->step_x) / 2) / v->ray_dir_x;
	else
		v->perp_wall_dist = (v->map_y - player.x
				+ (1 - v->step_y) / 2) / v->ray_dir_y;
	v->line_height = (int)(win.screen_width / v->perp_wall_dist);
	v->draw_start = -v->line_height / 2 + win.screen_width / 2;
	if (v->draw_start < 0)
		v->draw_start = 0;
	v->draw_end = v->line_height / 2 + win.screen_width / 2;
	if (v->draw_end >= win.screen_width)
		v->draw_end = win.screen_width - 1;
	if (v->side == 0)
		v->wall_x = player.x + v->perp_wall_dist * v->ray_dir_y;
	else
		v->wall_x = player.y + v->perp_wall_dist * v->ray_dir_x;
	v->wall_x -= floor((v->wall_x));
	v->tex_x = (int)(v->wall_x * (double)(TEXSIDE));
	if (v->side == 0 && v->ray_dir_x > 0)
		v->tex_x = TEXSIDE - v->tex_x - 1;
	if (v->side == 1 && v->ray_dir_y < 0)
		v->tex_x = TEXSIDE - v->tex_x - 1;
}

void	draw_map(void)
{
	t_vars	v;
	int		x;
	int		y;

	win.data.img = mlx_new_image(win.mlx,
			win.screen_width, win.screen_height);
	win.data.addr = mlx_get_data_addr(win.data.img,
			&win.data.bits_per_pixel, &win.data.line_length,
			&win.data.endian);
	x = -1;
	while (++x < win.screen_width)
	{
		init_vars(&v, &x);
		step_calculation(&v);
		while (v.hit == 0)
			perform_dda(&v);
		distance(&v);
		v.step = 1.0 * TEXSIDE / v.line_height;
		v.tex_pos = (v.draw_start - win.screen_width
				/ 2 + v.line_height / 2) * v.step;
		y = -1;
		while (++y < win.screen_height)
			fill_colors(&v, &x, &y);
	}
	mlx_put_image_to_window(win.mlx, win.win, win.data.img, 0, 0);
}
