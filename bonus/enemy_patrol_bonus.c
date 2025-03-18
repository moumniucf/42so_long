/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:44:36 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/18 13:45:37 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
void	find_enemy(t_game *game)
{
	int i;
	int j;
	i = 0;
	while(i < game->height)
	{
		j = 0;
		while(j < game->width)
		{
			if(game->map[j][j] == 'H')
			{
				game->enmx = i;
				game->enmy = j;
			}
			j++;
		}
		i++;
	}
}


// int	move_enemy(t_game *game)
// {
// 	int i;
// 	int j;
// 	find_enemy(game);
// 	game->px = i;
// 	game->py = j;
// 	if(game->)
// }

int	move_enemy(t_game *game)
{
	int	new_x;

	new_x = game->enmx + game->dir;

	// ✅ Ila enemy wsll l7ayt, ybdl direction
	if (game->map[game->enmy][new_x] == '1')
		game->dir = -game->dir;

	// ✅ Move Enemy
	if (game->map[game->enmy][new_x] != '1')
	{
		game->map[game->enmy][game->enmx] = '0'; // Remove old position
		game->map[game->enmy][new_x] = 'H'; // Update new position
		game->enmx = new_x;
	}

	return (0); // ✅ `mlx_loop_hook()` khas function trotoni `int`
}
