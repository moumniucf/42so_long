/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:14:04 by youmoumn          #+#    #+#             */
/*   Updated: 2025/02/24 13:05:08 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	leaks()
{
	system("leaks so_long");
}

int press_key(int keycode, t_game *game)
{
	(void)game;
	printf("key=>[%d]\n", keycode);
	if (keycode == 124)
	{
		int i = 0;
		int j = 0;
		while(i < 6)
		{	
			j = 0;		
			while(j < 19)
			{
				if (game->map[i][j] == 'P')
				{
					printf("player at [%d] [%d]", i, j);
					if (game->map[i][j+1] != '1')
					{

					game->map[i][j+1] = 'P';
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
	return (0);

}


int main(int ac, char **av)
{
	// atexit(leaks);
	(void)ac;
	(void)av;
	t_game game;
	game.map = reading_map(av[1]);
	game.x = len_x(*game.map);
	game.y = len_y(game.map);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.x * 32, game.y * 32, "so_long");
	apply_map(game.mlx, game.win, 32, 32, game.map, &game);
	mlx_key_hook(game.win, prees_esc, &game);
	mlx_key_hook(game.win, press_key, &game);
	mlx_hook(game.win, KEY_EXIT, 0, press_x, &game);
	mlx_loop(game.mlx);
}