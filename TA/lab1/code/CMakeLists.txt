cmake_minimum_required(VERSION 3.25)
project(code)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(GrammaParser src/GrammaParser.cpp)
target_link_libraries(GrammaParser nlohmann_json::nlohmann_json)

add_library(GrammaScanner src/GrammaScanner.cpp)

add_library(TreeBuilder src/TreeBuilder.cpp)
target_link_libraries(TreeBuilder GrammaScanner)

add_executable(code main.cpp)
