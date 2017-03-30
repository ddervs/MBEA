cmake_minimum_required(VERSION 3.6)
project(MBEA)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/BipartiteGraph.cpp src/BipartiteGraph.h)
add_executable(MBEA ${SOURCE_FILES})

add_subdirectory(tests)

