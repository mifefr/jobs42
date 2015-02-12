#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/27 19:37:38 by abruyere          #+#    #+#              #
#    Updated: 2015/01/27 19:37:39 by abruyere         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all, clean, fclean, re

NAME = fdf
CFLAGS = -Wall -Werror -Wextra -O3 -g -I include
LIBFT = libft -lft
LIBMLX = /usr/X11/lib
LIBML = libml -lml
MLXFLAGS = -lXext -lmlx -lX11
SRCS =  \
		fdf.c \
		ft_makep.c \
		ft_maketd.c \
		ft_struct.c \
		ft_error.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	@make -C $(LIBFT) fclean
	@make -C $(LIBFT)
	@make -C $(LIBML) fclean
	@make -C $(LIBML)
	gcc $(CFLAGS) -c $(SRCS)
	gcc $(OBJ) -o $(NAME) -L $(LIBFT) -L $(LIBML) -L $(LIBMLX) -L /usr/local/lib $(MLXFLAGS)

clean :
	@make -C $(LIBFT) clean
	@make -C $(LIBML) fclean
	@echo "\033[35;1m• \033[0mRemoving object files ...\033[55G\c"
	@rm -rf $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean : clean
	@make -C $(LIBFT) fclean
	@make -C $(LIBML) fclean
	@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re : fclean all

git :
	git add $(SRCS) Makefile fdf.h auteur libft libml
	git commit -m "$(COM)"
	git push
