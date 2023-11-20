cmake_minimum_required(VERSION 3.26)
project(Lista_Cadastral)

set(CMAKE_CXX_STANDARD 14)

include_directories(Lista)

add_executable(Lista_Cadastral
        Lista/Lista.cpp
        Lista/Lista.h
        main.cpp)
