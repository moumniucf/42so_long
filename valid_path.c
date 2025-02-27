/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:06:32 by youmoumn          #+#    #+#             */
/*   Updated: 2025/02/27 17:11:15 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int valid_path(t_game *game)
{
	int i = 0;
	int j = 0;
	while(i < game->height)
	{
		j = 0;
		while(j < game->height)
		{
			if(game->map[i][j] == 'P')
			{
				if(game->map[i][j + 1] == '1' || game->map[i][j - 1] == '1')
				{
					// ft_printf("Invalid path\n");
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}