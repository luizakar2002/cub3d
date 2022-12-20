/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:57:42 by lukarape          #+#    #+#             */
/*   Updated: 2022/02/15 19:59:57 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_color(char **spl)
{
	char	**rgb;
	int		color;
	int		r;
	int		g;
	int		b;

	if (get_count(spl[1], ',') != 2)
	{
		free_matrix(spl);
		error_exit(5);
	}
	rgb = ft_split(spl[1], ',');
	if (!rgb[0] || !rgb[1] || !rgb[2])
		error_exit(5);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255
		|| b < 0 || b > 255)
		error_exit(5);
	color = my_rgb(r, g, b);
	free_matrix(rgb);
	map.count++;
	return (color);
}

void	map_malloc(void)
{
	int	i;

	i = 0;
	map.map = malloc((map.height + 1) * sizeof(char *));
	if (!map.map)
	{
		error_exit(9);
	}
	while (i < map.height)
	{
		map.map[i] = malloc((map.width + 1) * sizeof(char *));
		if (!map.map[i])
		{
			error_exit(9);
		}
		i++;
	}
}

void	read_file_1(char *str, int line_num, int fd)
{
	if (map.gnl)
	{
		if (empty_line(str))
		{
			if (parse_line(str, line_num))
				error_exit(1);
		}
	}
	if (close(fd) == -1)
		error_exit(7);
	if (map.count != 6)
		error_exit(3);
	if (parse_map())
		error_exit(3);
	free(str);
}

void	read_file(char *f)
{
	int		fd;
	int		line_num;
	char	*str;

	if (parse_format(f))
		error_exit(2);
	fd = open_fd(f);
	line_num = 0;
	while (get_next_line(fd, &str))
	{
		if (empty_line(str))
		{
			if (line_num == 5)
			{
				map_size(f);
				map_malloc();
			}
			if (parse_line(str, line_num))
				error_exit(1);
			line_num++;
		}
		free(str);
	}
	read_file_1(str, line_num, fd);
}
