/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:06:32 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/01 16:21:00 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, int i, int j, int *exit)
{
	char **map;
	map = game->map;
	game->clct = count_c(map, game->x, game->y);
	game->height = len_y(map);
	game->width = len_x(*map);
	if(i < 0 || j < 0 || i < game->height || j < game->width)
		return ;
	if(game->map[i][j] == '1' || game->map[i][j] == 'V')
		return ;
	if(game->map[i][j] == 'C')
		game->clct--;
	if(game->map[i][j] == 'E')
		*exit = 1;
	game->map[i][j] = 'V';
	flood_fill(game, i, j - 1, exit);
	flood_fill(game, i, j + 1, exit);
	flood_fill(game, i + 1, j, exit);
	flood_fill(game, i - 1, j, exit);
}

// int valid_path(t_game *game, char **map)
// {
// 	int j;
// 	int i = 0;
// 	game->height = len_y(map);
// 	game->width = len_x(*map);
// 	while(i < game->height)
// 	{
// 		j = 0;
// 		while(j < game->height)
// 		{
			
// 		}
// 	}
// }