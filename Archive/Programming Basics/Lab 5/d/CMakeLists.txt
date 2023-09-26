cmake_minimum_required(VERSION 3.20)
project(5d C)

set(CMAKE_C_STANDARD 99)

add_executable(5d main.c libs/data_structures/matrix/matrix.c libs/data_structures/matrix/matrix.h libs/algorithms/algorithms.c libs/algorithms/algorithms.h)
