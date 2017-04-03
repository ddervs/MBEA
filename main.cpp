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

    /*
    // Test int BipartiteGraph constructor
    std::vector<std::vector<int>> mat = {{0,1,1}, {1,0,0}, {0,1,0}};
    BipartiteGraph graph = BipartiteGraph(mat);
    graph.print_matrices();
    */

    /*

    // Test constructors and neighbours_
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

    // Test removing neighbours_
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

    */

    std::vector<std::vector<int>> mat = {{0,1,1}, {1,0,0}, {0,1,0}, {1,1,1}};
    BipartiteGraph graph = BipartiteGraph(mat);

    // Check correct neighbourhoods imported
    graph.print_neighbourhoods();

    // Check pointers in left_neighbourhood equal to individual Vertex neighbours
    std::vector<std::vector<std::shared_ptr<Vertex>>> left_hood = graph.get_left_neighbours();
    std::vector<Vertex> left_nodes = graph.get_left_nodes();

    for (int i = 0; i < left_hood.size(); i++) {
        std::vector<std::shared_ptr<Vertex>> v_hood_1 = left_hood[i];
        Vertex v = left_nodes[i];
        const std::vector<std::shared_ptr<Vertex>>& v_hood_2 = v.get_neighbours();
        // neighbourhood size
        if (v_hood_1.size() != v_hood_2.size()) {
            std::string err_string = "Vertex " + std::to_string(i) + " neighbourhoods different sizes.";
            throw std::runtime_error(err_string);
        }
        // pointer equality
        for (int j = 0; j < v_hood_1.size(); j++) {
            std::shared_ptr<Vertex> v_ptr_1 = v_hood_1[j];
            std::shared_ptr<Vertex> v_ptr_2 = v_hood_2[j];
            if (v_ptr_1 != v_ptr_2) {
                std::string err_string = "Left Vertex" + std::to_string(i) +  ", Neighbour: " + std::to_string(j) +  " pointers not equal.\n";
                throw std::runtime_error(err_string);
            }
        }
    }


    // Check pointers in right_neighbourhood equal to individual Vertex neighbours
    std::vector<std::vector<std::shared_ptr<Vertex>>> right_hood = graph.get_right_neighbours();
    std::vector<Vertex> right_nodes = graph.get_right_nodes();

    for (int i = 0; i < right_hood.size(); i++) {
        std::vector<std::shared_ptr<Vertex>> v_hood_1 = right_hood[i];
        Vertex v = right_nodes[i];
        const std::vector<std::shared_ptr<Vertex>>& v_hood_2 = v.get_neighbours();
        // neighbourhood size
        if (v_hood_1.size() != v_hood_2.size()) {
            std::string err_string = "Vertex " + std::to_string(i) + " neighbourhoods different sizes.";
            throw std::runtime_error(err_string);
        }
        // pointer equality
        for (int j = 0; j < v_hood_1.size(); j++) {
            std::shared_ptr<Vertex> v_ptr_1 = v_hood_1[j];
            std::shared_ptr<Vertex> v_ptr_2 = v_hood_2[j];
            if (v_ptr_1 != v_ptr_2) {
                std::string err_string = "Right Vertex" + std::to_string(i) +  ", Neighbour: " + std::to_string(j) +  " pointers not equal.\n";
                throw std::runtime_error(err_string);
            }
        }
    }


    return 0;
}