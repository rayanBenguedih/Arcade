##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for project
##

SRC =	main.cpp 		\
		Core/Core.cpp 	\
		DLLoader.cpp 	\


OBJ = $(SRC:.cpp=.o)

NAME = arcade

all:     $(NAME)

${NAME}:

		g++ -o $(NAME) $(SRC) -Wall -Wextra -ldl -Wl,-E
		make -C Game/Nibbler/src all
		make -C Game/Pacman/src all
		make -C Graphic/Ncurses all
		make -C Graphic/SDL2 all
		make -C Graphic/SFML/ all

clean:
		rm -f $(OBJ)
		rm -f $(NAME)
		make -C Graphic/Ncurses clean
		make -C Graphic/SDL2 clean
		make -C Game/Nibbler/src clean
		make -C Graphic/SFML/ clean
		make -C Game/Pacman/src clean

fclean: clean
		rm -f $(NAME)
		make -C Graphic/Ncurses fclean
		make -C Graphic/SDL2 fclean
		make -C Game/Nibbler/src fclean
		make -C Graphic/SFML/ fclean
		make -C Game/Pacman/src fclean

core:
		g++ -o $(NAME) $(SRC) -Wall -Wextra -ldl -Wl,-E

games:
		make -C Game/Nibbler/src all
		make -C Game/Pacman/src all

graphicals:
		make -C Graphic/Ncurses all
		make -C Graphic/SDL2 all
		make -C Graphic/SFML/ all


decompress:
		./install.sh

sfml-test:
	g++ -c $(SRC)
	g++ $(OBJ) -o $(NAME) -lsfml-graphics -lsfml-window -lsfml-system -lncurses

sfml-test-path:
	g++ -c $(SRC) -I../SFML-2.5.1/include -Wall -Wextra
	g++ $(OBJ) -o $(NAME) -L../SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lncurses -Wall -Wextra

re:     fclean all

core:
	g++ -o $(NAME) $(SRC) -Wall -Wextra -ldl -Wl,-E

games:

graphicals:
	make -C Graphic/Ncurses all

.PHONY: all clean fclean re
