/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:58:54 by lukarape          #+#    #+#             */
/*   Updated: 2022/02/15 20:00:56 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_count(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s != '\0')
	{
		if (*s == c)
			cnt++;
		s++;
	}
	return (cnt);
}

void	fill_map(char *str, int line_num)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		map.map[line_num][i] = str[i];
	while (i < map.width)
	{
		map.map[line_num][i] = ' ';
		i++;
	}
	map.map[line_num][i] = '\0';
}

int	check_validity(char c)
{
	return (c != ' ' && c != '1' && c != '0' && c != 'N' && c != 'W'
		&& c != 'E' && c != 'S');
}

int	open_fd(char *f)
{
	int	fd;

	fd = open(f, O_RDONLY);
	if (fd == -1)
		error_exit(8);
	return (fd);
}
