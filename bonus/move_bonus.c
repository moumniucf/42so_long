/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:59:23 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/23 14:37:37 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	help_mov(t_game *game, int x, int y)
{
	int		i;
	int		j;

	find_pl(game);
	j = game->px;
	i = game->py;
	you_win(game, i + x, j + y);
	if (game->map[i + x][j + y] != '1' && game->map[i + x][j + y] != 'E')
	{
		game->map[i + x][j + y] = 'P';
		game->map[i][j] = '0';
		game->mvmt++;
		apply_map(32, 32, game);
	}
}

void	move_p(t_game *game, int x, int y)
{
	find_pl(game);
	help_mov(game, x, y);
}

void	help_fr(t_game *game)
{
	free_map(game->map);
	free(game->mlx);
	free(game->win);
	free(game);
	exit(1);
}
