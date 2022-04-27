##
## EPITECH PROJECT, 2021
## ...
## File description:
## Makefile
##

CC		=	gcc

SRC		=	src/start.c \
			src/update_game.c \
			src/update_menu.c \
			lib/create_object.c \
			src/check_collision.c \
			src/hover_actions.c \
			src/update_settings.c \
			src/process_change_commands.c \
			src/init_font.c \

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
