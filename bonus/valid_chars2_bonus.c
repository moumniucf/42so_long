/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:05:21 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/06 16:18:03 by youmoumn         ###   ########.fr       */
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
