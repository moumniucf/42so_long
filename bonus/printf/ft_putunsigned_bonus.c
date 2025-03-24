/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:26:51 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/24 11:26:53 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putunsigned(unsigned int n)
{
	unsigned int	x;

	x = 0;
	if (n > 9)
	{
		x += ft_putunsigned(n / 10);
		x += ft_putunsigned(n % 10);
	}
	else
	{
		x += ft_putchar(n + 48);
	}
	return (x);
}
