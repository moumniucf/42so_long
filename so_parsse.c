/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_parsse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:15:44 by youmoumn          #+#    #+#             */
/*   Updated: 2025/02/25 16:40:17 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	ispec(char **map, int x, int y)
// {
	
// }
void	so_parss(int ac, char **av, char **map, t_game *game)
{
	(void)ac;
	(void)av;
	int i;
	int j;
	int size = ft_strlen(*map) - 1;
	game->height = len_x(game->map[0]);
	game->width = len_y(game->map);
	i = 0;
	while(i < game->width)
	{
		j = 0;
		while(j < game->height)
		{
			if(map[0][j] != '1' || count_c(map, game->width, game->height) == 0)
			{
				ft_printf("Error\n");
				exit(1);
			}
			else if(count_e(map, game->width, game->height) != 1 || count_p(map, game->width, game->height) != 1)
			{
				ft_printf("Error\n");
				exit(1);
			}
			else if(size != len_x(map[i]))
			{
				ft_printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
	// int x = 0;
	// int y = 0;
	// while(y < game->width)
	// {
		
	// }
}