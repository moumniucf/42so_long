/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_parsse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:01:38 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/02 12:12:14 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	invalid_map(t_game *game)
{
	game->height = len_x(game->map[0]);
	game->width = len_y(game->map);
	int i = 0;
	int j = 0;
	while(i < game->width)
	{
		if((game->map[i][j] != '1' || game->map[i][game->height - 1] != '1'))
			return(0);
		i++;
	}
	i = 0;
	while(j < game->height)
	{
		if(game->map[i][j] != '1' || game->map[game->width - 1][j] != '1')
			return (0);
		j++;
	}
	return(1);
}
int valid_extention(char *file)
{
	int		len;
	int		dot;
	int		i;
	char	*ber;

	len = ft_strlen(file);
	dot = 0;
	i = 0;
	ber = ".ber";
	while (i < len)
	{
		if (i < 4 && (file[len - 1 - i] != ber[3 - i]))
		{
			return (0);
		}
		if (file[i] == '.')
			dot++;
		i++;
	}
	if (dot > 1)
	{
		return (0);
	}
	return (1);
}

void	so_parss(int ac, char **av, char **map, t_game *game)
{
	(void)ac;
	(void)av;
	int i;
	int j;
	int size = ft_strlen(*map) - 1;
	game->height = len_x(*game->map);
	game->width = len_y(game->map);
	i = 0;
	while(i < game->width)
	{
		j = 0;
		while(j < game->height)
		{
			if(count_c(map) == 0)
			{
				ft_printf("Error1\n");
				exit(1);
			}
			else if(count_e(map) != 1 || count_p(map) != 1)
			{
				ft_printf("Error2\n");
				exit(1);
			}
			else if(size != len_x(map[i]))
			{
				ft_printf("Error3\n");
				exit(1);
			}
			else if(!invalid_map(game))
			{
				ft_printf("Error4\n");
				exit(1);
			}
			else if(!valid_chars2(game->map[i][j]))
			{
				ft_printf("Error5\n");
				exit(1);
			}
			// else if(!valid_path(game, map))
			// {
			// 	ft_printf("OK\n");
			// }
			j++;
		}
		i++;
	}
}