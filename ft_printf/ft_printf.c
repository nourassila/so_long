/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 01:30:31 by nassila           #+#    #+#             */
/*   Updated: 2021/12/14 22:09:55 by nassila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	do_ft_printf(const char s, va_list args)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (s == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(args, int), &count);
	else if (s == 'u')
		ft_put_unsigned(va_arg(args, unsigned int), &count);
	else if (s == 'p')
	{
		count += ft_putstr("0x");
		ft_putaddr(va_arg(args, unsigned long long), 'p', &count);
	}
	else if (s == 'x')
		ft_putaddr(va_arg(args, unsigned int), 'x', &count);
	else if (s == 'X')
		ft_putaddr(va_arg(args, unsigned int), 'X', &count);
	else if (s == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	va_list		args;
	int			count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			count += ft_putchar(format[i]);
		else
		{
			i++;
			count += do_ft_printf(format[i], args);
		}
		i++;
	}
	va_end(args);
	return (count);
}
