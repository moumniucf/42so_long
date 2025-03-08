/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsse2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:42:45 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/08 14:44:18 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	so2_parss(char **map, t_game *game)
{
	int	i;
	int	j;

	game->map = map;
	game->px = 1;
    game->py = 1;
	game->height = len_x(*game->map);
	game->width = len_y(game->map);
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (!valid_path(game))
			{
				ft_printf("Error P\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}