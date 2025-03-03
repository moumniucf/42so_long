/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:43:48 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/03 15:08:16 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void animation(t_game *game)
{
	int i = 0;
	int j = 0;
	static int k = 0;
	game->height = len_x(game->map[0]);
	game->width = len_y(game->map);
	while(i < game->height)
	{
		j = 0;
		while(j < game->height)
		{
			if(game->map[i][j] == 'C')
			{
				while(k < 4)
				{
					if(k == 1)
					{
						game->img[0] = mlx_xpm_file_to_image(game->mlx, "fr1.xpm", &game->width, &game->height);
					}
					if(k == 2)
					{
						game->img[0] = mlx_xpm_file_to_image(game->mlx, "fr2.xpm", &game->width, &game->height);
					}
					if(k == 3)
					{
						game->img[0] = mlx_xpm_file_to_image(game->mlx, "fr3.xpm", &game->width, &game->height);
					}
					if(k == 4)
					{
						game->img[0] = mlx_xpm_file_to_image(game->mlx, "fr4.xpm", &game->width, &game->height);
					}
					k++;
				}
			}
			j++;
		}
		i++;
	}
}
