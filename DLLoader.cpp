/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-pierre-jean.descarpentries
** File description:
** DlLoader
*/

#include "DLLoader.hpp"

using namespace arcade;
using namespace DL;

void *DLLoader::open(const std::string filename, int flag)
{
    void *tmp = dlopen(filename.c_str(), flag);
    
    if (tmp == NULL)
        throw std::invalid_argument(dlerror());
    return tmp;
}

void *DLLoader::sym(void *handle, std::string symbol)
{
    void *tmp = dlsym(handle, symbol.c_str());

    if (tmp == NULL)
        throw std::invalid_argument(dlerror());
    return tmp;
}

char *DLLoader::error(void)
{
    return dlerror();
}

int DLLoader::close(void *handle)
{
    int tmp = dlclose(handle);

    if (tmp != 0)
        throw std::invalid_argument(dlerror());
    return tmp;
}