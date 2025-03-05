/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:06:32 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/04 13:47:51 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill(t_game *game, int i, int j, int *ex_it)
{
	char **map;
	map = game->map;
	if(i < 0 || j < 0 || i >= game->height || j >= game->width)
		return ;
	if(game->map[i][j] == '1' || game->map[i][j] == 'V')
		return ;
	if(game->map[i][j] == 'C')
		game->clct--;
	if(game->map[i][j] == 'E')
		*ex_it = 1;
	game->map[i][j] = 'V';
	flood_fill(game, i, j - 1, ex_it);
	flood_fill(game, i, j + 1, ex_it);
	flood_fill(game, i - 1, j, ex_it);
	flood_fill(game, i + 1, j, ex_it);
}

int valid_path(t_game *game)
{
    int i = 0;
    int j = 0;
    int exit_found = 0;
    flood_fill(game, i, j, &exit_found);
    return (exit_found == 1 && game->clct == 0);
}
// #include <stdio.h>
// int main() {
//     t_game *game;

//     // Define a simple map
//     char *map[] = {
//         "111111",
//         "1PCE01",
//         "100001",
//         "100001",
//         "100001",
//         "111111",
//         NULL
//     };

//     // game.map = map;

//     // Test the valid_path function
//     if (valid_path(game)) {
//         printf("Valid path exists and all collectibles were collected!\n");
//     } else {
//         printf("No valid path or some collectibles are missing.\n");
//     }

//     return 0;
// }
