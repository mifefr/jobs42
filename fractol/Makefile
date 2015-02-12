# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/30 15:10:16 by abruyere          #+#    #+#              #
#    Updated: 2015/01/14 17:09:00 by abruyere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = fractol
CFLAGS = -Wall -Werror -Wextra -O3 -g -I includes/
LIBFT = libft -lft
LIBMLX = /usr/X11/lib
MLXFLAGS = -lXext -lmlx -lX11
SRCS =  ft_julia.c ft_procarg.c mouse_hook.c \
		ft_getcol.c ft_mandelbrot.c key_hook.c \
		fractol.c ft_gethexa.c ft_modulo.c expose_hook.c \
		mouse_win.c ft_draw_square.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	@make -C $(LIBFT) fclean
	@make -C $(LIBFT)
	gcc $(CFLAGS) -c $(SRCS)
	gcc $(OBJ) -o $(NAME) -L $(LIBFT) -L $(LIBMLX) $(MLXFLAGS)

clean :
	@make -C $(LIBFT) clean
	@echo "\033[35;1m• \033[0mRemoving object files ...\033[55G\c"
	@rm -rf $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean : clean
	@make -C $(LIBFT) fclean
	@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re : fclean all

git :
	git add $(SRCS) Makefile fractol.h auteur libft
	git commit -m "$(COM)"
	git push
