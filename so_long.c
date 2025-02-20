/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:14:04 by youmoumn          #+#    #+#             */
/*   Updated: 2025/02/20 18:49:35 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	// void	*win;
	// void	*mlx;
	// void	*image;
	// void	*image2;
	// void	*image3;
	// // char **map = NULL;
	// int img_width = 1200;
	// int img_height = 600;
	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 1200, 1200, "so_long");
	// image = mlx_xpm_file_to_image(mlx, "walls.xpm", &img_width, &img_height);
	// image2 = mlx_xpm_file_to_image(mlx, "exit.xpm", &img_width, &img_height);
	// image3 = mlx_xpm_file_to_image(mlx, "walls.xpm", &img_width, &img_height);
	// if(!image)
	// 	return (0);
	// mlx_put_image_to_window(mlx, win, image, 600, 600);
	// mlx_put_image_to_window(mlx, win, image2, 500, 500);
	// // map = reading_map("map1.ber");
	// // int i = 0;
	// // int j;
	// // while(map[i])
	// // {
	// // 	j = 0;
	// // 	while(map[i][j])
	// // 	{
	// // 		if(map[i][j] == 'C')
	// // 		{
	// // 			mlx_xpm_file_to_image(mlx, "walls.xpm", &img_width, &img_height);
	// // 		}
	// // 	}
	// // }
	char **map = reading_map("map1.ber");
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 600, 600, "test");
	apply_map(mlx, win,32, 32, map);
	mlx_loop(mlx);
}
