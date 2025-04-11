/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:14:23 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/24 11:27:55 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "printf/ft_printf.h"
# include "getnextline/get_next_line.h"

typedef struct s_game
{
	int		height;
	int		width;
	int		x;
	int		y;
	int		p_x;
	int		p_y;
	void	*win;
	void	*mlx;
	char	**map;
	int		mvmt;
	int		clct;
	int		ex_it;
	void	*img;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
}	t_game;

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

char	**reading_map(char *file);
void	move_p(t_game *game, int x, int y);
void	apply_map(int x, int y, t_game *game);
int		len_y(char **map);
int		len_x(char *map);
int		prees_esc(int keycode, t_game *game);
int		press_x(t_game *game);
int		count_c(char **map);
void	so_parss(char **map, t_game *game);
int		count_p(char **map);
int		count_e(char **map);
int		invalid_map(t_game *game);
int		valid_extention(char *file);
void	flood_fill(char **map_c, int x, int y, t_game *game);
int		valid_chars2(char c);
int		valid_path(t_game *game);
int		ft_strlen(char *s);
void	find_pl(t_game *game);
void	free_map(char **map);
void	appcle(t_game *game);
void	you_win(t_game *game, int x, int y);
void	find_player(t_game *game);
void	get_error(void);
void	line_map(t_game *game);
void	inva_lid(t_game *game);
void	get_error_chars(void);
void	get_error_size(void);
void	get_error_p(void);
void	get_error_chars(void);
void	valid_win(t_game *game);
#endif