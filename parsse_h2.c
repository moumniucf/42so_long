/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsse_h2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:37:43 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/06 12:44:52 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so2_parss(int ac, char **av, char **map, t_game *game)
{
	(void)ac;
	(void)av;
	(void)map;
	int i;
	int j;
	game->height = len_x(*game->map);
	game->width = len_y(game->map);
	i = 0;
	while(i < game->height)
	{
		j = 0;
		while(j < game->width)
		{
			if(!valid_path(game))
			{
				ft_printf("Error path\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}