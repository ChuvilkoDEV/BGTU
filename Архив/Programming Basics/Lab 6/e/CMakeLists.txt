cmake_minimum_required(VERSION 3.20)
project(6e)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        6e main.cpp

        deque/deque.cpp deque/deque.h

        list/list.cpp list/list.h

        queue/queue.cpp queue/queue.h

        stack/stack.cpp stack/stack.h
        list/testsList.cpp list/testsList.h)
