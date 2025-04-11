/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:26:10 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/24 11:26:15 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putpoint(unsigned long n)
{
	int		x;
	char	*s;

	x = 0;
	s = "0123456789abcdef";
	if (n >= 16)
	{
		x += ft_putpoint(n / 16);
		x += ft_putpoint(n % 16);
	}
	else
	{
		x += ft_putchar(s[n]);
	}
	return (x);
}
