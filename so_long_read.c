/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noasila <noasila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:43:32 by noasila           #+#    #+#             */
/*   Updated: 2022/06/17 22:25:24 by noasila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_valid_map(t_read *so)
{
	char *tmp;
	so->line = get_next_line(so->fd);
	tmp = so->tmp;
	so->tmp = ft_strjoin(so->tmp, so->line);
	free(tmp);
	tmp = NULL;
	ft_check_one(so);
	if (so->line == '\0')
	{
		ft_printf("Error\n");
		exit(1);
	}
	while (so->line != NULL)
		ft_check_two(so);
	if (so->tmp && so->tmp[ft_strlen(so->tmp) - 1] == '\n')
	{
		ft_printf("Error.\n");
		exit(1);
	}
	free(so->line);
	so->map = ft_split(so->tmp, '\n');
	so->i = 0;
	so->j = 0;
	ft_confirm(ft_check_borders(so), so);
}

int ft_isValid(t_read *so)
{
	int check;

	check= 1;
	if ((so->j == 0 && so->map[so->i][so->j] != '1')
		|| (so->j == so->width - 1 && so->map[so->i][so->j] != '1'))
		check = 0;
	if ((so->i == 0 && so->map[so->i][so->j] != '1')
		|| (so->i == so->height - 1 && so->map[so->i][so->j] != '1'))
		check = 0;
	if (so->map[so->height - 1] == so->map[so->width - 1])
		check = 0;
	return (check);
}

int	ft_check_borders(t_read *so)
{
	int		check;
	size_t	len;

	len = 0;
	check = 1;
	if (so->map[0])
		len = ft_strlen(so->map[0]);
	while (so->map[so->i])
	{
		so->j = 0;
		if (len != ft_strlen(so->map[so->i]))
			check = 0;
		while (so->map[so->i][so->j])
		{
			check = ft_isValid(so);
			so->j++;
		}
		so->i++;
	}
	ft_count_characters(so);
	return (check);
}

void check_char(char c)
{
	if (c !='P' && c !='C' && c !='E' && c !='1' && c !='0')
	{
		ft_printf("Error, Other unused characters should not be in your map.\n");
		exit (1);
	}
}

void	ft_count_characters(t_read *so)
{
	int	x;
	int	y;

	x = 0;
	init_struct(so);
	while (so->map[x])
	{
		y = -1;
		while (so->map[x][++y])
		{
			check_char(so->map[x][y]);
			if (so->map[x][y] == 'C')
				so->collectibles++;
			else if (so->map[x][y] == 'P')
				so->players++;
			else if (so->map[x][y] == 'E')
				so->exits++;
			else if (so->map[x][y] != '1' && so->map[x][y] != '0')
				ft_printf("%s, Walls and Empty spaces aren't available");
		}
		x++;
	}
	ft_check_characters(so);
}

void	init_struct(t_read *so)
{
	so->collectibles = 0;
	so->players = 0;
	so->exits = 0;
	so->x_player = 0;
	so->y_player = 0;
}

void	ft_confirm(int check, t_read *so)
{
	if (check == 0)
	{
		printf("Invalid map please check again.\n");
		exit(1);
	}
	else
		printf("Your game has a valide Map, starting...\n");
		
	ft_start(so);
}
