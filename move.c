/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:16:27 by youmoumn          #+#    #+#             */
/*   Updated: 2025/02/25 11:04:10 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int move_rig(int keycode, t_game *game)
{
	t_game game2;
	game2.clct = count_c(game->map, game->width, game->height);
	if (keycode == KEY_RIG || keycode == KEY_D)
	{
		int i = 0;
		int j;
		game->height = len_x(game->map[0]);
		game->width = len_y(game->map);
		while(i < game->width)
		{	
			j = 0;		
			while(j < game->height)
			{
				if (game->map[i][j] == 'P')
				{
					if(game->map[i][j + 1] == 'E' && game2.clct == 0)
					{
						printf("3aaaaa\n");
						exit(0);
					}
					if (game->map[i][j + 1] != '1' && game->map[i][j + 1] != 'E')
					{
						game->map[i][j + 1] = 'P';
						game->map[i][j] = '0';
						game2.clct--;
						game->mvmt++;
						ft_printf("Moves: %d - Colect : %d\n", game->mvmt, game2.clct);
						break;
					}
				}
				j++;
			}
			i++;
		}
		mlx_clear_window(game->mlx, game->win);
		apply_map(game->mlx, game->win, 32, 32, game->map, game);
	}
	return (0);
}

int move_lef(int keycode, t_game *game)
{
	t_game game2;
	game2.clct = count_c(game->map, game->width, game->height);
	if(keycode == KEY_LEF || keycode == KEY_A)
	{
		int i = 0;
		int j;
		game->height = len_x(game->map[0]);
		game->width = len_y(game->map);
		while(i < game->width)
		{
			j = 0;
			while(j < game->height)
			{
				if(game->map[i][j] == 'P')
				{
					if(game->map[i][j - 1] == 'E' && game2.clct == 0)
					{
						printf("3aaaaa\n");
						exit(0);
					}
					if(game->map[i][j - 1] != '1' && game->map[i][j - 1] != 'E')
					{
						game->map[i][j - 1] = 'P';
						game->map[i][j] = '0';
						game2.clct--;
						game->mvmt++;
						ft_printf("Moves: %d - Colect : %d\n", game->mvmt, game2.clct);
						break;
					}
				}
				j++;
			}
			i++;
		}
		mlx_clear_window(game->mlx, game->win);
		apply_map(game->mlx, game->win, 32, 32, game->map, game);
	}
	return(0);
}

int move_up(int keycode, t_game *game)
{
	t_game game2;
	game2.clct = count_c(game->map, game->width, game->height);
	if(keycode == KEY_W || keycode == KEY_UP)
	{
		int i = 0;
		int j;
		game->height = len_x(game->map[0]);
		game->width = len_y(game->map);
		while(i < game->width)
		{
			j = 0;
			while(j < game->height)
			{
				if(game->map[i][j] == 'P')
				{
					if(game->map[i - 1][j] == 'E' && game2.clct == 0)
					{
						printf("3aaaaa\n");
						exit(0);
					}
					if(game->map[i - 1][j] != '1' && game->map[i - 1][j] != 'E')
					{
						game->map[i - 1][j] = 'P';
						game->map[i][j] = '0';
						game2.clct--;
						game->mvmt++;
						ft_printf("Moves: %d - Colect : %d\n", game->mvmt, game2.clct);
						break;
					}
				}
				j++;
			}
			i++;
		}
		mlx_clear_window(game->mlx, game->win);
		apply_map(game->mlx, game->win, 32, 32, game->map, game);
	}
	return (0);
}

int move_dow(int keycode, t_game *game)
{
	t_game game2;
	game2.clct = count_c(game->map, game->width, game->height);
	if(keycode == KEY_S || keycode == KEY_DOW)
	{
		int i;
		int j = 0;
		game->height = len_x(game->map[0]);
		game->width = len_y(game->map);
		while(j < game->height)
		{
			i = 0;
			while(i < game->width)
			{
				if(game->map[i][j] == 'P')
				{
					if(game->map[i + 1][j] == 'E' && game2.clct == 0)
					{
						printf("3aaaaa\n");
						exit(0);
					}
					if(game->map[i + 1][j] != '1' && game->map[i + 1][j] != 'E')
					{
						game->map[i + 1][j] = 'P';
						game->map[i][j] = '0';
						game2.clct--;
						game->mvmt++;
						ft_printf("Moves: %d - Colect : %d\n", game->mvmt, game2.clct);
						break;
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