/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_han_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tahadev <tahadev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:17:29 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/22 21:13:23 by tahadev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_error_chars(void)
{
	ft_printf("Error: Invalid character found.\n");
	exit(1);
}

void	get_error_e(void)
{
	ft_printf("Error: Invalid number of exits found or player.\n");
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
