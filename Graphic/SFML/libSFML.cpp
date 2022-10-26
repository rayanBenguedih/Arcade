#include "libSFML.hpp"

    LibSFML::LibSFML()
        {
            font.loadFromFile("Assets/arcade.ttf");
            police_size = 24;
            windowCreated = 0;
            _keys.insert({sf::Keyboard::A, arcade::KEY_A});
            _keys.insert({sf::Keyboard::B, arcade::KEY_B});
            _keys.insert({sf::Keyboard::C, arcade::KEY_C});
            _keys.insert({sf::Keyboard::D, arcade::KEY_D});
            _keys.insert({sf::Keyboard::E, arcade::KEY_E});
            _keys.insert({sf::Keyboard::F, arcade::KEY_F});
            _keys.insert({sf::Keyboard::G, arcade::KEY_G});
            _keys.insert({sf::Keyboard::H, arcade::KEY_H});
            _keys.insert({sf::Keyboard::I, arcade::KEY_I});
            _keys.insert({sf::Keyboard::J, arcade::KEY_J});
            _keys.insert({sf::Keyboard::K, arcade::KEY_K});
            _keys.insert({sf::Keyboard::L, arcade::KEY_L});
            _keys.insert({sf::Keyboard::M, arcade::KEY_M});
            _keys.insert({sf::Keyboard::N, arcade::KEY_N});
            _keys.insert({sf::Keyboard::O, arcade::KEY_O});
            _keys.insert({sf::Keyboard::P, arcade::KEY_P});
            _keys.insert({sf::Keyboard::Q, arcade::KEY_Q});
            _keys.insert({sf::Keyboard::R, arcade::KEY_R});
            _keys.insert({sf::Keyboard::S, arcade::KEY_S});
            _keys.insert({sf::Keyboard::T, arcade::KEY_T});
            _keys.insert({sf::Keyboard::U, arcade::KEY_U});
            _keys.insert({sf::Keyboard::V, arcade::KEY_V});
            _keys.insert({sf::Keyboard::W, arcade::KEY_W});
            _keys.insert({sf::Keyboard::X, arcade::KEY_X});
            _keys.insert({sf::Keyboard::Y, arcade::KEY_Y});
            _keys.insert({sf::Keyboard::Z, arcade::KEY_Z});
            _keys.insert({sf::Keyboard::Num0, arcade::NUMBER_0});
            _keys.insert({sf::Keyboard::Num1, arcade::NUMBER_1});
            _keys.insert({sf::Keyboard::Num2, arcade::NUMBER_2});
            _keys.insert({sf::Keyboard::Num3, arcade::NUMBER_3});
            _keys.insert({sf::Keyboard::Quote, arcade::NUMBER_4});
            _keys.insert({sf::Keyboard::Num5, arcade::NUMBER_5});
            _keys.insert({sf::Keyboard::Num6, arcade::NUMBER_6});
            _keys.insert({sf::Keyboard::Num7, arcade::NUMBER_7});
            _keys.insert({sf::Keyboard::Num8, arcade::NUMBER_8});
            _keys.insert({sf::Keyboard::Num9, arcade::NUMBER_9});
            _keys.insert({sf::Keyboard::Up, arcade::ARROW_U});
            _keys.insert({sf::Keyboard::Down, arcade::ARROW_D});
            _keys.insert({sf::Keyboard::Left, arcade::ARROW_L});
            _keys.insert({sf::Keyboard::Right, arcade::ARROW_R});
            _isRunning = false;
            _libName = "SFML";
            _input = arcade::NONE;
            commands_names.push_back("Change Graphics");
            commands_names.push_back("   Previous   \t:1");
            commands_names.push_back("   Next       \t:2");
            commands_names.push_back("Change Games");
            commands_names.push_back("   Previous   \t:4");
            commands_names.push_back("   Next       \t:5");
            commands_names.push_back("LEAVE THE PROGRAM :0");
            commands_names.push_back("\nIN THE MENU PRESS \'L\' TO START THE FIRST GAME");
            rand_val = 0;
            musicLoaded = 0;
        }

void LibSFML::drawMenu(std::vector<std::string> gamesPaths, std::vector<std::string> displayersPaths)
{
    if (windowCreated == 0) {
        window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width,  sf::VideoMode::getDesktopMode().height), "SFML Arcade");
        windowCreated = 4;
    }
    
    sf::Event event;
    std::vector<sf::Text> game_texts;
    std::vector<sf::Text> libs_texts;
    std::vector<sf::Color> all_colors = {sf::Color::Blue, sf::Color::Green, sf::Color::Yellow, sf::Color::Red, sf::Color::Black};
    std::vector<sf::Color> txt_clrs = {sf::Color::Blue, sf::Color::Green, sf::Color::Yellow, sf::Color::Red, sf::Color::Black, sf::Color::Magenta, sf::Color::Cyan, sf::Color::White};
    std::vector<sf::Text> commands;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    int pic = 0;


    if (musicLoaded == 0) {

        if (music.openFromFile("Assets/NGYU_music.ogg")) {
            music.play();
            music.setLoop(true);
        }
        musicLoaded = 1;
    }
    if (!image.loadFromFile("Assets/SFMLmenu.jpg")) {
       pic = 0;
    } else
        pic = 1;
    if (pic == 1) {
        texture.loadFromImage(image);
        sprite.setTexture(texture); 
    }
    for (std::size_t i = 0; i < commands_names.size(); i++) {
        sf::Text text;
        text.setFont(font);
        text.setString(commands_names[i]);
        text.setCharacterSize(police_size);
        text.setPosition(window.getSize().x / 5 - text.getGlobalBounds().width / 5 - 120, window.getSize().y / 5 + police_size * i);
        commands.push_back(text);
    }

    for (std::size_t i = 0; i != gamesPaths.size(); i++) {
        sf::Text text;
        text.setFont(font);
        text.setString(gamesPaths[i]);
        text.setCharacterSize(police_size);
        if (gamesPaths[i] == actualGame)
            text.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255));
        else
            text.setFillColor(sf::Color::White);
        text.setPosition(sf::Vector2f(window.getSize().x / 2 - text.getGlobalBounds().width / 2 - 230, window.getSize().y / 2 + police_size * i - 300));
        game_texts.push_back(text);
    }

    for (std::size_t i = 0; i != displayersPaths.size(); i++) {
        sf::Text text;
        text.setFont(font);
        text.setString(displayersPaths[i]);
        text.setCharacterSize(police_size);
        if (displayersPaths[i] == "sfml")
            text.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255));
        else
            text.setFillColor(sf::Color::White);
        text.setPosition(sf::Vector2f(window.getSize().x / 2 - text.getGlobalBounds().width / 2 + 700, window.getSize().y / 2 + police_size * i + gamesPaths.size() * police_size - 250));
        libs_texts.push_back(text);
    }

    window.clear(all_colors[rand_val]);
    if (pic == 1)
        window.draw(sprite);
    for (size_t i = 0; i < game_texts.size(); i++) {
        game_texts[i].move(20.f * i + 150.f, 0);
        window.draw(game_texts[i]);
    }
    for (size_t i = 0; i < libs_texts.size(); i++) {
        libs_texts[i].move(0, 20.f * i + 150.f);
        window.draw(libs_texts[i]);
    }

    for (size_t i = 0; i < commands.size(); i++) {
        commands[i].move(0, 20.f * i + 10.f);
        commands[i].setFillColor(sf::Color::White);
        window.draw(commands[i]);
    }

    window.display();

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (this->_keys.count(event.key.code)) {
                _input = _keys.at(event.key.code);
            }
        }
    }
}

arcade::KeyboardKeys LibSFML::getInput(void)
{
    arcade::KeyboardKeys keys;
    keys = _input;
    _input = arcade::NONE;
    return keys;
}

void LibSFML::drawGame(std::vector<std::string> Oldmap)
{

    sf::Image image;
    sf::Texture texture;
    std::vector<std::string> map;
    

    if (musicLoaded == 0) {

        if (music.openFromFile("Assets/NGYU_music.ogg")) {
            music.play();
            music.setLoop(true);
        }
        musicLoaded = 1;
    }
    for (size_t i = 0; i < Oldmap.size(); i++) {
        map.push_back(Oldmap[i]);
        for (size_t j = 0; j < Oldmap[i].size(); j++) {
            if (Oldmap[i][j] == 'o' && i != 0)
                map[i][j] = '.';
        }
    }
    sf::Sprite sprite;
    police_size = 16;
// make a clock so that the function refreshes every 0.01s
    sf::Clock clock;
    int pic = 0;
    sf::Time t2 = sf::milliseconds(100);
    while (clock.getElapsedTime() < t2);
    clock.restart();
    if (windowCreated == 0) {
        window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width,  sf::VideoMode::getDesktopMode().height), "SFML Arcade");
        windowCreated = 4;
    }
    if (!image.loadFromFile("Assets/GamingSFML.jpg")) {
        pic = 0;
    } else
        pic = 1;
    if (pic == 1) {
        texture.loadFromImage(image);
        sprite.setTexture(texture); 
    }
    std::vector<sf::Text> game_map;
    for (size_t i = 0; i < map.size(); i++) {
        sf::Text text;
        text.setFont(font);
        text.setString(map[i]);
        text.setCharacterSize(police_size);
        text.setFillColor(sf::Color::White);
        text.setPosition(sf::Vector2f(window.getSize().x / 7 - text.getGlobalBounds().width / 10 + 100, window.getSize().y / 10 + police_size * i - 20));
        game_map.push_back(text);
    }
    if (game_map.size() > 2) {
    game_map[0].setString("Score:" + map[0]);

    game_map[1].setString("HP:" + map[1]);
    game_map[0].move(20.f, 0);
    game_map[1].move(20.f, 0);

    }
    window.clear(sf::Color::Black);
    if (pic == 1)
        window.draw(sprite);
    // Draw an SFML black rectangle around the map
    sf::RectangleShape rect(sf::Vector2f(window.getSize().x / 10 * 7, window.getSize().y / 10 * 10));
    rect.setFillColor(sf::Color::Black);
    rect.setPosition(sf::Vector2f(window.getSize().x / 10 +80, window.getSize().y / 10  - 20));
    window.draw(rect);
    if (game_map.size() > 2) {
        window.draw(game_map[0]);
        window.draw(game_map[1]);
    }
    for (size_t i = 2; i < map.size(); i++) {
        game_map[i].move(80.f, 80.f + (i - 1) * 10);
        window.draw(game_map[i]);
    }

    window.display();

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (this->_keys.count(event.key.code))
                _input = _keys.at(event.key.code);
        }
    }

}

void LibSFML::destroyWindow(void)
{
    window.close();
    windowCreated = 0;
    music.stop();
    musicLoaded = 0;
}


void LibSFML::loadMenuAssets(std::string actualGamePath, std::vector<std::string> gameLibPath, std::vector<std::string> displayerlibPath)
{

    actualGame = "";

    for (size_t i = 0; i < actualGamePath.size(); i++) {
        actualGame += tolower(actualGamePath[i]);
    }
    if (actualGamePath.empty() || gameLibPath.empty() || displayerlibPath.empty())
        return;
}
void LibSFML::loadGameAssets(std::string actualGamePath, std::vector<std::string> map)
{
    if (actualGamePath.empty() || map.empty())
        return;

}

bool LibSFML::isRunning()
{
    return window.isOpen();
}


std::string LibSFML::getName(void)
{
    return "LibSFML";
}

extern "C" std::shared_ptr<LibSFML> entryPoint(void)
{
    return std::make_shared<LibSFML>();
}