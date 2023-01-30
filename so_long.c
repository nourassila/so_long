/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noasila <noasila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:43:40 by noasila           #+#    #+#             */
/*   Updated: 2022/06/17 22:17:43 by noasila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render(t_read *so)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < so->height)
	{
		j = 0;
		while (j < so->width)
		{
			ft_put_img(so, i, j);
			j++;
		}
		i++;
	}
}

void	ft_start(t_read *so)
{
	so->mlx = mlx_init();
	so->window = mlx_new_window(so->mlx, so->width * 100,
			so->height * 100, "So Long");
	ft_set_urls(so);
	ft_draw_map(so);
	ft_render(so);
	mlx_hook(so->window, 17, 0L, ft_x_key, &so);
	mlx_hook(so->window, 02, 0L, ft_check_key, so);
	mlx_loop(so->mlx);
}

int	main(int argc, char **argv)
{
	t_read	*so;

	so = malloc(sizeof(t_read));
	if (argc == 2)
	{
		if (ft_check_extension(argv[1]))
		{
			if (open(argv[1], O_RDONLY) == -1)
				ft_printf("File not found\n");
			else
			{
				so->tmp = ft_strdup("");
				so->fd = open(argv[1], O_RDONLY);
				if (argc == 2)
					ft_valid_map(so);
			}
		}
	}
	else
		ft_printf("Error, You must enter only two arguments\n");
	return (0);
}
