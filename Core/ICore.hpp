#pragma once

#include <string>
#include <memory>
#include <vector>
#include <sys/types.h>
#include <dirent.h> // Utiliser autre chose c++ permet de le faire
#include <string.h>
#include <fstream>
#include <iostream>

#include "../Displayer/IDisplayer.hpp"
#include "../DLLoader.hpp"

namespace arcade
{
    namespace core
    {
        class ICore
        {
            public:
                virtual ~ICore() = default;

                virtual std::shared_ptr<arcade::displayer::IDisplayer> initDisplayer(std::string path) = 0;
                virtual std::shared_ptr<arcade::game::IGame> initGame(std::string path) = 0;

                virtual std::vector<std::string> scanDisplayers() = 0;
                virtual std::vector<std::string> scanGames() = 0;

                virtual void update(size_t gameIndex, size_t displayerIndex) = 0;
                virtual void start() = 0;
        };
    };
};
