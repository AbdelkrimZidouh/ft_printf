/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:36:45 by azidouh           #+#    #+#             */
/*   Updated: 2025/11/30 12:36:46 by azidouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long ptr, char *base)
{
	int	len;

	len = 0;
	if (ptr >= 16)
	{
		len += ft_puthex(ptr / 16, base);
	}
	return (len + ft_putchar(base[ptr % 16]));
}

int	ft_putptr(void *ptr)
{
	if (!ptr)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (ft_puthex((unsigned long)ptr, "0123456789abcdef") + 2);
}
