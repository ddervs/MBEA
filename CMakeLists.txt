cmake_minimum_required(VERSION 3.6)
project(MBEA)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/BipartiteGraph.cpp src/BipartiteGraph.h src/Vertex.cpp src/Vertex.h src/BicliqueFinder.cpp src/BicliqueFinder.h src/Biclique.cpp src/Biclique.h src/VertexSet.cpp src/VertexSet.h src/CommandLineParser.cpp src/CommandLineParser.h)
add_executable(MBEA ${SOURCE_FILES})

include_directories(src)

add_subdirectory(tests)

