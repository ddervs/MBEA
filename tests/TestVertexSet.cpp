//
// Created by Danial Dervovic on 06/04/2017.
//

#include "gtest/gtest.h"
#include "Vertex.h"
#include "VertexSet.h"

TEST(vertex_set_test, add_vertex) {

    std::shared_ptr<Vertex>v1(new Vertex(1));
    std::shared_ptr<Vertex>v2(new Vertex(2));

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

    std::shared_ptr<Vertex>v1(new Vertex(1));
    std::shared_ptr<Vertex>v2(new Vertex(2));
    std::shared_ptr<Vertex>v3(new Vertex(3));

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


TEST(vertex_set_test, sort_by_num_neighbours) {

    std::shared_ptr<Vertex>v1(new Vertex(1));
    std::shared_ptr<Vertex>v2(new Vertex(2));
    std::shared_ptr<Vertex>v3(new Vertex(3));


    Vertex::add_edge((*v1), (*v2));
    Vertex::add_edge((*v2), (*v3));

    VertexSet S = VertexSet();
    S.add_vertex(v1);
    S.add_vertex(v2);
    S.add_vertex(v3);

    S.sort_by_num_neighbours();

    ASSERT_TRUE((S.to_string() == "1 3 2 ") or (S.to_string() == "3 1 2 ") );

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