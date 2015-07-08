NAME = libfts.a

SRC_PATH = ./srcs/
SRC = ft_isalpha.s ft_isdigit.s ft_isalnum.s ft_isascii.s ft_isprint.s ft_toupper.s \
	ft_tolower.s ft_bzero.s ft_strcat.s ft_puts.s ft_strlen.s ft_isupper.s ft_islower.s \
	ft_putchar.s ft_putstr.s ft_memset.s ft_memcpy.s ft_strdup.s ft_strnew.s ft_cat.s

OBJ_PATH = ./obj/
OBJ_NAME = $(SRC:.s=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INC = includes

RES = $(shell find . | grep "\~")

CC = nasm
FLAGS = -f macho64

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.s
	@mkdir -p $(OBJ_PATH)
	$(CC) $(FLAGS) -o $@ $< -I $(INC)

clean:
	/bin/rm -f $(OBJ) $(RES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all