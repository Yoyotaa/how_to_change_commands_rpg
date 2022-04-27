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
			src/update_settings.c \
			src/process_change_commands.c \
			src/engine/create_object.c \
			src/engine/init_font.c \
			src/engine/input_manager.c \

BIN		=	change_commands

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-I./includes

LFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(OBJ)
		$(CC) $(OBJ) -o $(BIN) $(LFLAGS)
		make clean

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(BIN)

re:		fclean all clean
