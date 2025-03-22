/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tahadev <tahadev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:29:00 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/22 21:50:06 by tahadev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	prees_esc(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}

int	press_x(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game);
	exit(0);
	return (0);
}

int	count_c(char **map)
{
	int	i;
	int	j;
	int	c;

	if (!map)
		return (0);
	c = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				c++;
			}
			j++;
		}
		i++;
	}
	return (c);
}

int	count_p(char **map)
{
	int	i;
	int	j;
	int	c;

	if (!map)
		return (0);
	c = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				c++;
			}
			j++;
		}
		i++;
	}
	return (c);
}

int	count_e(char **map)
{
	int	i;
	int	j;
	int	c;

	if (!map)
		return (0);
	c = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				c++;
			}
			j++;
		}
		i++;
	}
	return (c);
}
