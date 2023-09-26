cmake_minimum_required(VERSION 3.20)
project(Lab_5b C)

set(CMAKE_C_STANDARD 99)

add_executable(Lab_5b main.c libs/data_structures/vector/vector.c
        libs/data_structures/vector/vector.h libs/array/array.h
        libs/array/array.c libs/data_structures/vector/voidVector.c
        libs/data_structures/vector/voidVector.h)
