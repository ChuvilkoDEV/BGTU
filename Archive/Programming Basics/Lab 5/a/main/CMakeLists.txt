cmake_minimum_required(VERSION 3.20)
project(Sets C)

set(CMAKE_C_STANDARD 99)

add_executable(main main.c bitSet.c bitSet.h unorderedset.c unorderedset.h orderedarrayset.c orderedarrayset.h array.c array.h)
