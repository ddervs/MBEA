//
// Created by Danial Dervovic on 05/04/2017.
//

#include "gtest/gtest.h"
#include "Vertex.h"

TEST(vertex_test, repeat_edge) {

    Vertex v1 = Vertex(1);
    Vertex v2 = Vertex(2);
    Vertex::add_edge(v1, v2);
    ASSERT_ANY_THROW(Vertex::add_edge(v1, v2));
    Vertex v3 = Vertex(3);
    ASSERT_ANY_THROW(Vertex::remove_edge(v1, v3));

}

TEST(vertex_test, neighbourhood){

    Vertex v1 = Vertex(1);
    Vertex v2 = Vertex(2);
    Vertex v3 = Vertex(3);

    Vertex::add_edge(v1, v2);
    Vertex::add_edge(v2, v3);

    ASSERT_EQ(v1.get_neighbours_string(), "2 ");
    ASSERT_EQ(v2.get_neighbours_string(), "1 3 ");
    ASSERT_EQ(v3.get_neighbours_string(), "2 ");
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

