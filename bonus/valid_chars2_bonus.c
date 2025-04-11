/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:05:21 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/15 15:29:43 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	valid_chars2(char c)
{
	int		i;
	char	*s;

	s = "01PECH";
	i = 0;
	while (i < 6)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	invalid2(char **map)
{
	if (!map)
	{
		ft_printf("Error\n");
		exit(1);
	}
}

void	get_error2(void)
{
	ft_printf("Error in map\n");
	exit(1);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	count_h(char **map)
{
	int	i;
	int	j;
	int	c;

	if (!map)
		return (0);
	i = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'H')
			{
				c++;
			}
			j++;
		}
		i++;
	}
	return (c);
}
