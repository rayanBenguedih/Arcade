#pragma once

#include <vector>
#include <string>

namespace arcade {

    enum KeyboardKeys
    {
        NONE,
        KEY_A,
        KEY_B,
        KEY_C,
        KEY_D,
        KEY_E,
        KEY_F,
        KEY_G,
        KEY_H,
        KEY_I,
        KEY_J,
        KEY_K,
        KEY_L,
        KEY_M,
        KEY_N,
        KEY_O,
        KEY_P,
        KEY_Q,
        KEY_R,
        KEY_S,
        KEY_T,
        KEY_U,
        KEY_V,
        KEY_W,
        KEY_X,
        KEY_Y,
        KEY_Z,
        ARROW_R,
        ARROW_U,
        ARROW_D,
        ARROW_L,
        NUMBER_1,
        NUMBER_2,
        NUMBER_3,
        NUMBER_4,
        NUMBER_5,
        NUMBER_6,
        NUMBER_7,
        NUMBER_8,
        NUMBER_9,
        NUMBER_0,
    };

    namespace displayer {
        class IDisplayer;
    }

}

#include "../Game/IGame.hpp"

namespace arcade
{
    namespace displayer
    {
        class IDisplayer
        {
            public:
                virtual ~IDisplayer() = default;

                virtual void drawMenu(std::vector<std::string> gamesPaths, std::vector<std::string> displayersPaths) = 0;
                virtual void drawGame(std::vector<std::string> map) = 0;
                virtual void loadMenuAssets(std::string actualGamePath, std::vector<std::string> gameLibPath, std::vector<std::string> displayerlibPath) = 0;
                virtual void loadGameAssets(std::string actualGamePath, std::vector<std::string> map) = 0;

                virtual void destroyWindow(void) = 0;

                virtual bool isRunning() = 0;

                virtual KeyboardKeys getInput() = 0;
        };
    };
};