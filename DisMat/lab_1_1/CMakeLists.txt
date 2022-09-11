cmake_minimum_required(VERSION 3.20)
project(lab_1_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab_1_1 main.c

        libs/array/array.c
        libs/array/array.h

        libs/algorithms/algorithms.c
        libs/algorithms/algorithms.h

        sets/unorderedSet/unorderedSet.c
        sets/unorderedSet/unorderedSet.h

        sets/orderedSet/orderedSet.c
        sets/orderedSet/orderedSet.h

        sets/bitSet/bitSet.c
        sets/bitSet/bitSet.h

        sets/boolean_arraySet/booleans_array.c
        sets/boolean_arraySet/booleans_array.h
        )
