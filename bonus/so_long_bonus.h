/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:56:37 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/06 12:37:30 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
#define SO_LONG_BONUS_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
#include "printf/ft_printf.h"
#include "getnextline/get_next_line.h"

typedef struct s_game
{
	int height;
	int width;
	int x;
	int y;
	int P_X;
	int P_Y;
	void *win;
	void *mlx;
	char **map;
	int fr;
	int mvmt;
	int clct;
	int *ex_it;
	char *img[4];
} t_game;

#define KEY_ESC 53
#define KEY_LEF 123
#define KEY_RIG 124
#define KEY_UP 126
#define KEY_DOW 125
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_EXIT 17

char **reading_map(char *file);
void apply_map(void *mlx, void *win, int x, int y, char **map, t_game *game);
int len_y(char **map);
int len_x(char *map);
int prees_esc(int keycode, t_game *game);
int press_x(t_game *game);
int move_rig(int keycode, t_game *game);
int move_lef(int keycode, t_game *game);
int move_player(int keycode, t_game *game);
int move_up(int keycode, t_game *game);
int move_dow(int keycode, t_game *game);
int count_c(char **map);
void so_parss(int ac, char **av, char **map, t_game *game);
int count_p(char **map);
int count_e(char **map);
int invalid_map(t_game *game);
int valid_extention(char *file);
void flood_fill(t_game *game, int x, int y, int *ex_it);
int valid_chars2(char c);
int valid_path(t_game *game, char **map);
char *ft_itoa(int n);
int animation(t_game *game);
int all_animations(t_game *game);
void aplly_images(t_game *game);
char	*ft_strdup(const char *s1);
#endif
