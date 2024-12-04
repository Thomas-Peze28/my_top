##
## EPITECH PROJECT, 2024
## makefile pong seb
## File description:
## makfile
##

SRC	=	main.c	\
		my_top.c	\
		setting_up.c	\
		my_get.c	\
		my_get2.c	\
		init.c	\

NAME	=	my_top

OBJ	=	$(SRC:.c=.o)

CFLAGS = -I./include -L./lib/my -lmy -Wall -Wextra -Werror -lncurses

all: build_lib $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

build_lib:
		make -C ./lib/my/

clean_lib:
		make clean -C ./lib/my/

clean: clean_lib
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)

.PHONY: all fclean clean re
