//
// Created by Danial Dervovic on 05/04/2017.
//

#include "gtest/gtest.h"
#include "BipartiteGraph.h"
#include "BicliqueFinder.h"


TEST(biclique_finder_test, constructor) {

    const std::vector<std::vector<int>> & mat = {{0,1,1}, {1,0,0}, {0,1,0}, {1,1,1}};
    BipartiteGraph graph = BipartiteGraph(mat);
    BicliqueFinder finder = BicliqueFinder(graph);
    ASSERT_EQ(finder.get_LRPQ_initial(), "1 2 3 4 \n\n5 6 7 \n\n");

}

TEST(biclique_finder_test, get_maximal_throws) {
    const std::vector<std::vector<int>> & mat = {{0,1,1}, {1,0,0}, {0,1,0}, {1,1,1}};
    BipartiteGraph graph = BipartiteGraph(mat);
    BicliqueFinder finder = BicliqueFinder(graph);
    ASSERT_ANY_THROW(finder.get_maximal_bicliques());
    ASSERT_ANY_THROW(finder.get_num_bicliques());
}

TEST(biclique_finder_test, improved) {
    const std::vector<std::vector<int>> & mat = {{0,1,1}, {1,0,0}, {0,1,0}, {1,1,1}};
    BipartiteGraph graph = BipartiteGraph(mat);
    BicliqueFinder finder = BicliqueFinder(graph);
    std::string algorithm = "improved";
    finder.find_maximal_bicliques(algorithm);
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