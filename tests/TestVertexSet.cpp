//
// Created by Danial Dervovic on 06/04/2017.
//

#include "gtest/gtest.h"
#include "Vertex.h"
#include "VertexSet.h"

TEST(vertex_set_test, add_vertex) {

    Vertex v1 = Vertex(1);
    Vertex v2 = Vertex(2);

    VertexSet S1 = VertexSet();

    S1.add_vertex(v1);
    S1.add_vertex(v2);
    VertexSet S2 = S1;

    S2.add_vertex(v1);

    ASSERT_EQ(S1, S2);

}

TEST(vertex_set_test, remove_vertex) {

}

TEST(vertex_set_test, equality) {

    Vertex v1 = Vertex(v1);
    Vertex v2 = Vertex(v2);
    Vertex v3 = Vertex(v3);

    VertexSet S1 = VertexSet();
    VertexSet S2 = VertexSet();

    S1.add_vertex(v1);
    S1.add_vertex(v2);
    S1.add_vertex(v3);

    S2.add_vertex(v3);
    S2.add_vertex(v1);
    S2.add_vertex(v2);

    ASSERT_EQ(S1, S2);
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