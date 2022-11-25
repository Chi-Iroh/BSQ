##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CFLAGS	+=	-Wall -Wextra -pedantic -g3 -I ./include/

SRC	=	get_map_from_argv.c \
		get_map_from_file.c \
		bsq.c				\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -L ./lib/ -l my

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
