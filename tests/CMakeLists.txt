project(MBEA)

include_directories(lib/googletest-master/googletest/include)

add_executable(runMBEATests
        basicTests.cpp)

add_subdirectory(lib/googletest-master)
target_link_libraries(runMBEATests gtest gtest_main)