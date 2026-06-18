cmake_minimum_required(VERSION 4.0)
project(PoliComandas)

set(CMAKE_CXX_STANDARD 20)

add_executable(PoliComandas main.cpp
        Biblioteca/Bebida.cpp
        Biblioteca/PlatoFondo.h
        Biblioteca/Entrada.h
        Biblioteca/Entrada.cpp
        Biblioteca/DetalleComanda.cpp
        Biblioteca/DetalleComanda.h
        Biblioteca/Producto.cpp
        Biblioteca/Restaurante.cpp
        Biblioteca/Restaurante.h
        Biblioteca/PlatoFondo.cpp
        Biblioteca/Cola.cpp
        Biblioteca/Cola.h
        Biblioteca/Nodo.cpp
        Biblioteca/Nodo.h)
