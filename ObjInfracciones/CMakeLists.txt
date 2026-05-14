cmake_minimum_required(VERSION 4.0)
project(ObjInfracciones)

set(CMAKE_CXX_STANDARD 20)

add_executable(ObjInfracciones main.cpp
        Biblioteca/Infraccion.cpp
        Biblioteca/Infraccion.h
        Biblioteca/Empresa.cpp
        Biblioteca/Empresa.h
        Biblioteca/Multa.cpp
        Biblioteca/Multa.h
        Biblioteca/Ministerio.cpp
        Biblioteca/Ministerio.h
)
