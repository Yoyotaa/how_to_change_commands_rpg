##
## EPITECH PROJECT, 2021
## ...
## File description:
## Makefile
##

CC		=	gcc

SRC		=	main.c \

BIN		=	change_commands

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-I./includes

WFLAGS	=	-W -Werror -Wall -Wextra

TFLAGS	=	-lcriterion

LPATH	=	-C lib/my

all:	mylib $(OBJ)
		$(CC) $(OBJ) -o $(BIN) -L./lib/my -lmy

mylib:
		make $(LPATH)

w:		mylib $(OBJ)
		$(CC) $(OBJ) -o $(BIN) $(WFLAGS) -L./lib/my -lmy

clean:
		make clean $(LPATH)
		rm -f $(OBJ)

fclean:	clean
		make fclean $(LPATH)
		rm -f $(BIN)

re:		fclean all
