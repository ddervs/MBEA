//
// Created by Danial Dervovic on 05/04/2017.
//

#include "gtest/gtest.h"
#include "Vertex.h"
#include "BipartiteGraph.h"
#include <vector>
#include <iostream>


TEST(bipartite_graph_test, constructor) {

    const std::vector<std::vector<int>> & wrong_size_mat = {{0,1,1}, {1,0}, {0,1,0}, {1}};
    ASSERT_ANY_THROW(BipartiteGraph graph = BipartiteGraph(wrong_size_mat));

    const std::vector<std::vector<int>> & wrong_elems_mat = {{2,1,1}, {1,-1,0}, {0,-45,0}, {1,1,21}};
    ASSERT_ANY_THROW(BipartiteGraph graph = BipartiteGraph(wrong_elems_mat));
}

TEST(bipartite_graph_test, neighbourhoods) {

    const std::vector<std::vector<int>> & mat = {{0,1,1}, {1,0,0}, {0,1,0}, {1,1,1}};
    BipartiteGraph graph = BipartiteGraph(mat);

    ASSERT_EQ(graph.print_neighbourhoods(), "6 7 \n5 \n6 \n5 6 7 \n\n2 4 \n1 3 4 \n1 4 \n");
}


TEST(bipartite_graph_test, pointer_equality) {

    const std::vector<std::vector<int>> & mat = {{0,1,1}, {1,0,0}, {0,1,0}, {1,1,1}};
    BipartiteGraph graph = BipartiteGraph(mat);

    // Check pointers in left_neighbourhood equal to individual Vertex neighbours
    std::vector<std::vector<std::shared_ptr<Vertex>>> left_hood = graph.get_left_neighbours();
    std::vector<std::shared_ptr<Vertex>> left_nodes = graph.get_left_nodes();

    for (int i = 0; i < left_hood.size(); i++) {
        std::vector<std::shared_ptr<Vertex>> v_hood_1 = left_hood[i];
        Vertex v = *left_nodes[i];
        const std::vector<std::shared_ptr<Vertex>>& v_hood_2 = v.get_neighbours();
        // neighbourhood size
        ASSERT_EQ(v_hood_1.size(), v_hood_2.size());
        // pointer equality
        for (int j = 0; j < v_hood_1.size(); j++) {
            std::shared_ptr<Vertex> v_ptr_1 = v_hood_1[j];
            std::shared_ptr<Vertex> v_ptr_2 = v_hood_2[j];
            ASSERT_EQ(v_ptr_1, v_ptr_2);
        }
    }


    // Check pointers in right_neighbourhood equal to individual Vertex neighbours
    std::vector<std::vector<std::shared_ptr<Vertex>>> right_hood = graph.get_right_neighbours();
    std::vector<std::shared_ptr<Vertex>> right_nodes = graph.get_right_nodes();

    for (int i = 0; i < right_hood.size(); i++) {
        std::vector<std::shared_ptr<Vertex>> v_hood_1 = right_hood[i];
        Vertex v = *right_nodes[i];
        const std::vector<std::shared_ptr<Vertex>>& v_hood_2 = v.get_neighbours();
        // neighbourhood size
        ASSERT_EQ(v_hood_1.size(), v_hood_2.size());
        // pointer equality
        for (int j = 0; j < v_hood_1.size(); j++) {
            std::shared_ptr<Vertex> v_ptr_1 = v_hood_1[j];
            std::shared_ptr<Vertex> v_ptr_2 = v_hood_2[j];
            ASSERT_EQ(v_ptr_1, v_ptr_2);
        }
    }

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

