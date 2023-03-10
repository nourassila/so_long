/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 22:19:12 by nassila           #+#    #+#             */
/*   Updated: 2021/11/18 02:59:32 by nassila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	if (len <= ft_strlen(s))
		str = malloc(sizeof(char) * (len + 1));
	if (len > ft_strlen(s))
	{
		str = malloc(sizeof(char) * (ft_strlen(s) + 1));
		len = ft_strlen(s);
	}
	if (!str)
		return (NULL);
	while (s[i] && len--)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
