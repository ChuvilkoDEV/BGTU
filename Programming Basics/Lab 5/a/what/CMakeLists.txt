cmake_minimum_required(VERSION 3.20)
project(what C)

set(CMAKE_C_STANDARD 99)

add_executable(what main.c ordered.cpp ordered.h)
