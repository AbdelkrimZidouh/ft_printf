/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 10:57:37 by azidouh           #+#    #+#             */
/*   Updated: 2025/11/29 10:57:39 by azidouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, fmt);
	len = 0;
	i = 0;
	if (write(1, "", 0) == -1 || !fmt)
		return (-1);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (!fmt[i + 1])
				return (-1);
			len += ft_print_formatted(fmt[++i], args);
		}
		else
			len += ft_putchar(fmt[i]);
		i++;
	}
	va_end(args);
	return (len);
}
