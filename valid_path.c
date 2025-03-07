/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:06:32 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/07 16:50:59 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
int len_x(char *map)
{
	if(!map)
		exit(0);
	int x = 0;
	while(map[x] && map[x] != '\n')
	{
		x++;
	}
	return(x);
}

int len_y(char **map)
{
	if(!map)
		return (0);
	int y = 0;
	while(map[y])
	{
		y++;
	}
	return (y);
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

void	find_pl(t_game *game)
{
	int i;
	int j;
	i = 0;
	while(i < game->height)
	{
		j = 0;
		while(j < game->width)
		{
			if(game->map[i][j] == 'P')
			{
				game->p_x = j;
				game->p_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
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

    int cl;
	cl = count_c(game->map);
    int ext;
	find_pl(game);
    char **map_c = malloc(sizeof(char *) * (game->height + 1));
    int i = 0;
    while (i < game->height)
    {
        map_c[i] = ft_strdup(game->map[i]);
        i++;
    }
    map_c[i] = NULL;
    flood_fill(map_c, game->p_x, game->p_y, game, &cl, &ext);
    return (cl == 0 && ext == 1);
}

int main()
{
    t_game *game = malloc(sizeof(t_game));


    char *map[] = {
    "1111111111111",
    "1000001000001",
    "10P00000C0E01",
    "1000C00100001",
    "10000C0000001",
    "1000000000C01",
    "1111111101111",
    "1000CC0000001",
    "1000000C10101",
    "10000C0000001",
    "100C000000001",
    "1000000C00001",
    "1111111111111",
    NULL
};

    game->map = map;

    if (valid_path(game))
        printf("Valid path exists and all collectibles were collected!\n");
    else
        printf("No valid path or some collectibles are missing.\n");

    free(game);
    return 0;
}

