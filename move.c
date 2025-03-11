/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:16:27 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/11 14:01:12 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_p(t_game *game, int x, int y)
{
	int	i;
	int	j;
	int	nx;
	int	ny;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				nx = i + x;
				ny = j + y;
				you_win(game, nx, ny);
				if (game->map[nx][ny] != '1' && game->map[nx][ny] != 'E')
				{
					game->map[nx][ny] = 'P';
					game->map[i][j] = '0';
					game->mvmt++;
					ft_printf("Moves: %d\n", game->mvmt);
				}
				appcle(game);
				return ;
			}
			j++;
		}
		i++;
	}
}
