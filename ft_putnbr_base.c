/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:30:01 by azidouh           #+#    #+#             */
/*   Updated: 2025/11/30 11:30:02 by azidouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long n, char *ptr)
{
	int	len;
	int	base;

	len = 0;
	base = ft_strlen(ptr);
	if (n < 0)
	{
		ft_putchar('-');
		return (ft_putnbr_base(-n, ptr) + 1);
	}
	else if (n < base)
		return (ft_putchar(ptr[n]));
	else
	{
		len = ft_putnbr_base(n / base, ptr);
		return (len + ft_putchar(ptr[n % base]));
	}
}
