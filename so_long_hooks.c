/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassila <nassila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:43:34 by noasila           #+#    #+#             */
/*   Updated: 2022/06/13 08:30:06 by nassila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_x_key(int keycode)
{
	(void) keycode;
	ft_printf("You did quit the game.\n");
	exit (0);
	return (0);
}

int	ft_check_key(int keycode, t_read *so)
{
	if (keycode == 53)
	{
		ft_printf("Quiting... you did end the game.\n");
		ft_printf("Thanks for playing.\n");
		exit(0);
	}
	if (keycode == 13 || keycode == 126)
		ft_move_player_up(so, 1, 0);
	else if (keycode == 1 || keycode == 125)
		ft_move_player_up(so, -1, 0);
	else if (keycode == 0 || keycode == 123)
		ft_move_player_up(so, 0, 1);
	else if (keycode == 2 || keycode == 124)
		ft_move_player_up(so, 0, -1);
	return (0);
}

int	ft_move_player_up(t_read *so, int i, int j)
{
	if (so->map[so->x_player - i][so->y_player - j] == '0')
		ft_swap(so, i, j);
	if (so->map[so->x_player - i][so->y_player - j] == 'C')
	{
		ft_swap(so, i, j);
		so->collectibles--;
	}
	if (so->collectibles == 0)
	{
		if (so->map[so->x_player - i][so->y_player - j] == 'E')
		{
			ft_printf("you end up the game thanks for playing.\n");
			exit(0);
		}
	}
	ft_render(so);
	return (0);
}

void	ft_swap(t_read *so, int i, int j)
{
	so->map[so->x_player - i][so->y_player - j] = 'P';
	so->map[so->x_player][so->y_player] = '0';
	so->moves++;
	ft_printf("%d, Numbers of moves\n", so->moves);
}
