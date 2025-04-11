/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:11:22 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/23 15:03:16 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_heigth(char *line)
{
	int	len;
	int	fd;

	fd = open(line, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	len = 0;
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (len);
}

char	**reading_map(char *file)
{
	int		fd;
	int		height;
	char	*line;
	char	**map;
	int		i;

	height = get_heigth(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = malloc((height + 1) * sizeof(char *));
	if (!map)
		return (close(fd), NULL);
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

void	ima_ges(int i, int j, t_game *game)
{
	game->img = mlx_xpm_file_to_image(game->mlx, "./textures/hayt.xpm", &i, &j);
	game->img1 = mlx_xpm_file_to_image(game->mlx, "./textures/e.xpm", &i, &j);
	game->img2 = mlx_xpm_file_to_image(game->mlx, "./textures/sb.xpm", &i, &j);
	game->img3 = mlx_xpm_file_to_image(game->mlx, "./textures/b.xpm", &i, &j);
	game->img4 = mlx_xpm_file_to_image(game->mlx, "./textures/coi.xpm", &i, &j);
	if (!game->img || !game->img1 || !game->img2 || !game->img3 || !game->img4)
	{
		exit(1);
	}
}

void	a_i(int i, int j, void *imag, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, imag, i, j);
}

void	apply_map(int x, int y, t_game *game)
{
	int		i;
	int		j;

	ima_ges(x, y, game);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				a_i(j * x, i * y, game->img, game);
			else if (game->map[i][j] == 'E')
				a_i(j * x, i * y, game->img1, game);
			else if (game->map[i][j] == 'P')
				a_i(j * x, i * y, game->img2, game);
			else if (game->map[i][j] == '0')
				a_i(j * x, i * y, game->img3, game);
			else if (game->map[i][j] == 'C')
				a_i(j * x, i * y, game->img4, game);
			j++;
		}
		i++;
	}
}
