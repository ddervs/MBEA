cmake_minimum_required(VERSION 3.6)
project(MBEA)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp tests/basicTests.cpp)
add_executable(MBEA ${SOURCE_FILES})

add_subdirectory(tests)

