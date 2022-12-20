/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:58:46 by lukarape          #+#    #+#             */
/*   Updated: 2022/02/15 20:00:48 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	nb;

	sign = 1;
	nb = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (nb * sign);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	unsigned int	idx;
	char			*modified_s;

	modified_s = malloc(sizeof(char) * (len + 1));
	if (!s || !modified_s)
		return (NULL);
	idx = 0;
	while (start < ft_strlen((char *)s) && s[start + idx] && idx < len)
	{
		modified_s[idx] = s[start + idx];
		idx++;
	}
	modified_s[idx] = '\0';
	return (modified_s);
}

int	check_zero(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (*str != ' ' && *str != '1' && *str != '\0')
			return (1);
		str++;
	}
	return (0);
}

int	check_neighbours(int i, int j)
{
	if (i - 1 >= 0 && i - 1 < map.height)
		if (map.map[i - 1][j] != ' ' && map.map[i - 1][j] != '1'
			&& map.map[i - 1][j] != '\0')
			return (1);
	if (i + 1 >= 0 && i + 1 < map.height)
		if (map.map[i + 1][j] != ' ' && map.map[i + 1][j] != '1'
			&& map.map[i + 1][j] != '\0')
			return (1);
	if (j - 1 >= 0 && j - 1 < map.width)
		if (map.map[i][j - 1] != ' ' && map.map[i][j - 1] != '1'
			&& map.map[i + 1][j] != '\0')
			return (1);
	if (j + 1 >= 0 && j + 1 < map.width)
		if (map.map[i][j + 1] != ' ' && map.map[i][j + 1] != '1'
			&& map.map[i + 1][j] != '\0')
			return (1);
	return (0);
}

char	*ft_strdup(char *str)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
