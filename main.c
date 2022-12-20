/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:37:16 by lukarape          #+#    #+#             */
/*   Updated: 2022/02/15 19:59:40 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	win.screen_width = 1280;
	win.screen_height = 1100;
	if (argc == 2)
	{
		read_file(argv[1]);
		start();
		free(map.fd_no);
		free(map.fd_so);
		free(map.fd_ea);
		free(map.fd_we);
		free_matrix(map.map);
	}
	else
	{
		printf("Wrong number of arguments!\n");
		exit(1);
	}
	return (0);
}
