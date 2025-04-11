/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:56:37 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/24 11:27:37 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "printf/ft_printf_bonus.h"
# include "getnextline/get_next_line_bonus.h"

typedef struct s_game
{
	int		height;
	int		width;
	int		x;
	int		y;
	int		px;
	int		py;
	int		dir;
	void	*win;
	void	*mlx;
	char	**map;
	char	*n;
	int		fr;
	int		mvmt;
	int		enmx;
	int		enmy;
	int		clct;
	int		ex_it;
	void	*imag;
	void	*imag1;
	void	*imag2;
	void	*imag3;
	void	*imag4;
	char	*img[4];
}		t_game;

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
# define WH 0xFFFFFF

char	**reading_map(char *file);
void	apply_map(int x, int y, t_game *game);
int		len_y(char **map);
int		len_x(char *map);
int		prees_esc(int keycode, t_game *game);
void	move_p(t_game *game, int x, int y);
int		press_x(t_game *game);
int		count_c(char **map);
void	so_parss_b(char **map, t_game *game);
int		count_p(char **map);
int		count_e(char **map);
int		invalid_map(t_game *game);
int		valid_extention(char *file);
void	flood_fill(char **map_c, int x, int y, t_game *game);
int		valid_chars2(char c);
int		valid_path(t_game *game);
char	*ft_itoa(int n);
int		animation(t_game *game);
int		all_animations(t_game *game);
void	aplly_images(t_game *game);
char	*ft_strdup(char *s1);
void	find_pl(t_game *game);
void	appcle(t_game *game);
void	you_win(t_game *game, int x, int y);
void	invalid2(char **map);
void	get_error2(void);
void	line_map(t_game *game);
void	free_map(char **map);
int		get_heigth(char *line);
void	invalid_m(t_game *game);
int		count_h(char **map);
void	get_error_chars(void);
void	get_error_e(void);
void	get_error_size(void);
void	valid_win(t_game *game);
int		move_enemy(t_game *game);
void	help_fr(t_game *game);
#endif