#include <iostream>
#include "BipartiteGraph.h"
#include <vector>
#include "Vertex.h"

void carriage_return() {
    std::cout << std::endl;
}

int main() {

    // Test int BipartiteGraph constructor
    //std::vector<std::vector<int>> mat = {{0,1,1}, {1,0,0}, {0,1,0}};
    //BipartiteGraph graph = BipartiteGraph(mat);
    //graph.print_matrices();

    // Test constructors and neighbours
    Vertex v1 = Vertex(1);
    Vertex v2 = Vertex(2);
    v1.add_neighbour(v2);
    v2.add_neighbour(v1);
    v1.print_neighbours();
    v2.print_neighbours();
    carriage_return();

    // Test make edge
    Vertex v3 = Vertex(3);
    Vertex v4 = Vertex(4);
    Vertex::make_edge(v3, v4);
    v3.print_neighbours();
    v4.print_neighbours();
    carriage_return();

    // Test removing neighbours
    Vertex::make_edge(v4, v1);
    v4.remove_neighbour((Vertex&) v3);
    v4.print_neighbours();
    carriage_return();

    // Test removing edges
    v4.add_neighbour((Vertex&) v3);
    Vertex::remove_edge((Vertex&) v1, (Vertex&) v4);
    v4.print_neighbours();
    v1.print_neighbours();
    carriage_return();

    return 0;
}