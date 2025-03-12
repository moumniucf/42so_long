/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:16:27 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/12 13:51:09 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_p(t_game *game, int x, int y)
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
				you_win(game, i + x, j + y);
				if (game->map[i + x][j + y] != '1'
					&& game->map[i + x][j + y] != 'E')
				{
					game->map[i + x][j + y] = 'P';
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
