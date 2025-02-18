/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:14:04 by youmoumn          #+#    #+#             */
/*   Updated: 2025/02/18 16:51:33 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	void	*img ;
	void	*mlx;
	void	*image;

	mlx = mlx_init();
	img = mlx_new_window(mlx, 1200, 1000, "so_long");
	image = mlx_new_image(mlx, 1200, 100);
	int i = 0;
	while(i <= 1200)
	{
		mlx_pixel_put(mlx, img, 100, 100, R);
		i++;
	}
	mlx_loop(mlx);
}
