/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:25:49 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/24 11:25:53 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_puthex(unsigned int n, char c)
{
	int		i;
	char	*uper;
	char	*lower;

	i = 0;
	lower = "0123456789abcdef";
	uper = "0123456789ABCDEF";
	if (n < 16 && c == 'x')
		i += ft_putchar(lower[n]);
	else if (n < 16 && c == 'X')
		i += ft_putchar(uper[n]);
	else
	{
		i += ft_puthex(n / 16, c);
		i += ft_puthex(n % 16, c);
	}
	return (i);
}
