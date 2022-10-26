cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(arcade LANGUAGES CXX)

#

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../lib/)

set(LIB_NAME arcade_sdl2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer")

add_library(
    ${LIB_NAME} SHARED
    ${PROJECT_SOURCE_DIR}/Sdl.cpp
    ${PROJECT_SOURCE_DIR}/Sdl.hpp
    ${PROJECT_SOURCE_DIR}/LibSDL2.cpp
    ${PROJECT_SOURCE_DIR}/LibSDL2.hpp
    ${PROJECT_SOURCE_DIR}/../../Core/Core.hpp
    ${PROJECT_SOURCE_DIR}/../../Displayer/IDisplayer.hpp
    ${PROJECT_SOURCE_DIR}/../../Game/IGame.hpp
)

target_include_directories(
    ${LIB_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/../../Displayer/
    ${PROJECT_SOURCE_DIR}/../../Game/
    ${PROJECT_SOURCE_DIR}/../../Core
)

set_target_properties(${LIB_NAME} PROPERTIES PREFIX "")
#