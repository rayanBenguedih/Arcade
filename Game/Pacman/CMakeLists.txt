cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(arcade LANGUAGES CXX)

#

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../lib/)

set(LIB_NAME arcade_pacman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_library(
    ${LIB_NAME} SHARED
    ${PROJECT_SOURCE_DIR}/src/pacman.cpp
    ${PROJECT_SOURCE_DIR}/include/pacman.hpp
    ${PROJECT_SOURCE_DIR}/../AGame.hpp
    ${PROJECT_SOURCE_DIR}/../AGame.cpp
    ${PROJECT_SOURCE_DIR}/../IGame.hpp
)

target_include_directories(
    ${LIB_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}../
    ${PROJECT_SOURCE_DIR}/include/
)

set_target_properties(${LIB_NAME} PROPERTIES PREFIX "")
#
