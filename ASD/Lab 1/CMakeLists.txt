cmake_minimum_required(VERSION 3.20)
project(_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(_1 main.c DecToBin/DecToBin.c DecToBin/DecToBin.h BinToDec/BinToDec.c BinToDec/BinToDec.h)
