/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 01:18:27 by nassila           #+#    #+#             */
/*   Updated: 2021/12/12 01:19:56 by nassila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_printf(const char *s, ...);
char	*ft_unsigned(unsigned int n);
void	ft_putnbr(int nb, int *count);
void	ft_put_unsigned(unsigned int n, int *count);
void	ft_putaddr(unsigned long long nb, char type, int *count);

#endif