/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:14:23 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/06 16:44:48 by youmoumn         ###   ########.fr       */
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
	int		*ex_it;
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
void move_p(t_game *game, int x, int y);
void	apply_map(void *mlx, void *win, int x, int y, char **map, t_game *game);
int		len_y(char **map);
int		len_x(char *map);
int		prees_esc(int keycode, t_game *game);
int		press_x(t_game *game);
int		move_rig(int keycode, t_game *game);
int		move_lef(int keycode, t_game *game);
int		move_player(int keycode, t_game *game);
int		move_up(int keycode, t_game *game);
int		move_dow(int keycode, t_game *game);
// int		move_p(int keycode, t_game *game, int x, int y);
int		count_c(char **map);
void	so_parss(int ac, char **av, char **map, t_game *game);
int		count_p(char **map);
int		count_e(char **map);
int		invalid_map(t_game *game);
int		valid_extention(char *file);
void	flood_fill(char **map_c, int x, int y, t_game *game, int *cl, int *exit);
int		valid_chars2(char c);
int		valid_path(t_game *game);
void	so2_parss(int ac, char **av, char **map, t_game *game);
int		ft_strlen(char *s);
#endif