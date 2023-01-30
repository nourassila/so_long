/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noasila <noasila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:43:36 by noasila           #+#    #+#             */
/*   Updated: 2022/06/16 23:06:30 by noasila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_extension(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '.')
	{
		if (!str[i])
			return (0);
		i++;
	}
	return (str[i + 1] == 'b' && str[i + 2] == 'e' && str[i + 3] == 'r');
}

void	ft_check_characters(t_read *so)
{
	if (so->collectibles >= 1 && so->exits >= 1 && so->players == 1)
		return ;
	else if (so->players < 1)
	{
		ft_printf("You must have only one player\n");
		exit (0);
	}
	else
	{
		ft_printf("You must have at least these requirements\n");
		ft_printf("1 Collectible\n");
		ft_printf("1 exit point\n");
		ft_printf("1 starting position\n");
		exit (0);
	}
}

void	ft_set_urls(t_read *so)
{
	so->wall.wallpath = "textures/wall.xpm";
	so->collect.collectpath = "textures/collect.xpm";
	so->empty.emptypath = "textures/empty.xpm";
	so->exit.exitpath = "textures/exit.xpm";
	so->player.playerpath = "textures/player.xpm";
}
