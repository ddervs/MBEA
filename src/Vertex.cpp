//
// Created by Danial Dervovic on 31/03/2017.
//

#include "Vertex.h"
#include <iostream>
#include <algorithm>

Vertex::Vertex(int label) {
    v_label = label;
}

void Vertex::add_neighbour(Vertex& v) {
    //TODO: Check for doubles - throw exception

    std::shared_ptr<Vertex> v_ptr(&v, [](Vertex*){});
    neighbours.push_back(v_ptr);
}

void Vertex::print_neighbours() {
    for (int i = 0; i < neighbours.size(); i++) {
        Vertex& v = *neighbours[i];
        std::cout << v.v_label;
    }
    std::cout << std::endl;
}

void Vertex::remove_neighbour(Vertex& v) {
    //TODO: Test is a neighbour, throw exception

    auto it = std::find(neighbours.begin(), neighbours.end(), v);
    if(it != neighbours.end())
        neighbours.erase(it);

}

bool Vertex::operator==(const Vertex &other) const {
   if (v_label == other.v_label) {
       return true;
   }
   else {
       return false;
   }
}
bool Vertex::operator!=(const Vertex &other) const {
    return !(*this == other);
}

void Vertex::make_edge(Vertex& v1, Vertex& v2) {
    //TODO: Check not already edge
    v1.add_neighbour(v2);
    v2.add_neighbour(v1);
}

void Vertex::remove_edge(Vertex &v1, Vertex &v2) {
    //TODO: Check that is an edge
    v1.remove_neighbour(v2);
    v2.remove_neighbour(v1);
};

inline bool operator==(const std::shared_ptr<Vertex>& lhs, const Vertex rhs) {
    return *lhs == rhs;
}

inline bool operator==(const Vertex lhs, const std::shared_ptr<Vertex>& rhs) {
    return lhs == *rhs;
}