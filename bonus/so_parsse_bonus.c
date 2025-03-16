/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_parsse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:01:38 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/16 10:28:56 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	invalid_map(t_game *game)
{
	int	i;
	int	j;

	game->height = len_x(game->map[0]);
	game->width = len_y(game->map);
	i = 0;
	j = 0;
	while (i < game->width)
	{
		if ((game->map[i][j] != '1' || game->map[i][game->height - 1] != '1'))
			return (0);
		i++;
	}
	i = 0;
	while (j < game->height)
	{
		if (game->map[i][j] != '1' || game->map[game->width - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	valid_extention(char *file)
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
	if (dot != 1 || len - 4 == 0)
	{
		return (0);
	}
	return (1);
}

void	invalid_map2(char **map)
{
	if (!map)
	{
		get_error2();
	}
}

void	so_parss_b2(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->width)
	{
		j = 0;
		while (j < game->height)
		{
			if (count_c(map) == 0)
				get_error_chars();
			else if (count_e(map) != 1 || count_p(map) != 1 || !count_h(map))
				get_error_e();
			j++;
		}
		i++;
	}
}

void	so_parss_b(char **map, t_game *game)
{
	int	i;
	int	j;

	invalid_map2(map);
	line_map(game);
	so_parss_b2(map, game);
	i = 0;
	while (i < game->width)
	{
		j = 0;
		while (j < game->height)
		{
			if (len_x(map[0]) != len_x(map[i]) || !invalid_map(game))
				get_error_size();
			else if (count_p(map) != 1)
				get_error_e();
			else if (!valid_chars2(game->map[i][j]))
				get_error_chars();
			else
				valid_win(game);
			j++;
		}
		i++;
	}
}
