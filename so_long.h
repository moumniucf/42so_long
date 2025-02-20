/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:14:23 by youmoumn          #+#    #+#             */
/*   Updated: 2025/02/20 16:54:28 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>
#include "getnextline/get_next_line.h"

typedef struct s_game
{
	int x;
	int y;
}	t_game;

# define R 0x00FF0000
# define G 0x0000FF00
# define B 0x000000FF


char **reading_map();

#endif