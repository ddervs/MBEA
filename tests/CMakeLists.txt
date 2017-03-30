project(MBEA)
set(CMAKE_CXX_STANDARD 11)

#add_compile_options(--version)

include_directories(lib/googletest-master/googletest/include ../src)

enable_testing()
add_executable(runMBEAtests basicTests.cpp)

add_subdirectory(lib/googletest-master)
target_link_libraries(runMBEAtests gtest gtest_main)

