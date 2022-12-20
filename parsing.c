/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:57:24 by lukarape          #+#    #+#             */
/*   Updated: 2022/02/15 19:59:48 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_format(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (str[len - 1] == 'b' && str[len - 2] == 'u'
		&& str[len - 3] == 'c' && str[len - 4] == '.')
		return (0);
	return (1);
}

int	parse_elements(char *str)
{
	char	**spl;

	spl = ft_split(str, ' ');
	if (spl[2] != NULL)
	{
		free_matrix(spl);
		error_exit(6);
	}
	if (parse_colors(spl))
	{
		free_matrix(spl);
		return (1);
	}
	return (0);
}

int	parse_colors_1(char **spl)
{
	if (spl[0][0] == 'N' && spl[0][1] == 'O' && spl[0][2] == '\0')
		map.fd_no = ft_strdup(spl[1]);
	else if (spl[0][0] == 'S' && spl[0][1] == 'O' && spl[0][2] == '\0')
		map.fd_so = ft_strdup(spl[1]);
	else if (spl[0][0] == 'W' && spl[0][1] == 'E' && spl[0][2] == '\0')
		map.fd_we = ft_strdup(spl[1]);
	else if (spl[0][0] == 'E' && spl[0][1] == 'A' && spl[0][2] == '\0')
		map.fd_ea = ft_strdup(spl[1]);
	else if (spl[0][0] == 'F' && spl[0][1] == '\0')
	{
		if (map.f >= 1)
			error_exit(3);
		map.floor = parse_color(spl);
		map.f++;
	}
	else if (spl[0][0] == 'C' && spl[0][1] == '\0')
	{
		if (map.c >= 1)
			error_exit(3);
		map.ceiling = parse_color(spl);
		map.c++;
	}
	else
		return (1);
	return (0);
}

int	parse_colors(char **spl)
{
	if (parse_colors_1(spl))
		return (1);
	free_matrix(spl);
	map.count = 6;
	return (0);
}
