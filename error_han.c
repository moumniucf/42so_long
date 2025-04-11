/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_han.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:24:02 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/23 14:17:49 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_error_chars(void)
{
	ft_printf("Error: Invalid character found.\n");
	exit(1);
}

void	get_error_p(void)
{
	ft_printf("Error: Invalid number of players found.\n");
	exit(1);
}

void	get_error_e(void)
{
	ft_printf("Error: Invalid number of exits found.\n");
	exit(1);
}

void	get_error_size(void)
{
	ft_printf("Error: Row size mismatch.\n");
	exit(1);
}

void	valid_win(t_game *game)
{
	game->height = len_x(*game->map);
	game->width = len_y(game->map);
	if (game->width * 32 > 5120 || game->height * 32 > 2880)
	{
		ft_printf("Error: Map is too big for the screen!\n");
		exit(1);
	}
}
