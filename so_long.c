/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:14:04 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/12 10:43:03 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_p(game, -1, 0);
	else if (keycode == KEY_S || keycode == KEY_DOW)
		move_p(game, 1, 0);
	else if (keycode == KEY_A || keycode == KEY_LEF)
		move_p(game, 0, -1);
	else if (keycode == KEY_D || keycode == KEY_RIG)
		move_p(game, 0, 1);
	else if (keycode == KEY_ESC)
		prees_esc(keycode, game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game ;

	game = malloc(sizeof(t_game));
	if (ac != 2 || !game)
		return (0);
	game->map = reading_map(av[1]);
	so_parss(game->map, game);
	inva_lid(game);
	if (!valid_extention(av[1]))
	{
		ft_printf("Error\n");
		exit(1);
	}
	game->x = len_x(*game->map);
	game->y = len_y(game->map);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->x * 32, game->y * 32, "./so_long");
	game->mvmt = 0;
	game->clct = 0;
	apply_map(32, 32, game);
	mlx_hook(game->win, 2, 0, move_player, game);
	mlx_hook(game->win, KEY_EXIT, 0, press_x, game);
	mlx_loop(game->mlx);
	return (0);
}
