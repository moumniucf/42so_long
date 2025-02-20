/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:11:22 by youmoumn          #+#    #+#             */
/*   Updated: 2025/02/20 16:55:23 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **reading_map(char *file)
{
	char *line;
	int fd = open(file, O_RDONLY);
	char **map = malloc((100) * sizeof(char *));
	line = get_next_line(fd);
	int i = 0;
	while(line)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return(map);
}
void	apply_map(void	*mlx, char *files, int x, int y, char **map)
{
	int i = 0;
	while(map[i])
	{
		int j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'C')
			{
				mlx_xpm_file_to_image(mlx, files, &x, &y);
			}
			j++;
		}
		i++;
	}
}
int main()
{
	char **map = reading_map("map1.ber");
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 12, 12, "test");
	apply_map(mlx, "walls.xpm", 12, 12, map);
}