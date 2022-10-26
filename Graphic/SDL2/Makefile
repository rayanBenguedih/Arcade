##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for project
##

SRC = 	LibSDL2.cpp \
		Sdl.cpp

OBJ = $(SRC:.cpp=.o)

NAME = arcade_sdl2.so


$(NAME): $(OBJ)
		g++ -c -Wall -Wextra -fpic $(SRC) -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
		g++ -shared -o ${NAME} -fPIC $(OBJ) -Wall -Wextra -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

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

