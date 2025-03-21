/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:14:04 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/21 16:19:05 by youmoumn         ###   ########.fr       */
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

void	invalid_exi(char *file)
{
	if (!valid_extention(file))
	{
		ft_printf("Error exe\n");
		exit(1);
	}
}

void	error_ac(int ac)
{
	if (ac != 2)
		exit(1);
}
void	leaks()
{
	system("leaks so_long");
}
int	main(int ac, char **av)
{
	atexit(leaks);
	t_game	*game ;

	error_ac(ac);
	invalid_exi(av[1]);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	game->map = reading_map(av[1]);
	so_parss(game->map, game);
	inva_lid(game);
	game->x = len_x(*game->map);
	game->y = len_y(game->map);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_map(game->map);
		free(game);
		return(1);
	}
	game->win = mlx_new_window(game->mlx, game->x * 32,
			game->y * 32, "./so_long");
	// game->win = NULL;
	if (!game->win)
	{
		free_map(game->map);
		free(game);
		return (1);
	}
	game->mvmt = 1;
	game->clct = 0;
	apply_map(32, 32, game);
	mlx_hook(game->win, 2, 0, move_player, game);
	mlx_hook(game->win, KEY_EXIT, 0, press_x, game);
	mlx_loop(game->mlx);
}
