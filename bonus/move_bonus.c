/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:59:23 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/12 15:10:57 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_p(t_game *game, int x, int y)
{
	int		i;
	int		j;
	int		nx;
	int		ny;
	char	*n;

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
					n = ft_itoa(game->mvmt);
					apply_map(32, 32, game);
					mlx_string_put(game->mlx, game->win, 0, 10, WH, "Moves:");
					mlx_string_put(game->mlx, game->win, 70, 10, WH, n);
					free(n);
				}
				return ;
			}
			j++;
		}
		i++;
	}
}
