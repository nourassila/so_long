/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noasila <noasila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:43:38 by noasila           #+#    #+#             */
/*   Updated: 2022/06/14 17:22:39 by noasila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <limits.h>

typedef struct s_wall
{
	void	*image;
	int		imgheight;
	int		imgwidth;
	char	*wallpath;
}	t_wall;

typedef struct s_player
{
	void	*image;
	int		imgheight;
	int		imgwidth;
	char	*playerpath;
}	t_player;

typedef struct s_exit
{
	void	*image;
	int		imgheight;
	int		imgwidth;
	char	*exitpath;
}	t_exit;

typedef struct s_empty
{
	void	*image;
	int		imgheight;
	int		imgwidth;
	char	*emptypath;
}	t_empty;

typedef struct s_collect
{
	void	*image;
	int		imgheight;
	int		imgwidth;
	char	*collectpath;
}	t_collect;

typedef struct s_read{
	char		*tmp;
	char		*line;
	int			fd;
	size_t		height;
	size_t		width;
	char		**map;
	size_t		i;
	size_t		j;
	t_wall		wall;
	t_player	player;
	t_exit		exit;
	t_empty		empty;
	t_collect	collect;
	int			collectibles;
	int			emptyspace;
	int			players;
	int			exits;
	int			walls;
	void		*window;
	void		*mlx;
	int			s;
	int			x_player;
	int			y_player;
	void		*img;
	int			moves;
	int			exitz;
}	t_read;

int		ft_check_extension(char *str);
char	*ft_strdup(const char *s1);
void	ft_confirm(int check, t_read *so);
int		ft_check_borders(t_read *so);
void	init_struct(t_read *so);
void	ft_count_characters(t_read *so);
int		ft_x_key(int keycode);
int		ft_keys(int keycode);
void	ft_valid_map(t_read *so);
char	*get_next_line(int fd);
void	ft_check_characters(t_read *so);
void	ft_start(t_read *so);
void	ft_draw_map(t_read *so);
void	ft_put_img(t_read *so, int i, int j);
void	ft_set_urls(t_read *so);
int		ft_move_player_up(t_read *so, int i, int j);
int		ft_check_key(int keycode, t_read *so);
void	ft_render(t_read *so);
void	ft_swap(t_read *so, int i, int j);
void    ft_check_one(t_read *so);
void    ft_check_two(t_read *so);
#endif
