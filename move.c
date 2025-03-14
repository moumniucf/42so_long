/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:16:27 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/14 14:49:13 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	help_mov(t_game *game, int x, int y)
{
	int		i;
	int		j;

	find_pl(game);
	j = game->p_x;
	i = game->p_y;
	you_win(game, i + x, j + y);
	if (game->map[i + x][j + y] != '1' && game->map[i + x][j + y] != 'E')
	{
		game->map[i + x][j + y] = 'P';
		game->map[i][j] = '0';
		ft_printf("Moves: %d\n", game->mvmt++);
	}
	apply_map(32, 32, game);
}

void	move_p(t_game *game, int x, int y)
{
	find_pl(game);
	help_mov(game, x, y);
}
