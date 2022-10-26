##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for project
##

SRC = 	../../AGame.cpp \
		nibbler.cpp

OBJ = $(SRC:.cpp=.o)

NAME = arcade_nibbler.so


$(NAME): $(OBJ)
		g++ -c -Wall -Wextra -fPIC $(SRC)
		g++ -shared -o $(NAME) -Wall -Wextra -fPIC  $(OBJ)

all:     $(NAME)
		 mv ${NAME} ../../../lib/

clean:
		rm -f $(OBJ)
		rm -f ${NAME}
		rm -f ../../../lib/${NAME}
		rm -f AGame.o

fclean: clean

re:     fclean all

valgrind:
	valgrind ./$(NAME) --leak-check=full

# export LD_PRELOAD=/home/canopus/Epitech/B-PSU-400-LIL-4-1-malloc-rayan.benguedih/libmy_malloc.so

