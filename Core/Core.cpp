#include "Core.hpp"

// ---------------------- CONSTRUCTORS ------------------------------

arcade::core::Core::Core() : ICore()
{
    gamesPaths = scanGames();
    graphicsPaths = scanDisplayers();

    // _games[gameIndex].update();
    // graphics[graphicIndex].drawGame(_games[gameIndex]); // Replace with struct data

    _games = game_loader(gamesPaths);
    graphics = lib_loader(libs_names);

    gameLoaded = -1;
    graphicLoaded = 0;
}

arcade::core::Core::Core(std::string first_lib) : ICore()
{
    gamesPaths = scanGames();
    graphicsPaths = scanDisplayers();

    _games = game_loader(gamesPaths);
    eraseSubStr(first_lib, "./");
    eraseSubStr(first_lib, "lib/arcade_");
    eraseSubStr(first_lib, ".so");
    // libs_names.push_back(first_lib);
    graphics = lib_loader(graphicsPaths);
    std::vector<std::string> libs_uniq;
    int dupi = 0;
    for (size_t i = 0; i < libs_names.size();) {
        if (dupi == 0) {
            libs_uniq.push_back(libs_names[i]);
        }
        i = i + 1;
        dupi = 0;
        for (size_t j = 0; j < libs_uniq.size() && i < libs_names.size(); j++) {
            if (libs_uniq[j] == libs_names[i])
                dupi = 1;
        }
    }
    libs_names = libs_uniq;
    gameLoaded = 0;
    graphicLoaded = 0;
    for (size_t i = 0; i < libs_names.size(); i++) {
        if (libs_names[i] == first_lib) {
            graphicLoaded = i;
            break;
        }
    }
}

// ----- QOL FUNCTIONS --------------------------------

void arcade::core::Core::eraseSubStr(std::string &mainStr, const std::string &toErase)
{
    // Search for the substring in string
    size_t pos = mainStr.find(toErase);
    if (pos != std::string::npos) {
        // If found then erase it from string
        mainStr.erase(pos, toErase.length());
    }
}

void arcade::core::Core::update(size_t gameIndex, size_t graphicIndex)
{
    gameIndex += 1;
    graphicIndex += 1;
    return;
}

// -------- FUNCTIONS THAT WILL SCAN LIB FOLDER -------


std::vector<std::string> arcade::core::Core::explore(void)
{
    std::vector <std::string> so_files;
    
    DIR *di;
    char *ptr1;
    char *ptr2;
    int retn;
    struct dirent *dir;

    di = opendir("./lib/");
    if (di)
    {
        while ((dir = readdir(di)) != NULL) 
        {
            ptr1=strtok(dir->d_name,".");
            ptr2=strtok(NULL,".");
            if(ptr2!=NULL)
            {
                retn=strcmp(ptr2,"so");
                if(retn==0)
                    so_files.push_back(std::string(ptr1));
            }
        }
    }
    closedir(di);
    return so_files;
}

std::vector <std::string> arcade::core::Core::clear_vectors(std::vector <std::string> vec)
{

    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i].find("arcade_") != std::string::npos) 
            eraseSubStr(vec[i], "arcade_");
        if (vec[i].find(".so") != std::string::npos) 
            eraseSubStr(vec[i], ".so");
    }
    return (vec);
}

std::vector <std::string> arcade::core::Core::fetch_libs_founds()
{
    std::vector <std::string> files = explore();

    std::vector <std::string> games_list;
    std::vector <std::string> libs_list;

    std::vector <std::string> to_ret;

    std::ifstream games_file("Content/games.txt");
    std::ifstream lib_file("Content/libs.txt");
    std::string line;

    while (getline(games_file, line))
        games_list.push_back(line);
    while (getline(lib_file, line))
        libs_list.push_back(line); 

    libs_list = clear_vectors(libs_list);
    games_list = clear_vectors(games_list);
    for (size_t i = 0; i < files.size(); i++) {
        if (files[i].find("arcade_") != std::string::npos) 
            eraseSubStr(files[i], "arcade_");
        if (files[i].find(".so") != std::string::npos) 
            eraseSubStr(files[i], ".so");
    }

    for (size_t i = 0; i < files.size(); i++) {
        for (size_t iter = 0; iter < libs_list.size(); iter++) {
            if (files[i] == libs_list[iter])
                to_ret.push_back(libs_list[iter]);
        }
        for (size_t iter = 0; iter < games_list.size(); iter++) {
            if (files[i] == games_list[iter])
                to_ret.push_back(games_list[iter]);
        }
    }
    return to_ret;
}


// --------- SCANNERS FOR GAMES ----------

std::vector<std::string> arcade::core::Core::scanGames()
{
    std::vector<std::string> files = explore();

    std::vector<std::string> games_list;

    std::vector<std::string> to_ret;

    std::ifstream games_file("Content/games.txt");
    std::string line;

    while (getline(games_file, line))
        games_list.push_back(line);

    for (size_t i = 0; i < files.size(); i++)
    {
        for (size_t iter = 0; iter < games_list.size(); iter++)
        {
            if (files[i] == games_list[iter])
                to_ret.push_back(games_list[iter]);
        }
    }
    return (to_ret);
}

// --------- SCANNERS FOR DISPLAYERS -------------------

std::vector<std::string> arcade::core::Core::scanDisplayers()
{
    std::vector<std::string> files = explore();

    std::vector<std::string> libs_list;

    std::vector<std::string> to_ret;

    std::ifstream libs_file("Content/libs.txt");
    std::string line;

    while (getline(libs_file, line))
        libs_list.push_back(line);

    for (size_t i = 0; i < files.size(); i++)
    {
        for (size_t iter = 0; iter < libs_list.size(); iter++) {
            if (files[i] == libs_list[iter])
                to_ret.push_back(libs_list[iter]);
        }
    }
    return (to_ret);
}

//  ---------- LIB LOADER ----------


std::shared_ptr<arcade::displayer::IDisplayer> arcade::core::Core::initDisplayer(std::string path) 
{
    std::string lib_path = "";

    lib_path += "./lib/arcade_";
    lib_path += path;
    lib_path += ".so";
    void *handle = arcade::DL::DLLoader::open(lib_path, RTLD_NOW);
   
    if (!handle)
        return (nullptr);
    std::shared_ptr<arcade::displayer::IDisplayer> (*func)(void) = (std::shared_ptr<arcade::displayer::IDisplayer> (*)(void)) arcade::DL::DLLoader::sym(handle, "entryPoint");

    std::shared_ptr<arcade::displayer::IDisplayer> my_shrd_lib = func();
    return (my_shrd_lib);
}

std::vector<std::shared_ptr<arcade::displayer::IDisplayer>> arcade::core::Core::lib_loader(std::vector<std::string> libs)
{
    std::vector<std::shared_ptr<arcade::displayer::IDisplayer>> all_libs;
    std::shared_ptr<arcade::displayer::IDisplayer> pts;
    int exist_already = 0;
    for (size_t i = 0; i < libs.size(); i++)
    {
        exist_already = 0;
        for (size_t i = 0; i < libs.size(); i++) {
            if (libs[i].find("arcade_") != std::string::npos) 
                eraseSubStr(libs[i], "arcade_");
            if (libs[i].find(".so") != std::string::npos) 
                eraseSubStr(libs[i], ".so");
        }   
        for (size_t j = 0; j < libs_names.size(); j++) {
            if (libs[i] == libs_names[j])
                exist_already = 1;
        }
        if (exist_already == 0) {
            pts = initDisplayer(libs[i]);
            if (pts != nullptr) {
                all_libs.push_back(pts);
                libs_names.push_back(libs[i]);
            }
        }
    }
    return (all_libs);
}

// --------- GAME LOADERS ---------------


std::shared_ptr<arcade::game::IGame> arcade::core::Core::initGame(std::string path)
{
    std::string game_path = "";

    game_path += "lib/arcade_";
    game_path += path;
    game_path += ".so";
    void *handle = arcade::DL::DLLoader::open(game_path, RTLD_NOW);

    if (!handle)
        return (nullptr);
    std::shared_ptr<arcade::game::IGame> (*func)(void) = (std::shared_ptr<arcade::game::IGame> (*)(void)) arcade::DL::DLLoader::sym(handle, "entryPoint");

    std::shared_ptr<arcade::game::IGame> my_shared_Game = func();
    return (my_shared_Game);
}

std::vector<std::shared_ptr<arcade::game::IGame>> arcade::core::Core::game_loader(std::vector<std::string> games) // mettre dans le core
{
    std::vector<std::shared_ptr<arcade::game::IGame>> all_games;
    std::shared_ptr<arcade::game::IGame> pts;

    for (size_t i = 0; i < games.size(); i++)
    {
        eraseSubStr(games[i], "arcade_");
        eraseSubStr(games[i], ".so");
        pts = initGame(games[i]);
        if (pts != nullptr)
        {
            all_games.push_back(pts);
            games_names.push_back(games[i]);
        }
    }
    return (all_games);
}

// ----------- START OF THE CORE ----------------




void arcade::core::Core::check_for_news()
{
    gm_bff = scanGames();
    lb_bff = scanDisplayers();
    gm_bff = clear_vectors(gm_bff);
    lb_bff = clear_vectors(lb_bff);
    size_t differ_gm = 1;
    size_t differ_lb = 1;
    std::shared_ptr<arcade::game::IGame> pts_g;
    std::shared_ptr<arcade::displayer::IDisplayer>  pts_l;

    for (size_t i = 0; i < gm_bff.size(); i++) {
        for (size_t j = 0; j < games_names.size(); j++) {
            if (gm_bff[i] == games_names[j])
                differ_gm = 0;
        }
        if (differ_gm == 1) {
            pts_g = initGame(gm_bff[i]);
            if (pts_g != nullptr) {
                games_names.push_back(gm_bff[i]);
                _games.push_back(pts_g);
            }
        }
    }
    for (size_t i = 0; i < lb_bff.size(); i++) {
        for (size_t j = 0; j < libs_names.size(); j++) {
            if (lb_bff[i] == libs_names[j])
                differ_lb = 0;
        }
        if (differ_lb == 1) {
            pts_l = initDisplayer(lb_bff[i]);
            if (pts_l != nullptr) {
                libs_names.push_back(lb_bff[i]);
                graphics.push_back(pts_l);
            }
        }
    }

    return;
}


void arcade::core::Core::check_for_less()
{
    size_t found = 0;

    for (size_t c = 0; c < games_names.size(); c++)  {
        for (size_t i = 0; i < gm_bff.size(); i++) {
            if (games_names[c] == gm_bff[i])
                found = 1;
        }
        if (found == 0) {
            invalid_games.push_back(c);
        }
        found = 0;
    }

    found = 0;
    for (size_t c = 0; c < libs_names.size(); c++)  {
        for (size_t i = 0; i < lb_bff.size(); i++) {
            if (libs_names[c] == lb_bff[i])
                found = 1;
        }
        if (found == 0) {
            invalid_libs.push_back(c);
        }
        found = 0;
    }
}


size_t arcade::core::Core::double_game_check(std::vector<size_t> invalid_values, size_t val, size_t maxSize)
{
    size_t to_ret = 0;
    if (val == 0) {
        val = val;
    }
    if (invalid_values.size() == maxSize)
        return (-1);
    for (size_t i = 0; i < invalid_values.size(); i++) {
        if (invalid_values[i] == to_ret) {
            to_ret += 1;
            i = 0;
        }
    }
    return (to_ret);
}
size_t arcade::core::Core::look_for_valid(std::vector<size_t> invalid_values, size_t val, size_t maxSize)
{
    if (invalid_values.size() == maxSize)
        return (-1);
    if ((int) val == -1)
        return (0);
    if (invalid_values.size() == 0)
        return (val);
    for (size_t i = 0; i < invalid_values.size(); i++) {
        if (val == invalid_values[i]) {
            i = 0;
            val += 1;
            if (val > maxSize)
                val = 0;
        }
    }
    return (val);
}

void arcade::core::Core::start(void)
{
    if (graphics.size() == 0)
        exit(0);

    // ---------- DISPLAY OF THE START TO GET PLAYER NAME --------------
    size_t incr = 0;
    for (size_t i = 0; i < 50; i++)
        std::cout << "-";
    std::cout << "\n";
    std::string padder = "";
    for (; incr < games_names.size(); incr++) {
        padder = "";
        std::cout << "|" << games_names[incr];
        for (size_t j = games_names[incr].size() + 1; j < 20; j++)
            padder += " ";
        padder += "|";
        std::cout << padder;
        if (incr < libs_names.size()) {
            padder = "";
            std::cout << libs_names[incr];
            for (size_t k = libs_names[incr].size(); k < 28; k++)
                padder += " ";
            padder += "|";
            std::cout << padder << "\n";
        } else
            std::cout << padder << "|\n";
    }

    for (; incr < libs_names.size(); incr++) {
        padder = "|";
        for (size_t i = 1; i < 20; i++)
            padder += " ";
        padder += "|";
        std::cout << padder << libs_names[incr];
        padder = "";
        for (size_t i = libs_names.size() + 3; i < 27; i++)
            padder += " ";
        padder += "|";
        std::cout << padder << "\n";
    }
    for (size_t i = 0; i < 50; i++)
        std::cout << "-";
    std::cout << "\nNo Score";
    std::cout << "\nPlease enter your name: ";
    std::string Player = "Anonymous (Edgy)";
    std::string tmp;
    std::cin >> tmp;

    if (tmp.size() >= 1)
        Player = tmp;
    std::vector<std::string> highScores;

    for (size_t i = 0; i < 150; i++)
        std::cout << "\n";

    // -------- YOU STARTED THE GAME BY ENTERING A NAME NOW LOADING ASSETS ---------------
    graphics[graphicLoaded]->loadMenuAssets("None", games_names, libs_names);
    graphics[graphicLoaded]->drawMenu(games_names, libs_names);
    int menu = 1;
    int game_started = 0; // Rester dans le menu tant qu'on a commencé aucun jeu
    int reload_gme = 1;
    std::string game_nms = "";
    std::vector<std::string> new_map;
    int reload_mne = 0;
    int game_over = 0;
    std::ofstream myFile;

    myFile.open("highScore.txt", std::ios_base::app);
    if (!myFile.is_open()) {
        std::ofstream myFile("highScore.txt");
    } else
        myFile << "\n\n";
    myFile << Player + "'s high scores are:\n";
    while (graphics[graphicLoaded]->isRunning()) {
        invalid_games.clear();
        invalid_libs.clear();
        check_for_news();
        check_for_less();
        if (lb_bff.size() == 0)
            exit(0);
        graphicLoaded = look_for_valid(invalid_libs, graphicLoaded, graphics.size());
        for (size_t i = 0; i < invalid_libs.size(); i++) {
            graphics[invalid_libs[i]]->destroyWindow();
        }
        command = graphics[graphicLoaded]->getInput();
    
        // ------- VERIFICATION INPUT CORE ---------
        if (menu == 1) {
            if (command == arcade::NUMBER_1) {
                graphics[graphicLoaded]->destroyWindow();
                reload_gme = 1;
                reload_mne = 1;
                if (graphicLoaded > 0)
                    graphicLoaded -= 1;
                else
                    graphicLoaded = graphics.size() - 1;
            } else if (command == arcade::NUMBER_2) {
                graphics[graphicLoaded]->destroyWindow();
                reload_gme = 1;
                reload_mne = 1;
                if (graphicLoaded < graphics.size() - 1) 
                    graphicLoaded += 1;
                else
                    graphicLoaded = 0;
            } else if (command == arcade::NUMBER_4) {
                reload_gme = 1;
                reload_mne = 1;
                if (gameLoaded > 0)
                    gameLoaded -= 1;
                else
                    gameLoaded = _games.size() - 1;
            } else if (command == arcade::NUMBER_5) {
                reload_gme = 1;
                reload_mne = 1;
                if ( (size_t) gameLoaded < _games.size() - 1)
                    gameLoaded += 1;
                else
                    gameLoaded = 0;
            } else if (command == arcade::NUMBER_0) {
                std::cout << "Thanks for playing with us " + Player + "! Your highscore in the following games are:\n";
                for(size_t i = 0; i < _games.size(); i++) {
                    highScores.push_back(games_names[i] + ": " + _games[i]->getDatas()[0]);
                }
                for (size_t i = 0; i < highScores.size(); i++) {
                    std::cout << highScores[i] << "\n";
                    myFile << highScores[i] + "\n";
                }
                myFile.close();
                std::cout << "\nWe hope to see you again soon!\n";
                for (size_t i = 0; i < graphics.size(); i++)
                    graphics[i]->destroyWindow();
                exit(0);
            } else if (command == arcade::KEY_L) {
                game_started = 1;
                menu = 0;
            }
        } else {
            if (command == arcade::NUMBER_1) {
                graphics[graphicLoaded]->destroyWindow(); 
                reload_gme = 1;
                reload_mne = 1;
                if (graphicLoaded > 0)
                    graphicLoaded -= 1;
                else
                    graphicLoaded = graphics.size() - 1;
            } else if (command == arcade::NUMBER_2) {
                graphics[graphicLoaded]->destroyWindow();
                reload_gme = 1;
                reload_mne = 1;
                if (graphicLoaded < graphics.size() - 1) 
                    graphicLoaded += 1;
                else
                    graphicLoaded = 0;
            }   else if (command == arcade::NUMBER_4) {
                reload_gme = 1;
                reload_mne = 1;
                if (gameLoaded > 0)
                    gameLoaded -= 1;
                else
                    gameLoaded = _games.size() - 1;
            } else if (command == arcade::NUMBER_5) {
                reload_gme = 1;
                reload_mne = 1;
                if ( (size_t) gameLoaded < _games.size() - 1)
                    gameLoaded += 1;
                else
                    gameLoaded = 0;
            } else if (command == arcade::NUMBER_0) {
                std::cout << "Thanks for playing with us " + Player + "! Your highscores in the following games are:\n";
                for(size_t i = 0; i < _games.size(); i++) {
                    highScores.push_back(games_names[i] + ": " + _games[i]->getDatas()[0]);
                }
                for (size_t i = 0; i < highScores.size(); i++) {
                    std::cout << highScores[i] << "\n";
                    myFile << highScores[i] + "\n";
                }
                myFile.close();
                std::cout << "\nWoah you left in the middle of the game?! We hope you didn't get angry! See you soon!\n";
                for (size_t i = 0; i < graphics.size(); i++)
                    graphics[i]->destroyWindow();
                exit(0);
            } 
        }
        if (command == arcade::KEY_M) {
            if (libs_names[graphicLoaded] == "ncurses")
                graphics[graphicLoaded]->destroyWindow();
            graphicLoaded = look_for_valid(invalid_libs, graphicLoaded, graphics.size());
            graphics[graphicLoaded]->drawMenu(gm_bff, lb_bff);
            game_started = 0;
            menu = 1;
        }

        // ---------- VERIFICATION SI ON PEUT JOUER AU JEU -------------
        if (_games.size() > 0)
            game_nms = games_names[gameLoaded];
        if (game_started == 1 && _games.size() > 0 && menu == 0) {
            if (_games.size() != 0) {
                graphicLoaded = look_for_valid(invalid_libs, graphicLoaded, graphics.size());
                gameLoaded = look_for_valid(invalid_games, gameLoaded, _games.size());
                if ((size_t)gameLoaded >= _games.size()) {
                    gameLoaded = double_game_check(invalid_games, gameLoaded, _games.size());
                }
                if ((size_t)gameLoaded < _games.size() && gameLoaded != -1 && _games[gameLoaded]->getDatas().size() >= 3) {
                if (gameLoaded != -1 && game_over == 0 ) {
                    new_map = _games[gameLoaded]->getDatas();
                    new_map[0] = Player + " " +  _games[gameLoaded]->getDatas()[0];
                    if (reload_gme == 1) {
                        graphics[graphicLoaded]->loadGameAssets(games_names[gameLoaded], new_map);
                        reload_gme = 0;
                    }
                    graphics[graphicLoaded]->drawGame(new_map);
                    _games[gameLoaded]->setInput(command);
                    _games[gameLoaded]->update();
                } else {
                    game_started = 0;
                    menu = 1;
                    graphicLoaded = look_for_valid(invalid_libs, graphicLoaded, graphics.size());
                    if (reload_mne == 1) {

                        if (libs_names[graphicLoaded] == "ncurses")
                            graphics[graphicLoaded]->destroyWindow();
                        if (games_names.size() == 0)
                            game_nms = "No games";
                        else
                            game_nms = games_names[gameLoaded];
                        graphics[graphicLoaded]->loadMenuAssets(game_nms, games_names, libs_names);
                        reload_mne = 0;
                    }
                    graphics[graphicLoaded]->drawMenu(gm_bff, lb_bff);
                }
                if (_games[gameLoaded]->getDatas()[1] == "0") {
                        // highScores.push_back(game_nms + _games[gameLoaded]->getDatas()[0]);
                        game_over = 1;
                    } else
                        game_over = 0;
                } else {
                    game_started = 0;
                    gameLoaded = 0;
                }
            } else
                game_started = 0;
        } else {
            game_started = 0;
            menu = 1;
            graphicLoaded = look_for_valid(invalid_libs, graphicLoaded, graphics.size());
            if (libs_names[graphicLoaded] == "ncurses")
                graphics[graphicLoaded]->destroyWindow();
            if (reload_mne == 1) {
                if (games_names.size() == 0)
                    game_nms = "No games";
                else
                    game_nms = games_names[gameLoaded];
                graphics[graphicLoaded]->loadMenuAssets(game_nms, games_names, libs_names);
                reload_mne = 0;
            }
            graphics[graphicLoaded]->drawMenu(gm_bff, lb_bff);
        }
        command = arcade::NONE;
        if (lb_bff.size() == 0)
            exit (0);
        graphicLoaded = look_for_valid(invalid_libs, graphicLoaded, graphics.size());
    }
}
