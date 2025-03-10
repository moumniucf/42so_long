/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:59:23 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/08 13:58:03 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_p(t_game *game, int x, int y)
{
	int	i;
	int	j;
	int	nx;
	int	ny;
	char *n;

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
				if (game->map[nx][ny] == 'H')
				{
					ft_printf("\x1b[31mU Lose\n\x1b[0m");
					exit(1);
				}
				if (game->map[nx][ny] == 'E' && count_c(game->map) == 0)
				{
					ft_printf("\e[1;34m Game Over\e[0m\n");
					exit(0);
				}
				if (game->map[nx][ny] != '1' && game->map[nx][ny] != 'E')
				{
					game->map[nx][ny] = 'P';
					game->map[i][j] = '0';
					game->mvmt++;
					n = ft_itoa(game->mvmt);
					mlx_clear_window(game->mlx, game->win);
					apply_map(game->mlx, game->win, 32, 32, game->map, game);
					mlx_string_put(game->mlx, game->win, 0, 10, 0xFFFFFF, "Moves:");
					mlx_string_put(game->mlx, game->win, 70, 10, 0xFFFFFF, n);
				}
				return ;
			}
			j++;
		}
		i++;
	}
}
