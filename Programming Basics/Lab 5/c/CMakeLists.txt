cmake_minimum_required(VERSION 3.20)
project(vor C)

set(CMAKE_C_STANDARD 99)

add_executable(vor main.c libs/algorithms/algorithms.c libs/algorithms/algorithms.h)
