/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsse2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:42:45 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/12 10:38:47 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	appcle(t_game *game)
{
	apply_map(32, 32, game);
}

void	you_win(t_game *game, int x, int y)
{
	if (game->map[x][y] == 'E' && count_c(game->map) == 0)
	{
		ft_printf("\e[1;34m Game Over\e[0m\n");
		exit(0);
	}
	if (game->map[x][y] == 'H')
	{
		ft_printf("\x1b[31mU Lose\n\x1b[0m");
		exit(1);
	}
}

void	line_map(t_game *game)
{
	game->height = len_x(*game->map);
	game->width = len_y(game->map);
}

void	invalid_m(t_game *game)
{
	if(!valid_path(game))
	{
		ft_printf("Error\n");
		exit(1);
	}
}