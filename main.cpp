#include <iostream>
#include "BipartiteGraph.h"
#include <vector>
#include "Vertex.h"

void carriage_return() {
    std::cout << std::endl;
}

void print(const char* in) {
    std::cout << in << std::endl;
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

    try { v2.add_neighbour(v1); }
    catch( std::runtime_error& e ){print("add_neighbour err caught");}

    v1.print_neighbours();
    v2.print_neighbours();
    carriage_return();

    // Test make edge
    Vertex v3 = Vertex(3);
    Vertex v4 = Vertex(4);
    Vertex::add_edge(v3, v4);
    try { Vertex::add_edge(v3, v4); }
    catch( std::runtime_error& e ){print("add_edge err caught");}
    v3.print_neighbours();
    v4.print_neighbours();
    carriage_return();

    // Test removing neighbours
    Vertex::add_edge(v4, v1);
    v4.remove_neighbour((Vertex&) v3);
    try { v4.remove_neighbour((Vertex&) v3); }
    catch( std::runtime_error& e ){print("remove_neighbour err caught");}
    v4.print_neighbours();
    carriage_return();

    // Test removing edges
    v4.add_neighbour((Vertex&) v3);
    Vertex::remove_edge((Vertex&) v1, (Vertex&) v4);
    try { Vertex::remove_edge((Vertex&) v1, (Vertex&) v4); }
    catch( std::runtime_error& e ){print("remove_edge err caught");}
    v4.print_neighbours();
    v1.print_neighbours();
    carriage_return();

    return 0;
}