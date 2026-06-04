cmake_minimum_required(VERSION 4.0)
project(HerPlatos)

set(CMAKE_CXX_STANDARD 20)

add_executable(HerPlatos main.cpp
        Biblioteca/Producto.cpp
        Biblioteca/Producto.h
        Biblioteca/Bebida.cpp
        Biblioteca/Bebida.h
        Biblioteca/PlatoFondo.cpp
        Biblioteca/PlatoFondo.h
        Biblioteca/Entrada.cpp
        Biblioteca/Entrada.h
        Biblioteca/Comanda.h
        Biblioteca/Comanda.cpp
        Biblioteca/Restaurante.h
        Biblioteca/Restaurante.cpp)
