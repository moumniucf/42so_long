/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:14:04 by youmoumn          #+#    #+#             */
/*   Updated: 2025/02/20 10:47:52 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	void	*win;
	void	*mlx;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1200, 600, "so_long");
	// int i = 0;
	// while(i <= 1200)
	// {
	// 	mlx_pixel_put(mlx, win, 1200 + i, 600, R);
	// 	i++;
	// }
	mlx_put_image_to_window(mlx, win, "map1.ber", 1200, 600);
	mlx_loop(mlx);
}
