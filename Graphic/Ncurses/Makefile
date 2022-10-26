##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for project
##

SRC = 	Ncurses.cpp \
		LibNcurses.cpp

OBJ = $(SRC:.cpp=.o)

NAME = arcade_ncurses.so


$(NAME): $(OBJ)
		g++ -c -Wall -Wextra -fpic $(SRC) -lncurses -ltinfo -Wl,-E
		g++ -shared -o ${NAME} -fPIC $(OBJ) -Wall -Wextra -lncurses -ltinfo -Wl,-E

all:     $(NAME)
		 mv ${NAME} ../../lib/

clean:
		rm -f $(OBJ)
		rm -f ${NAME}
		rm -f ../../lib/${NAME}

fclean: clean

re:     fclean all

valgrind:
	valgrind ./$(NAME) --leak-check=full

# export LD_PRELOAD=/home/canopus/Epitech/B-PSU-400-LIL-4-1-malloc-rayan.benguedih/libmy_malloc.so

