/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 10:57:22 by azidouh           #+#    #+#             */
/*   Updated: 2025/11/29 10:57:24 by azidouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_formatted(char specifier, va_list ap);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_strlen(char *str);
int	ft_putnbr_base(long n, char *ptr);
int	ft_putptr(void *ptr);

#endif
