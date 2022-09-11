cmake_minimum_required(VERSION 3.20)
project (1_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(1_3 main.cpp
        libs/UOAS/UOAS.cpp
        libs/UOAS/UOAS.h

        libs/array/array.cpp
        libs/array/array.h
        )
