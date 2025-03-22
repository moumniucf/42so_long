/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 10:51:22 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/22 13:02:24 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_enemy(t_game *game)
{
	int			i;
	int			j;
	static int	d = 1;
	static int	m = 0;
	int			n_j;

	if (m % 10 == 0)
	{
		i = 0;
		while (i < game->height)
		{
			j = 0;
			while (j < game->width)
			{
				if (game->map[i][j] == 'H')
				{
					n_j = j + d;
					if (n_j >= 0 && n_j < game->width && game->map[i][n_j] == '0')
					{
						game->map[i][n_j] = 'H';
						game->map[i][j] = '0';
					}
					else if(n_j >= 0 && n_j < game->width && game->map[i][n_j] == '1')
					{
						d *= -1;
						n_j = j + d;
						game->map[i][n_j] = 'H';
						game->map[i][j] = '0';
					}
				}
				j++;
			}
			i++;
		}
	}
	m++;
	apply_map(32, 32, game);
	return (0);
}
