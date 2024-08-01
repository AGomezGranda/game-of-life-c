cmake_minimum_required(VERSION 3.28)
project(game_of_life_c C)

set(CMAKE_C_STANDARD 23)

add_executable(game_of_life_c main.c
        maps.c
        maps.h)
