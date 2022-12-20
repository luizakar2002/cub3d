/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:35:24 by lukarape          #+#    #+#             */
/*   Updated: 2022/02/15 19:59:04 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(int code)
{
	if (code == 1)
		printf("Error\nMap is not valid!\n");
	else if (code == 2)
		printf("Error\nWrong file extension format!\n");
	else if (code == 3)
		printf("Error\nElements are not valid!\n");
	else if (code == 4)
		printf("Error\nInvalid path of textures!\n");
	else if (code == 5)
		printf("Error\nInvalid RGB format!\n");
	else if (code == 6)
		printf("Error\nWrong element format!\n");
	else if (code == 7)
		printf("Error\nCouldn't close the file!\n");
	else if (code == 8)
		printf("Error\nNot able to open the file!\n");
	else if (code == 9)
		printf("Error\nNo memory left!\n");
	exit(code);
}
