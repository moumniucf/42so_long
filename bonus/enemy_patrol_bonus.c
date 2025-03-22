/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 10:51:22 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/22 14:55:18 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_enemy(t_game *game)
{
	int			i;
	int			j;
	static int	d = 1;
	static int	m = 0;
	int			nj;

	mlx_clear_window(game->mlx, game->win);
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
					nj = j + d;
					if (nj >= 0 && nj < game->width
						&& game->map[i][nj] == '0')
					{
						game->map[i][nj] = 'H';
						game->map[i][j] = '0';
					}
					else if (nj >= 0 && nj < game->width
						&& game->map[i][nj] == 'P')
					{
						ft_printf("\x1b[31mU Lose\n\x1b[0m");
						exit(1);
					}
					else if (game->map[i][nj] == '1' || game->map[i][nj] == 'C')
					{
						d *= -1;
						nj = j + d;
						game->map[i][nj] = 'H';
						game->map[i][j] = '0';
					}
					break ;
				}
				j++;
			}
			i++;
		}
	}
	apply_map(32, 32, game);
	m++;
	mlx_string_put(game->mlx, game->win, 0, 10, WH, "Moves:");
	mlx_string_put(game->mlx, game->win, 70, 10, WH, ft_itoa(game->mvmt));
	return (0);
}
