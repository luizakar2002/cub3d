/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:58:38 by lukarape          #+#    #+#             */
/*   Updated: 2022/02/15 20:00:39 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_next_line(int fd, char **line)
{
	int		i;
	int		n;
	char	c;
	char	*str;

	i = 0;
	if (fd < 0)
		return (-1);
	str = (char *)malloc(1000 + 1);
	if (!str)
		return (-1);
	n = read(fd, &c, 1);
	while (n && c != '\n' && c != '\0')
	{
		str[i++] = c;
		n = read(fd, &c, 1);
	}
	str[i] = '\0';
	*line = str;
	if (ft_strlen(*line) != 0 && n == 0)
		map.gnl = 1;
	return (n);
}

int	my_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (0);
	return (1);
}

int	empty_line(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (is_space(*str))
			return (1);
		str++;
	}
	return (0);
}
