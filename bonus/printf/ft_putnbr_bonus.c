/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:26:00 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/24 11:30:14 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putnbr(int n)
{
	int		x;
	long	y;

	x = 0;
	y = (long)n;
	if (y < 0)
	{
		x += ft_putchar('-');
		y *= -1;
	}
	if (y > 9)
	{
		x += ft_putnbr(y / 10);
		x += ft_putnbr(y % 10);
	}
	else
	{
		x += ft_putchar(y + 48);
	}
	return (x);
}
