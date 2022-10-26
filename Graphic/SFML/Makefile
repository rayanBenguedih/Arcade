##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for project
##

SRC = 	libSFML.cpp

OBJ = $(SRC:.cpp=.o)

NAME = arcade_sfml.so


$(NAME): $(OBJ)
		g++ -c -Wall -Wextra -fpic $(SRC) -lsfml-window -lsfml-graphics -lsfml-audio
		g++ -shared -o ${NAME} -fPIC $(OBJ) -Wall -Wextra -lsfml-window -lsfml-graphics -lsfml-audio

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

