/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:16:27 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/06 16:23:27 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_p(int keycode, t_game *game, int x, int y)
{
	int	i;
	int	j;
	int	nx;
	int	ny;

	(void)keycode;
	game->clct = count_c(game->map);
	game->height = len_x(game->map[0]);
	game->width = len_y(game->map);
	i = 0;
	while (i < game->width)
	{
		j = 0;
		while (j < game->height)
		{
			if (game->map[i][j] == 'P')
			{
				nx = i + x;
				ny = j + y;
				if (game->map[nx][ny] == 'E' && game->clct == 0)
				{
					ft_printf ("\e[1;34m Game Over\e[0m\n");
					exit(0);
				}
				if (game->map[nx][ny] != '1' && game->map[nx][ny] != 'E')
				{
					game->map[nx][ny] = 'P';
					game->map[i][j] = '0';
					game->clct--;
					game->mvmt++;
					ft_printf("Moves : %d\n", game->mvmt);
					break ;
				}
			}
			j++;
		}
		i++;
	}
	mlx_clear_window(game->mlx, game->win);
	apply_map(game->mlx, game->win, 32, 32, game->map, game);
	return (0);
}

int	move_lef(int keycode, t_game *game)
{
	game->clct = count_c(game->map);
	if (keycode == KEY_LEF || keycode == KEY_A)
	{
		return (move_p(keycode, game, 0, -1));
	}
	return (0);
}

int	move_up(int keycode, t_game *game)
{
	game->clct = count_c(game->map);
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		return (move_p(keycode, game, -1, 0));
	}
	return (0);
}

int	move_rig(int keycode, t_game *game)
{
	game->clct = count_c(game->map);
	if (keycode == KEY_D || keycode == KEY_RIG)
	{
		return (move_p(keycode, game, 0, 1));
	}
	return (0);
}

// int	move_dow(int keycode, t_game *game)
// {
// 	game->clct = count_c(game->map);
// 	if (keycode == KEY_S || keycode == KEY_DOW)
// 	{
// 		return (move_p(keycode, game, 1, 0));
// 	}
// 	return (0);
// }
int	move_dow(int keycode, t_game *game)
{
	int	i;
	int	j;

	game->clct = count_c(game->map);
	if (keycode == KEY_S || keycode == KEY_DOW)
	{
		game->height = len_x(game->map[0]);
		game->width = len_y(game->map);
		j = 0;
		while (j < game->height)
		{
			i = 0;
			while (i < game->width)
			{
				if (game->map[i][j] == 'P')
				{
					if (game->map[i + 1][j] == 'E' && game->clct == 0)
					{
						ft_printf ("\e[1;34mGame Over\e[0m\n");
						exit(0);
					}
					if (game->map[i + 1][j] != '1' && game->map[i + 1][j] != 'E')
					{
						game->map[i + 1][j] = 'P';
						game->map[i][j] = '0';
						game->clct--;
						game->mvmt++;
						ft_printf("Moves : %d\n", game->mvmt);
						break ;
					}
				}
				i++;
			}
			j++;
		}
		mlx_clear_window(game->mlx, game->win);
		apply_map(game->mlx, game->win, 32, 32, game->map, game);
	}
	return (0);
}
