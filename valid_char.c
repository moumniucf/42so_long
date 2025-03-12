/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:30:13 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/12 14:47:58 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_chars2(char c)
{
	int		i;
	char	*s;

	s = "01PEC";
	i = 0;
	while (i < 5)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	app_3(t_game *game, int x, int y)
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
			nx = i + x;
			ny = j + y;
			if (game->map[nx][ny] != '1' && game->map[nx][ny] != 'E')
			{
				game->map[nx][ny] = 'P';
				game->map[i][j] = '0';
				game->mvmt++;
				ft_printf("Moves: %d\n", game->mvmt);
			}
		}
	}
}
