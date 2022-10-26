#ifndef libSFML
#define libSFML

#include <iostream>
#include <map>
#include <memory>

#include "../../Displayer/IDisplayer.hpp"
#include "../../Game/IGame.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class LibSFML : public arcade::displayer::IDisplayer {
    public:
        LibSFML();
        ~LibSFML() 
        {

        }

        void drawMenu(std::vector<std::string> gamesPaths, std::vector<std::string> displayersPaths);
        void drawGame(std::vector<std::string> map);
        
        void loadMenuAssets(std::string actualGamePath, std::vector<std::string> gameLibPath, std::vector<std::string> displayerlibPath);
        void loadGameAssets(std::string actualGamePath, std::vector<std::string> map);

        void destroyWindow(void);

        bool isRunning(void);

        arcade::KeyboardKeys getInput(void);
        std::string getName(void);

    protected:
        std::string _libName;
        bool _isRunning;

        int windowCreated;
        sf::RenderWindow window;
        sf::Font font;
        size_t police_size;

        sf::Event event;
        int musicLoaded;
        sf::Music music;

        arcade::KeyboardKeys _input;
        std::map<sf::Keyboard::Key, arcade::KeyboardKeys> _keys;
        std::vector<std::string> commands_names;
        size_t rand_val;
        std::string actualGame;

};

#endif /* !LIBSFML_HPP_ */