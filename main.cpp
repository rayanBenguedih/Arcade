/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-pierre-jean.descarpentries
** File description:
** main
*/

#include <iostream>
#include "DLLoader.hpp"
#include "Core/ICore.hpp"
#include "Core/Core.hpp"

int execute_main_loop(std::string init_lib) // mettre dans le core
{
    std::string current_game_so = "";
    arcade::core::ICore *data = new arcade::core::Core(init_lib); // Créer un nouveau core et le feed de data faire un shared pointer

    data->start();
    delete data;
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "\033[91mError: The number of arguments isn't respected.\033[0m\nThis program need only \033[6mONE\033[0m argument." << std::endl;
        exit(84);   
    }

    try {
        void * handle = arcade::DL::DLLoader::open(av[1], RTLD_NOW);
        arcade::DL::DLLoader::close(handle);
        execute_main_loop(av[1]);
        exit(0);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        exit(84);
    }
}