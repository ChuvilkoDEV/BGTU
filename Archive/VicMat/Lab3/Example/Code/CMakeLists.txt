cmake_minimum_required(VERSION 3.20.2)
project(Code)

set(CMAKE_CXX_STANDARD 23)

add_executable(Code main.cpp libs/integrals/integrals.cpp libs/integrals/integrals.h)
