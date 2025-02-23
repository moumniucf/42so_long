/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:14:23 by youmoumn          #+#    #+#             */
/*   Updated: 2025/02/23 17:31:45 by youmoumn         ###   ########.fr       */
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
	void *win;
	void *mlx;
	int P_X;
	int P_Y;
	char **map;
}	t_game;

# define R 0x00FF0000
# define G 0x0000FF00
# define B 0x000000FF
# define KEY_ESC 53 
# define KEY_LEF 123
# define KEY_RIG 124
# define KEY_UP 126
# define KEY_DOW 125
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_EXIT 17


char **reading_map(char *file);
void apply_map(void *mlx, void *win, int x, int y, char **map, t_game *game);
int len_y(char **map);
int len_x(char *map);
int prees_esc(int keycode, t_game *game);
int	press_x(t_game *game);
#endif