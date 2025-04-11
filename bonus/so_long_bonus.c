/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:00:56 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/23 15:09:49 by youmoumn         ###   ########.fr       */
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

void	invlid_ex(char *file)
{
	if (!valid_extention(file))
	{
		ft_printf("Error exe\n");
		exit(1);
	}
}

void	help_norm(t_game *game)
{
	so_parss_b(game->map, game);
	invalid_m(game);
}

void	error_ac(int ac)
{
	if (ac != 2)
		exit(1);
}

int	main(int ac, char **av)
{
	t_game	*game;

	error_ac(ac);
	invlid_ex(av[1]);
	game = malloc(sizeof(t_game));
	if (!game)
		exit(1);
	game->map = reading_map(av[1]);
	help_norm(game);
	game->x = len_x(*game->map);
	game->y = len_y(game->map);
	game->mlx = mlx_init();
	if (!game->mlx)
		help_fr(game);
	game->win = mlx_new_window(game->mlx, game->x * 32,
			game->y * 32, "./so_long_bonus");
	if (!game->win)
		help_fr(game);
	game->mvmt = 0;
	game->fr = 0;
	apply_map(32, 32, game);
	mlx_hook(game->win, 2, 0, move_player, game);
	mlx_hook(game->win, KEY_EXIT, 0, press_x, game);
	mlx_loop_hook(game->mlx, all_animations, game);
	mlx_loop(game->mlx);
}
