cmake_minimum_required(VERSION 3.20)
project(6a)

set(CMAKE_CXX_STANDARD 14)

add_executable(6a main.cpp

        thread/thread.cpp
        thread/thread.h

        Codeforces/Codeforces.cpp
        Codeforces/Codeforces.h
        )
