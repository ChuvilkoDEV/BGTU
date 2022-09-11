cmake_minimum_required(VERSION 3.20)
project(main C)

set(CMAKE_C_STANDARD 99)

add_executable(main main.c implementation.c implementation.h libs/string_/string_.c libs/string_/string_.h)