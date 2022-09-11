cmake_minimum_required(VERSION 3.20)
project(f)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        f main.cpp

        fraction/Fraction.cpp
        fraction/Fraction.h
        algorithms/algorithms.cpp algorithms/algorithms.h BitSet/BitSet.cpp BitSet/BitSet.h PrefixSum/PrefixSum.cpp PrefixSum/PrefixSum.h MaterialPoint/MaterialPoint.cpp MaterialPoint/MaterialPoint.h)
