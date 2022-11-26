##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CFLAGS	+=	-Wall -Wextra -pedantic -g3 -I ./include

SRC = 	get_map_from_argv.c \
		get_map_from_file.c \
		bsq.c				\
		main.c

NAME = bsq

all: $(NAME)

$(NAME):
	make -C ./lib/my/ -j8
	gcc -c $(SRC) $(CFLAGS)
	gcc -o $(NAME) *.o -L ./lib -lmy -lm

clean:
	make -C ./lib/my/ clean
	rm -f *.gcda
	rm -f *.gcno
	rm -f vgcore.*
	rm -f *.log
	rm -f *.o

fclean: clean
	rm -f ./lib/libmy.a
	rm -f ./lib/my/libmy.a
	rm -f $(NAME)
	rm -f my_ls

re: fclean all
