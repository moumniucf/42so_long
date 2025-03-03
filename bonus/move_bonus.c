/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:59:23 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/03 13:33:34 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int move_rig(int keycode, t_game *game)
{
	game->clct = count_c(game->map, game->width, game->height);
	if (keycode == KEY_RIG || keycode == KEY_D)
	{
		int i = 0;
		int j;
		char mvmn;
		game->height = len_x(game->map[0]);
		game->width = len_y(game->map);
		char *n;
		while(i < game->width)
		{	
			j = 0;		
			while(j < game->height)
			{
				if (game->map[i][j] == 'P')
				{
					if(game->map[i][j + 1] == 'E' && game->clct == 0)
					{
						ft_printf ("\e[1;34m Game Over\e[0m\n");
						exit(0);
					}
					if(game->map[i][j + 1] == 'H')
					{
						ft_printf("\x1b[31mU Lose\n\x1b[0m");
						exit(1);
					}
					if (game->map[i][j + 1] != '1' && game->map[i][j + 1] != 'E')
					{
						game->map[i][j + 1] = 'P';
						game->map[i][j] = '0';
						game->clct--;
						game->mvmt++;
						mvmn = game->mvmt;
						mlx_clear_window(game->mlx, game->win);
						apply_map(game->mlx, game->win, 32, 32, game->map, game);
						n = ft_itoa(game->mvmt);
						mlx_string_put(game->mlx, game->win, 0, 5, 0xFFFFFF, " Moves:");
						mlx_string_put(game->mlx, game->win, 70, 5, 0xFFFFFF, n);
						break;
					}
				}
				j++;
			}
			i++;
		}
	}
	return (0);
}

int move_lef(int keycode, t_game *game)
{
	game->clct = count_c(game->map, game->width, game->height);
	if(keycode == KEY_LEF || keycode == KEY_A)
	{
		int i = 0;
		int j;
		game->height = len_x(game->map[0]);
		game->width = len_y(game->map);
		char *n;
		while(i < game->width)
		{
			j = 0;
			while(j < game->height)
			{
				if(game->map[i][j] == 'P')
				{
					if(game->map[i][j - 1] == 'E' && game->clct == 0)
					{
						ft_printf ("\e[1;34m Game Over\e[0m\n");
						exit(0);
					}
					if(game->map[i][j - 1] == 'H')
					{
						ft_printf("\x1b[31mU Lose\n\x1b[0m");
						exit(1);
					}
					if(game->map[i][j - 1] != '1' && game->map[i][j - 1] != 'E')
					{
						game->map[i][j - 1] = 'P';
						game->map[i][j] = '0';
						game->clct--;
						game->mvmt++;
						mlx_clear_window(game->mlx, game->win);
						apply_map(game->mlx, game->win, 32, 32, game->map, game);
						n = ft_itoa(game->mvmt);
						mlx_string_put(game->mlx, game->win, 0, 5, 0xFFFFFF, " Moves:");
						mlx_string_put(game->mlx, game->win, 70, 5, 0xFFFFFF, n);
						break;
					}
				}
				j++;
			}
			i++;
		}
	}
	return(0);
}

int move_up(int keycode, t_game *game)
{
	game->clct = count_c(game->map, game->width, game->height);
	if(keycode == KEY_W || keycode == KEY_UP)
	{
		int i = 0;
		int j;
		game->height = len_x(game->map[0]);
		game->width = len_y(game->map);
		char *n;
		while(i < game->width)
		{
			j = 0;
			while(j < game->height)
			{
				if(game->map[i][j] == 'P')
				{
					if(game->map[i - 1][j] == 'E' && game->clct == 0)
					{
						ft_printf ("\e[1;34m Game Over\e[0m\n");
						exit(0);
					}
					if(game->map[i - 1][j] == 'H')
					{
						ft_printf("\x1b[31mU Lose\n\x1b[0m");
						exit(1);
					}
					if(game->map[i - 1][j] != '1' && game->map[i - 1][j] != 'E')
					{
						game->map[i - 1][j] = 'P';
						game->map[i][j] = '0';
						game->clct--;
						game->mvmt++;
						mlx_clear_window(game->mlx, game->win);
						apply_map(game->mlx, game->win, 32, 32, game->map, game);
						n = ft_itoa(game->mvmt);
						mlx_string_put(game->mlx, game->win, 0, 5, 0xFFFFFF, " Moves:");
						mlx_string_put(game->mlx, game->win, 70, 5, 0xFFFFFF, n);
						break;
					}
				}
				j++;
			}
			i++;
		}
	}
	return (0);
}

int move_dow(int keycode, t_game *game)
{
	game->clct = count_c(game->map, game->width, game->height);
	if(keycode == KEY_S || keycode == KEY_DOW)
	{
		int i;
		int j = 0;
		game->height = len_x(game->map[0]);
		game->width = len_y(game->map);
		char *n;
		while(j < game->height)
		{
			i = 0;
			while(i < game->width)
			{
				if(game->map[i][j] == 'P')
				{
					if(game->map[i + 1][j] == 'E' && game->clct == 0)
					{
						ft_printf ("\e[1;34mGame Over\e[0m\n");
						exit(0);
					}
					if(game->map[i + 1][j] == 'H')
					{
						ft_printf("\x1b[31mU Lose\n\x1b[0m");
						exit(1);
					}
					if(game->map[i + 1][j] != '1' && game->map[i + 1][j] != 'E')
					{
						game->map[i + 1][j] = 'P';
						game->map[i][j] = '0';
						game->clct--;
						game->mvmt++;
						mlx_clear_window(game->mlx, game->win);
						apply_map(game->mlx, game->win, 32, 32, game->map, game);
						n = ft_itoa(game->mvmt);
						mlx_string_put(game->mlx, game->win, 0, 5, 0xFFFFFF, " Moves:");
						mlx_string_put(game->mlx, game->win, 70, 5, 0xFFFFFF, n);
						break;
					}
				}
				i++;
			}
			j++;
		}
	}
	return (0);
}