cmake_minimum_required(VERSION 4.0)
project(projet_match C)

set(CMAKE_C_STANDARD 99)

add_executable(projet_match main.c
        initialiser.c
        initialiser.h
        matrice.c
        matrice.h
        affichage.c
        affichage.h)
