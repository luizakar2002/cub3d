/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:57:52 by lukarape          #+#    #+#             */
/*   Updated: 2022/02/15 20:00:04 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map_1(int i, int j)
{
	if (check_validity(map.map[i][j]))
		error_exit(1);
	if (j == 0 || j == map.width - 1)
		if (map.map[i][j] != ' ' && map.map[i][j] != '1')
			error_exit(1);
	if (map.map[i][j] == 'N' || map.map[i][j] == 'W'
		|| map.map[i][j] == 'E' || map.map[i][j] == 'S')
	{
		player.count++;
		if (player.count == 1)
		{
			player.x = j;
			player.y = i;
			player.dir_symb = map.map[i][j];
		}
		map.map[i][j] = '0';
	}
	if (map.map[i][j] == ' ')
		if (check_neighbours(i, j))
			error_exit(1);
}

int	parse_map(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map.height)
	{
		if (i == 0 || i == map.height - 1)
			if (check_zero(map.map[i]))
				error_exit(1);
		j = -1;
		while (map.map[i][++j])
			parse_map_1(i, j);
	}
	if (player.count == 0)
		error_exit(1);
	return (0);
}

int	parse_line(char *str, int line_num)
{
	if (line_num >= 0 && line_num <= 5)
	{
		if (parse_elements(str))
			error_exit(3);
		return (0);
	}
	else if (line_num > 5)
	{
		fill_map(str, line_num - 6);
		return (0);
	}
	return (1);
}

void	map_size_1(char *str, int *flag, int *line_num)
{
	if (empty_line(str))
	{
		if (*flag)
			error_exit(1);
		if (*line_num < 6)
			(*line_num)++;
		else
		{
			map.height++;
			(*line_num)++;
			if (ft_strlen(str) > map.width)
				map.width = ft_strlen(str);
		}
	}
	else if (*line_num > 6)
		*flag = 1;
	free(str);
}

void	map_size(char *fd)
{
	int		flag;
	char	*str;
	int		f;
	int		line_num;

	f = open_fd(fd);
	line_num = 0;
	flag = 0;
	while (get_next_line(f, &str))
		map_size_1(str, &flag, &line_num);
	if (map.gnl)
	{
		map.height++;
	}
	free(str);
	if (close(f) == -1)
		error_exit(7);
}
