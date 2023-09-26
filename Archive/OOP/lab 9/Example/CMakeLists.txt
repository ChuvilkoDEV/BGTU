cmake_minimum_required(VERSION 3.24)
project(Example)

set(CMAKE_CXX_STANDARD 23)

add_executable(Example main.cpp Task.cpp Task.h TaskQueue.cpp TaskQueue.h MainTaskQueue.cpp MainTaskQueue.h Executor.cpp Executor.h)
