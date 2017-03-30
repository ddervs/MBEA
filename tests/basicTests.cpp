//
// Created by Danial Dervovic on 30/03/2017.
//

#include "gtest/gtest.h"
#include "BipartiteGraph.h"
#include <vector>
#include <iostream>

TEST(basic_test, test_eq) {
   EXPECT_EQ(1, 1);
}

int main() {

    std::vector<std::vector<int>> mat = {{0, 1, 1},
                                         {1, 0, 0},
                                         {0, 1, 0}};
    std::cout << "WTF" << std::endl;
//BipartiteGraph graph = BipartiteGraph(mat);
}