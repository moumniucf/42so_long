/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:50:02 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/04 16:14:56 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void aplly_images(t_game *game)
{
	int x;
	int y;
	game->img[0] = mlx_xpm_file_to_image(game->mlx, "fr1.xpm", &x, &y);
	game->img[1] = mlx_xpm_file_to_image(game->mlx, "fr2.xpm", &x, &y);
	game->img[2] = mlx_xpm_file_to_image(game->mlx, "fr3.xpm", &x, &y);
	game->img[3] = mlx_xpm_file_to_image(game->mlx, "fr4.xpm", &x, &y);
}
int animation(t_game *game, int i, int j)
{
	static int frame_count = 0;
	(void)i;
	(void)j;
	if (frame_count % (10 * count_c(game->map, game->width, game->height)) == 0)
	{
		game->fr = (game->fr + 1) % 4;
	}
	frame_count++;
	aplly_images(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img[game->fr], j * 32, i * 32);
	return (0);
}

int all_animations(t_game *game)
{
	int i = 0;
	while (game->map[i])
	{
		int j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
			{
				animation(game, i, j);
			}
			j++;
		}
		i++;
	}
	return (0);
}
