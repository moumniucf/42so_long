/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:34:13 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/11 15:07:35 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	line_map(t_game *game)
{
	game->height = len_x(*game->map);
	game->width = len_y(game->map);
}

void	get_error(void)
{
	ft_printf("Error\n");
	exit(1);
}
