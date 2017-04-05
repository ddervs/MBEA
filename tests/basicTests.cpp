//
// Created by Danial Dervovic on 30/03/2017.
//

#include "gtest/gtest.h"
#include "BipartiteGraph.h"
#include <vector>
#include <iostream>

TEST(basic_test, test_eq) {
    //EXPECT_EQ(1, 1);
    const std::vector<std::vector<int>>& incidence_matrix = {{0,1,1}, {1,0,0}, {0,1,0}, {1,1,1}};
    BipartiteGraph graph = BipartiteGraph(incidence_matrix);
    // Check correct neighbourhoods imported
    graph.print_neighbourhoods();
}

int main (int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    int returnValue;

    //Do whatever setup here you will need for your tests here
    //
    //

    returnValue =  RUN_ALL_TESTS();

    //Do Your teardown here if required
    //
    //

    return returnValue;
}

