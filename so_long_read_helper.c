/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_read_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noasila <noasila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:20:53 by noasila           #+#    #+#             */
/*   Updated: 2022/06/17 22:02:05 by noasila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_check_one(t_read *so)
{
	if (so->tmp)
	{
		so->height = 1;
		so->width = ft_strlen(so->tmp) - 1;
		if (so->tmp[0] == '\n')
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
}

void    ft_check_two(t_read *so)
{
    char *tmp;
    char *tmp1;
    char *tmp2;

    tmp = so->line;
    tmp1 = so->line;
        
	if (so->line[0] == '\n')
	{
		ft_printf("Error\n");
		exit(1);
	}
	so->line = get_next_line(so->fd);
	if (so->line)
	{
        tmp2 = so->tmp;
		so->tmp = ft_strjoin(so->tmp, so->line);
		so->height++;
        free (tmp2);
	}
    free(tmp1);
}
