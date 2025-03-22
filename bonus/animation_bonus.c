/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:50:02 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/22 14:47:49 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	aplly_images(t_game *game)
{
	int	x;
	int	y;

	game->img[0] = mlx_xpm_file_to_image(game->mlx, "./textures/fr1.xpm",
			&x, &y);
	game->img[1] = mlx_xpm_file_to_image(game->mlx, "./textures/fr2.xpm",
			&x, &y);
	game->img[2] = mlx_xpm_file_to_image(game->mlx, "./textures/fr3.xpm",
			&x, &y);
	game->img[3] = mlx_xpm_file_to_image(game->mlx, "./textures/fr4.xpm",
			&x, &y);
	if (!game->img[0] || !game->img[1] || !game->img[2] || !game->img[3])
		exit(1);
}

int	animation(t_game *game)
{
	static int	frame_count = 0;

	if (frame_count % 25 == 0)
	{
		game->fr = (game->fr + 1) % 4;
	}
	frame_count++;
	aplly_images(game);
	return (0);
}

int	all_animations(t_game *game)
{
	int	i;
	int	j;

	animation(game);
	move_enemy(game);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->img[game->fr], j * 32, i * 32);
			}
			j++;
		}
		i++;
	}
	return (0);
}
