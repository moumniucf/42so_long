/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:34:13 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/05 14:35:25 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int len_x(char *map)
{
	if(!map)
		exit(0);
	int x = 0;
	while(map[x] && map[x] != '\n')
	{
		x++;
	}
	return(x);
}

int len_y(char **map)
{
	if(!map)
		return (0);
	int y = 0;
	while(map[y])
	{
		y++;
	}
	return (y);
}