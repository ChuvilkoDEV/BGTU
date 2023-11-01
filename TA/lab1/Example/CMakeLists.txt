cmake_minimum_required(VERSION 3.21)
project(ta1
    LANGUAGES CXX
    VERSION 0.1
)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 23) #23
set(CMAKE_CXX_STANDARD_REQUIRED)

include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

include_directories(include)

add_library(GrammaParser src/GrammaParser.cpp)
target_link_libraries(GrammaParser nlohmann_json::nlohmann_json)

add_library(GrammaScanner src/GrammaScanner.cpp)

add_library(TreeBuilder src/TreeBuilder.cpp)
target_link_libraries(TreeBuilder GrammaScanner)

add_executable(ta1 main.cpp)
target_link_libraries(ta1 PRIVATE GrammaParser GrammaScanner TreeBuilder)


