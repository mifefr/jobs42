# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/30 22:05:52 by abruyere          #+#    #+#              #
#    Updated: 2014/12/30 15:26:23 by abruyere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libml.a

CC = gcc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror -I ../include

SRCS = color.c draw_line.c mouse_draw.c \
	   mouse_hook.c key_hook.c expose_hook.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	$(CC) $(FLAGS) -c $(SRCS) -I.
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)


clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all
