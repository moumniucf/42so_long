/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_han_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:17:29 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/15 15:18:43 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_error_chars(void)
{
	ft_printf("Error: Invalid character found.\n");
	exit(1);
}

void	get_error_p(void)
{
	ft_printf("Error: Invalid number of players found.\n");
	exit(1);
}

void	get_error_e(void)
{
	ft_printf("Error: Invalid number of exits found.\n");
	exit(1);
}

void	get_error_size(void)
{
	ft_printf("Error: Row size mismatch.\n");
	exit(1);
}
