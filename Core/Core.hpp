#include "ICore.hpp"

namespace arcade
{
    namespace core
    {
        class Core : public ICore
        { 
            protected: // variable en protected
           // Will be initialized by loaders
            std::vector<std::string> games_names;
            std::vector<std::string> libs_names;
           
           // needs to be initialized
            std::vector<std::shared_ptr<arcade::game::IGame>> _games;
            std::vector<std::shared_ptr<arcade::displayer::IDisplayer>> graphics;

            // Init with scanners
            std::vector<std::string> gamesPaths;
            std::vector<std::string> graphicsPaths;


            std::vector<std::string> gm_bff;
            std::vector<std::string> lb_bff;


            std::vector<size_t> invalid_games;
            std::vector<size_t> invalid_libs;

            int gameLoaded;      //Représente l'index du jeu actuellement chargé (à utilisé avec les vecteurs au-dessus)
            size_t graphicLoaded;   //Représente l'index de la lib graphique actuellement chargé (à utilisé avec les vecteurs au-dessus)

            arcade::KeyboardKeys command;

            public:
            Core();
            Core (std::string first_lib);

            void eraseSubStr(std::string &mainStr, const std::string &toErase);

            void update(size_t gameIndex, size_t graphicIndex);

            void start();

            // ---- SCANS ALL FILES IN ./lib
            std::vector<std::string> explore();
            std::vector <std::string> clear_vectors(std::vector <std::string> vec);
            std::vector <std::string> fetch_libs_founds();

            // ------ SCANNERS FOR GAMES AND DISPLAYERS .SO IN /LIB --------
            std::vector<std::string> scanGames();
            std::vector<std::string> scanDisplayers();

            // ---- LOADERS AND INITIALISERS FOR GAMES AND DISLPAYERS WILL CALL ENTRYPOINT -------
            std::vector<std::shared_ptr<arcade::displayer::IDisplayer>> lib_loader(std::vector<std::string> libs);
            std::shared_ptr<arcade::displayer::IDisplayer> initDisplayer(std::string path);
            std::vector<std::shared_ptr<arcade::game::IGame>> game_loader(std::vector<std::string> games);
            std::shared_ptr<arcade::game::IGame> initGame(std::string path);

            // ----- WILL RELOAD THE LIST OF ALL .SO LIBS AND WILL CHECK IF ANY NEW----
            void check_for_news();
            void check_for_less();
            size_t look_for_valid(std::vector<size_t> invalid_values, size_t val, size_t maxSize);

            size_t double_game_check(std::vector<size_t> invalid_values, size_t val, size_t maxSize);
            ~Core()
            {

            }
        };
    };
};