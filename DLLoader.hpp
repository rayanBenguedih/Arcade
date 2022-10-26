/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-pierre-jean.descarpentries
** File description:
** DlLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <iostream>
#include <dlfcn.h>

namespace arcade {

    namespace DL {
        
        class DLLoader {
            public:
                static void *open(const std::string, int);
                static void *sym(void *, std::string);
                static char *error(void);
                static int close(void *);
        };
    };
};

#endif /* !DLLOADER_HPP_ */