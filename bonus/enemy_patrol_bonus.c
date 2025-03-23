/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 10:51:22 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/23 14:30:41 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_enemy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'H')
			{
				game->enmx = i;
				game->enmy = j;
			}
			j++;
		}
		i++;
	}
}

void	move_help(t_game *game)
{
	game->n = ft_itoa(game->mvmt);
	mlx_string_put(game->mlx, game->win, 0, 10, WH, "Moves:");
	mlx_string_put(game->mlx, game->win, 70, 10, WH, game->n);
	free(game->n);
}

void	enemy_lose(t_game *game, int i, int j)
{
	if (j >= 0 && j < game->width
		&& game->map[i][j] == 'P')
	{
		ft_printf("\x1b[31mU Lose\n\x1b[0m");
		exit(1);
	}
}

void	move_en(t_game *game)
{
	int			nj;
	int			i;
	int			j;
	static int	d = 1;

	find_enemy(game);
	i = game->enmx ;
	j = game->enmy ;
	nj = j + d;
	enemy_lose(game, i, nj);
	if (nj >= 0 && nj < game->width
		&& game->map[i][nj] == '0')
	{
		game->map[i][nj] = 'H';
		game->map[i][j] = '0';
	}
	else if (game->map[i][nj] == '1' || game->map[i][nj] == 'C')
	{
		d *= -1;
		nj = j + d;
		game->map[i][nj] = 'H';
		game->map[i][j] = '0';
	}
}

int	move_enemy(t_game *game)
{
	static int	m = 0;

	if (m % 15 == 0)
	{
		move_en(game);
	}
	apply_map(32, 32, game);
	m++;
	move_help(game);
	return (0);
}
