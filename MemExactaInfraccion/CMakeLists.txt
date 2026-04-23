cmake_minimum_required(VERSION 4.0)
project(MemExactaInfraccion)

set(CMAKE_CXX_STANDARD 20)

add_executable(MemExactaInfraccion main.cpp
        MiBiblioteca/Memoria.cpp
        MiBiblioteca/Memoria.h
        MiBiblioteca/Conductores.h
        MiBiblioteca/Faltas.h)
