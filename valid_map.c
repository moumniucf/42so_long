/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:11:22 by youmoumn          #+#    #+#             */
/*   Updated: 2025/02/22 17:41:41 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **reading_map(char *file)
{
	int fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);

	char **map = malloc(100 * sizeof(char *));
	int i = 0;
	char *line = get_next_line(fd);
	while (line)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}

	map[i] = NULL;
	return (map);
}

void apply_map(void *mlx, void *win, int x, int y, char **map)
{
	void *img;
	void *img1;
	void *img2;
	void *img3;
	void *img4;
	int img_w;
	int img_h;
	img = mlx_xpm_file_to_image(mlx, "hayt.xpm", &img_w, &img_h);
	img1 = mlx_xpm_file_to_image(mlx, "exit.xpm", &img_w, &img_h);
	img2 = mlx_xpm_file_to_image(mlx, "arbi.xpm", &img_w, &img_h);
	img3 = mlx_xpm_file_to_image(mlx, "wall.xpm", &img_w, &img_h);
	img4 = mlx_xpm_file_to_image(mlx, "coins.xpm", &img_w, &img_h);
	if (!img || !img1 || !img2 || !img3 || !img4)
	{
		printf("ko\n");
		exit(1);
	}
	int i = 0;
	while (map[i])
	{
		int j = 0;
		while (map[i][j])
		{
			if(map[i][j] == '1')
			{
				mlx_put_image_to_window(mlx, win,img ,j * x, i * y);
			}
			else if(map[i][j] == 'E')
			{
				mlx_put_image_to_window(mlx, win,img1 ,j * x, i * y);
			}
			else if(map[i][j] == 'P')
			{
				mlx_put_image_to_window(mlx, win,img2 ,j * x, i * y);
			}
			else if(map[i][j] == '0')
			{
				mlx_put_image_to_window(mlx, win,img3 ,j * x, i * y);
			}
			else if(map[i][j] == 'C')
			{
				mlx_put_image_to_window(mlx, win,img4 ,j * x, i * y);
			}
			j++;
		}
		i++;
	}
}

