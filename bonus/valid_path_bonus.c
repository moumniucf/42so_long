/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:35:28 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/22 14:56:23 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_pl(t_game *game)
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
				game->px = j;
				game->py = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(char **map_c, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (map_c[y][x] == 'E')
		game->ex_it = 1;
	if (map_c[y][x] == 'C')
		game->clct--;
	if (map_c[y][x] == '1' || map_c[y][x] == 'V' || map_c[y][x] == 'E')
		return ;
	map_c[y][x] = 'V';
	flood_fill(map_c, x + 1, y, game);
	flood_fill(map_c, x - 1, y, game);
	flood_fill(map_c, x, y + 1, game);
	flood_fill(map_c, x, y - 1, game);
}

int	valid_path(t_game *game)
{
	int		res;
	int		i;
	char	**map_c;

	game->height = len_y(game->map);
	game->width = len_x(game->map[0]);
	game->clct = count_c(game->map);
	find_pl(game);
	map_c = malloc(sizeof(char *) * (game->height + 1));
	if (!map_c)
		return (0);
	i = 0;
	while (i < game->height)
	{
		map_c[i] = ft_strdup(game->map[i]);
		i++;
	}
	map_c[i] = NULL;
	flood_fill(map_c, game->px, game->py, game);
	res = (game->clct == 0 && game->ex_it == 1);
	free_map(map_c);
	return (res);
}
