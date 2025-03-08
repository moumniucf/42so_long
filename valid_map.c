/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:11:22 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/08 15:12:33 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_x(char *map)
{
	int	x;

	if (!map)
		return (0);
	x = 0;
	while (map[x] && map[x] != '\n')
	{
		x++;
	}
	return (x);
}

int	len_y(char **map)
{
	int	y;

	if (!map)
		return (0);
	y = 0;
	while (map[y])
	{
		y++;
	}
	return (y);
}

char	**reading_map(char *file)
{
	int		fd;
	int		height;
	char	*line;
	char	**map;
	int		i;

	fd = open(file, O_RDONLY);
	if(fd == -1)
		return (NULL);
	line = get_next_line(fd);
	height = 0;
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	fd = open(file, O_RDONLY);
	if(fd == -1)
		return (NULL);
	map = malloc((height + 1) * sizeof(char *));
	if(!map)
	{
		return (free(map), NULL);
		close(fd);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close (fd);
	return (map);
}

void	apply_map(void	*mlx, void *win, int x, int y, char **map, t_game *game)
{
	void	*img;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	int		img_w;
	int		img_h;
	int		i;
	int		j;

	(void)mlx;
	(void)win;
	img = mlx_xpm_file_to_image(game->mlx, "hayt.xpm", &img_w, &img_h);
	img1 = mlx_xpm_file_to_image(game->mlx, "e.xpm", &img_w, &img_h);
	img2 = mlx_xpm_file_to_image(game->mlx, "sb.xpm", &img_w, &img_h);
	img3 = mlx_xpm_file_to_image(game->mlx, "b.xpm", &img_w, &img_h);
	img4 = mlx_xpm_file_to_image(game->mlx, "coin.xpm", &img_w, &img_h);
	if (!img || !img1 || !img2 || !img3 || !img4 || !map)
	{
		exit(1);
	}
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->win, img, j * x, i * y);
			}
			else if (game->map[i][j] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->win, img1, j * x, i * y);
			}
			else if (game->map[i][j] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, img2, j * x, i * y);
			}
			else if (game->map[i][j] == '0')
			{
				mlx_put_image_to_window(game->mlx, game->win, img3, j * x, i * y);
			}
			else if (game->map[i][j] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win, img4, j * x, i * y);
			}
			j++;
		}
		i++;
	}
}
