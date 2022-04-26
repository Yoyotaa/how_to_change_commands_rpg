##
## EPITECH PROJECT, 2021
## ...
## File description:
## Makefile
##

CC		=	gcc

SRC		=	start.c \
			update_game.c \
			update_menu.c \
			lib/create_object.c \

BIN		=	change_commands

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-I./includes

LFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

WFLAGS	=	-W -Werror -Wall -Wextra

LPATH	=	-C lib/my

all:	mylib $(OBJ)
		$(CC) $(OBJ) -o $(BIN) $(LFLAGS) -L./lib/my -lmy
		make clean

mylib:
		make $(LPATH)

clean:
		make clean $(LPATH)
		rm -f $(OBJ)

fclean:	clean
		make fclean $(LPATH)
		rm -f $(BIN)

re:		fclean all clean
