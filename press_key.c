/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:29:00 by youmoumn          #+#    #+#             */
/*   Updated: 2025/02/25 10:30:40 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int prees_esc(int keycode, t_game *game)
{
	if(keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}

int	press_x(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int count_c(char **map, int x, int y)
{
	int i;
	int j;
	int c = 0;
	i = 0;
	while(i < x)
	{
		j = 0;
		while(j < y)
		{
			if(map[i][j] == 'C')
			{
				c++;
			}
			j++;
		}
		i++;
	}
	return (c);
}
