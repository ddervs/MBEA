project(MBEA)
set(CMAKE_CXX_STANDARD 11)

#add_compile_options(--version)

include_directories(lib/googletest-master/googletest/include ../src)

add_subdirectory(lib/googletest-master)

add_library(MBEA_lib ../src/Vertex.cpp ../src/BipartiteGraph.cpp)

set(DATA_DIR ${CMAKE_SOURCE_DIR}/Testing/Data)
set(TMP_DIR ${CMAKE_BINARY_DIR}/Testing/Temporary)

enable_testing()

set(TEST_CASES
       basicTests
        )

foreach(_test_case ${TEST_CASES})
    add_executable(${_test_case} ${_test_case}.cpp )
    target_link_libraries(${_test_case} gtest gtest_main MBEA_lib)
endforeach()

# Adding tests is done outside the above loop,
# as each test will need different arguments.

##################################################################################################
# Dont forget its:  add_test(<test name (globally unique) > <exe name> <argument1> <argument2>
##################################################################################################

add_test(basic ${EXECUTABLE_OUTPUT_PATH}/BasicTest)

