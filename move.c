/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:16:27 by youmoumn          #+#    #+#             */
/*   Updated: 2025/02/24 17:21:09 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int move_rig(int keycode, t_game *game)
{
	ft_printf("keyRD=>[%d]\n", keycode);
	ft_printf("kawnona motassadirin yo2limohom fi madrid  ");
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
					ft_printf("player at [%d] [%d]", i, j);
					if (game->map[i][j + 1] != '1')
					{
						game->map[i][j + 1] = 'P';
						game->map[i][j] = '0';
						break;
					}
				}
				if(game->map[i][j] == 'E')
				{
					exit(0);
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
	ft_printf("keyLA=>[%d]\n", keycode);
	ft_printf("kawnona motassadirin yo2limohom fi madrid  ");
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
					if(game->map[i][j - 1] != '1')
					{
						game->map[i][j - 1] = 'P';
						game->map[i][j] = '0';
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
	ft_printf("keyWU=>[%d]\n", keycode);
	ft_printf("kawnona motassadirin yo2limohom fi madrid");
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
					if(game->map[i][j + 1] != '1')
					{
						game->map[i][j] = '0';
						game->map[i][j + 1] = 'P';
						game->map[i][j - 1] = 'P';
						game->map[i][j] = '0';
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