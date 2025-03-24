/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:25:01 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/24 11:30:12 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printother(va_list lst, const char c)
{
	int	ptr;

	ptr = 0;
	if (c == '%')
		ptr += ft_putchar('%');
	else if (c == 'p')
		ptr += ft_putstr("0x") + ft_putpoint(va_arg(lst, unsigned long));
	else if (c == 'u')
		ptr += ft_putunsigned(va_arg(lst, unsigned int));
	else if (c == 'c')
		ptr += ft_putchar(va_arg(lst, int));
	else if (c == 'd' || c == 'i')
		ptr += ft_putnbr(va_arg(lst, int));
	return (ptr);
}

int	ft_printf(const char *form, ...)
{
	int			x;
	va_list		lst;

	va_start (lst, form);
	x = 0;
	while (*form)
	{
		if (*form == '%')
		{
			form++;
			if (*form == '\0')
				return (0);
			if (*form == 's')
				x += ft_putstr(va_arg(lst, char *));
			else if (*form == 'x' || *form == 'X')
				x += ft_puthex(va_arg(lst, int), *form);
			else
				x += ft_printother(lst, *form);
		}
		else
			x += ft_putchar(*form);
		form++;
	}
	return (va_end(lst), x);
}
