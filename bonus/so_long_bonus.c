/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:00:56 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/08 16:07:03 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_player(int keycode, t_game *game)
{
	if (keycode == KEY_RIG || keycode == KEY_D)
		move_p(game, 0, 1);
	else if (keycode == KEY_LEF || keycode == KEY_A)
		move_p(game, 0, -1);
	else if (keycode == KEY_ESC)
		prees_esc(keycode, game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_p(game, -1, 0);
	else if (keycode == KEY_S || keycode == KEY_DOW)
		move_p(game, 1, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (0);
	(void)av;
	game = malloc(sizeof(t_game));
	game->map = reading_map(av[1]);
	if (!valid_extention(av[1]))
	{
		ft_printf("Error\n");
		exit(1);
	}
	so_parss_b(game->map, game);
	so2_parss(game->map, game);
	game->x = len_x(*game->map);
	game->y = len_y(game->map);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->x * 32, game->y * 32, "./so_long_bonus");
	game->mvmt = 0;
	game->clct = 0;
	game->fr = 0;
	apply_map(game->mlx, game->win, 32, 32, game->map, game);
	mlx_loop_hook(game->mlx, all_animations, game);
	mlx_key_hook(game->win, move_player, game);
	mlx_hook(game->win, KEY_EXIT, 0, press_x, game);
	mlx_loop(game->mlx);
}
