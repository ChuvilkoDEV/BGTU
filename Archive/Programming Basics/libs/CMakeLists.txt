cmake_minimum_required(VERSION 3.20)
project(libs C)

set(CMAKE_C_STANDARD 99)

add_executable(libs main.c algorithms/algorithms.c algorithms/algorithms.h array/array_.c array/array_.h sorts/sorts.c sorts/sorts.h sets/bitSet/bitSet.c sets/bitSet/bitSet.h)
