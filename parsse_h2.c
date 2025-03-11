/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsse_h2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:37:43 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/11 13:26:58 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	appcle(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	apply_map(32, 32, game->map, game);
}

void	you_win(t_game *game, int x, int y)
{
	if (game->map[x][y] == 'E' && count_c(game->map) == 0)
	{
		ft_printf("\e[1;34m Game Over\e[0m\n");
		exit(0);
	}
}
