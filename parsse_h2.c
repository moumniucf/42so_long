/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsse_h2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:37:43 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/23 14:22:27 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

void	find_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				game->p_x = j;
				game->p_y = i;
			}
			i++;
		}
		j++;
	}
}

void	inva_lid(t_game *game)
{
	if (!valid_path(game))
	{
		ft_printf("Error path\n");
		free_map(game->map);
		free(game);
		exit(1);
	}
}
