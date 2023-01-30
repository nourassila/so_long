/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassila <nassila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:45:23 by noasila           #+#    #+#             */
/*   Updated: 2022/06/13 08:44:18 by nassila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_map(t_read *so)
{
	so->wall.image = mlx_xpm_file_to_image(so->mlx,
			so->wall.wallpath, &so->s, &so->s);
	so->collect.image = mlx_xpm_file_to_image(so->mlx,
			so->collect.collectpath, &so->s, &so->s);
	so->empty.image = mlx_xpm_file_to_image(so->mlx,
			so->empty.emptypath, &so->s, &so->s);
	so->exit.image = mlx_xpm_file_to_image(so->mlx,
			so->exit.exitpath, &so->s, &so->s);
	so->player.image = mlx_xpm_file_to_image(so->mlx,
			so->player.playerpath, &so->s, &so->s);
}

void	ft_put_img(t_read *so, int i, int j)
{
	if (so->map[i][j] == 'C')
		mlx_put_image_to_window(so->mlx, so->window,
			so->collect.image, j * 100, i * 100);
	else if (so->map[i][j] == '0')
		mlx_put_image_to_window(so->mlx, so->window,
			so->empty.image, j * 100, i * 100);
	else if (so->map[i][j] == '1')
		mlx_put_image_to_window(so->mlx, so->window,
			so->wall.image, j * 100, i * 100);
	else if (so->map[i][j] == 'E')
		mlx_put_image_to_window(so->mlx, so->window,
			so->exit.image, j * 100, i * 100);
	else if (so->map[i][j] == 'P')
	{
		so->y_player = j;
		so->x_player = i;
		mlx_put_image_to_window(so->mlx, so->window,
			so->player.image, j * 100, i * 100);
	}
}
