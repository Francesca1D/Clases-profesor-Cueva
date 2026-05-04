cmake_minimum_required(VERSION 4.0)
project(VoidStreamers)

set(CMAKE_CXX_STANDARD 20)

add_executable(VoidStreamers main.cpp
        MiBiblioteca/PunterosGenericos.cpp
        MiBiblioteca/PunterosGenericos.h)
