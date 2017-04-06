//
// Created by Danial Dervovic on 06/04/2017.
//

#include "gtest/gtest.h"
#include "BipartiteGraph.h"
#include "Biclique.h"
#include <string>


TEST(biclique_test, matrix_constructor) {

    const std::vector<std::vector<int>> & mat = {{0,1,1}, {1,0,0}, {0,1,0}, {1,1,1}};
    ASSERT_ANY_THROW(Biclique graph = Biclique(mat));

}

TEST(biclique_test, vertex_set_constructor) {

    std::vector<Vertex> left_vertices = {Vertex(1), Vertex(2), Vertex(3)};
    std::vector<Vertex> right_vertices = {Vertex(4), Vertex(5), Vertex(6)};

    Biclique graph = Biclique(left_vertices, right_vertices);

    ASSERT_EQ(graph.print_neighbourhoods(), "4 5 6 \n4 5 6 \n4 5 6 \n\n1 2 3 \n1 2 3 \n1 2 3 \n");

    right_vertices = {Vertex(1), Vertex(5), Vertex(6)};

    ASSERT_ANY_THROW(Biclique graph = Biclique(left_vertices, right_vertices));

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