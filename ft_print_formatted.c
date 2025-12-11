/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_formatted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:50:20 by azidouh           #+#    #+#             */
/*   Updated: 2025/11/30 11:50:31 by azidouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_formatted(char specifier, va_list ap)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'p')
		len += ft_putptr(va_arg(ap, void *));
	else if (specifier == 'd' || specifier == 'i')
		len += ft_putnbr_base((long)va_arg(ap, int), "0123456789");
	else if (specifier == 'x')
		len += ft_putnbr_base((long)va_arg(ap, unsigned int),
				"0123456789abcdef");
	else if (specifier == 'X')
		len += ft_putnbr_base((long)va_arg(ap, unsigned int),
				"0123456789ABCDEF");
	else if (specifier == 'u')
		len += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789");
	else
		len += ft_putchar('%');
	return (len);
}
