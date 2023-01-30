/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassila <nassila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 05:45:07 by nassila           #+#    #+#             */
/*   Updated: 2022/06/14 05:55:11 by nassila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	int		size;

	size = 0;
	while (s1[size])
			size++;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char	line[OPEN_MAX];
	char	c;
	int		i;

	i = 0;
	while (read(fd, &c, 1) > 0)
	{
		line[i] = c;
		i++;
		if (c == '\n')
			break ;
	}
	line[i] = '\0';
	if (line[0] == '\0')
		return (NULL);
	return (ft_strdup(line));
}
