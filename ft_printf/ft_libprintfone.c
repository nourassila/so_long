/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libprintfone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 01:26:17 by nassila           #+#    #+#             */
/*   Updated: 2021/12/14 22:12:36 by nassila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *count)
{
	unsigned int	n;

	if (nb < 0)
	{
		*count += ft_putchar('-');
		n = nb * -1;
	}
	else
		n = nb;
	if (n > 9)
	{
		ft_putnbr(n / 10, count);
		*count += ft_putchar((n % 10) + '0');
	}
	else
		*count += ft_putchar(n + '0');
}

void	ft_put_unsigned(unsigned int n, int *count)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, count);
		*count += ft_putchar((n % 10) + '0');
	}
	else
		*count += ft_putchar(n + '0');
}

static void	ft_puthex(unsigned long long nb, char *base, int *count)
{
	if (nb >= 16)
	{
		ft_puthex(nb / 16, base, count);
	}
	*count += ft_putchar(base[nb % 16]);
}

void	ft_putaddr(unsigned long long nb, char type, int *count)
{
	if (type == 'x' || type == 'p')
		ft_puthex(nb, "0123456789abcdef", count);
	else if (type == 'X')
		ft_puthex(nb, "0123456789ABCDEF", count);
}
