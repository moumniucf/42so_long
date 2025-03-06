/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:06:32 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/06 12:57:53 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <string.h>


// int len_x(char *map)
// {
// 	if(!map)
// 		exit(0);
// 	int x = 0;
// 	while(map[x] && map[x] != '\n')
// 	{
// 		x++;
// 	}
// 	return(x);
// }

// int len_y(char **map)
// {
// 	if(!map)
// 		return (0);
// 	int y = 0;
// 	while(map[y])
// 	{
// 		y++;
// 	}
// 	return (y);
// }

void flood_fill(char **map_c, int x, int y, t_game *game, int *cl, int *exit)
{
    if (x < 0 || y < 0 || x >= game->width || y >= game->height)
        return;
    if (map_c[y][x] == 'E')
        *exit = 1;
    if (map_c[y][x] == 'C')
        (*cl)++;
    if (map_c[y][x] == '1' || map_c[y][x] == 'V')
        return;
    map_c[y][x] = 'V';
    flood_fill(map_c, x + 1, y, game, cl, exit);
    flood_fill(map_c, x - 1, y, game, cl, exit);
    flood_fill(map_c, x, y + 1, game, cl, exit);
    flood_fill(map_c, x, y - 1, game, cl, exit);
}

int valid_path(t_game *game)
{
    game->height = len_y(game->map);
    game->width = len_x(game->map[0]);

    int cl = 0;
    int ext = 0;
	// char **map_c;
	// game->map = map_c;
    char **map_c = malloc(sizeof(char *) * (game->height + 1));
    int i = 0;
    while (i < game->height)
    {
        map_c[i] = ft_strdup(game->map[i]);
        i++;
    }
    map_c[i] = NULL;
    flood_fill(map_c, game->P_X, game->P_Y, game, &cl, &ext);
    return (cl > 0 && ext);
}

// int main()
// {
//     t_game *game = malloc(sizeof(t_game));
//     if (!game)
//         return 1;
// 	// t_game *game;

//     char *map[] = {
//     "1111111111111",
//     "1000001000001",
//     "10P00000C0001",
//     "1000C00100001",
//     "10000C0000001",
//     "1000000000C01",
//     "1111110111111",
//     "1000CC0000001",
//     "1000000C10101",
//     "10000C0000001",
//     "100C00000E001",
//     "1000000C00001",
//     "1111111111111",
//     NULL
// };

//     game->map = map;
//     game->P_X = 1;
//     game->P_Y = 1;

//     if (valid_path(game))
//         printf("Valid path exists and all collectibles were collected!\n");
//     else
//         printf("No valid path or some collectibles are missing.\n");

//     free(game);
//     return 0;
// }

