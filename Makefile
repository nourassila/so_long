# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noasila <noasila@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/12 03:43:05 by noasila           #+#    #+#              #
#    Updated: 2022/06/14 17:21:13 by noasila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = so_long.c so_long_read.c so_long_map.c so_long_hooks.c so_long_checker.c so_long_read_helper.c 
LIBFT = "libft/libft.a"
# MLX = -lmlx -framework OpenGL -framework AppKit
MLX = -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit
GETNL = "get_next_line/get_next_line.c"
FTPRINTF = "ft_printf/libftprintf.a"
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME) $(SRCS)

$(NAME):$(LIBFT) $(FTPRINTF)
		@gcc $(CFLAGS) $(SRCS) $(MLX) $(LIBFT) $(GETNL) $(FTPRINTF) -o $(NAME) 
		
$(LIBFT):
		@cd libft && make all
		@cd libft && make -s clean
$(FTPRINTF):
		@cd ft_printf && make all
		@cd ft_printf && make -s clean
clean:
	@rm -rf $(NAME)
	
fclean: clean
	@rm -rf $(LIBFT)
	@rm -rf ${NAME}.dSYM
	# @cd libft && make -s fclean
	@make fclean -C libft 
	
re: fclean all 

# -fsanitize=address