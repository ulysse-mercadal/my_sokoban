##
## EPITECH PROJECT, 2023
## my_ls
## File description:
## Makefile
##

SRC		=	src/main.c				\
			src/move_player.c		\
			src/move_player2.c		\
			src/printh.c			\
			src/check_end_game.c	\

CFLAGS	=	-g3 -Wall -Wextra

NAME	=	my_sokoban

OBJ		= 	$(SRC:.c=.o)	\

FLAGS	=	-lncurses

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(FLAGS)

all:	$(NAME)

fclean:	clean
	rm -f $(NAME)

clean:
		rm -f $(OBJ)

re:	fclean all
