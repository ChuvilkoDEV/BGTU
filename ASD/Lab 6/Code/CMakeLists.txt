cmake_minimum_required(VERSION 3.23)
project(Code)

set(CMAKE_CXX_STANDARD 14)

add_executable(Code main.cpp Stack/Stack.cpp Stack/Stack.h Queue/Queue.cpp Queue/Queue.h)
