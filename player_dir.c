/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:58:08 by lukarape          #+#    #+#             */
/*   Updated: 2022/02/15 20:00:17 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	set_player_direction_two(void)
{
	if (player.dir_symb == 'W')
	{
		player.dir_y = 0;
		player.dir_x = -1;
		player.plane_y = -0.66;
		player.plane_x = 0;
	}
	else if (player.dir_symb == 'E')
	{
		player.dir_y = 0;
		player.dir_x = 1;
		player.plane_y = 0.66;
		player.plane_x = 0;
	}
}

void	set_player_direction(void)
{
	if (player.dir_symb == 'N')
	{
		player.dir_y = -1;
		player.dir_x = 0;
		player.plane_y = 0;
		player.plane_x = 0.66;
	}
	else if (player.dir_symb == 'S')
	{
		player.dir_y = 1;
		player.dir_x = 0;
		player.plane_y = 0;
		player.plane_x = -0.66;
	}
	else
		set_player_direction_two();
}
