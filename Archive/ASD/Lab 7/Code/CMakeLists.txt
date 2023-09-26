cmake_minimum_required(VERSION 3.23)
project(Code C)

set(CMAKE_C_STANDARD 99)

add_executable(Code main.c Tree/Tree.c Tree/Tree.h)
