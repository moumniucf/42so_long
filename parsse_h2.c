/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsse_h2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:37:43 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/10 15:48:48 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so2_parss(t_game *game)
{
	int	i;
	int	j;

	game->height = len_x(*game->map);
	game->width = len_y(game->map);
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (!valid_path(game))
			{
				ft_printf("Error P\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

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
