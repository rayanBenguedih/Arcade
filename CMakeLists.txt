cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(arcade LANGUAGES CXX)

set(EXECUTABLE_OUTPUT_PATH ..)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -ldl -fno-gnu-unique")

add_subdirectory(./Graphic/Ncurses/)
add_subdirectory(./Graphic/SDL2/)
add_subdirectory(./Graphic/SFML/)

add_subdirectory(./Game/Nibbler/)
add_subdirectory(./Game/Pacman/)

add_executable(${PROJECT_NAME} main.cpp DLLoader.cpp DLLoader.hpp ./Core/Core.cpp)
