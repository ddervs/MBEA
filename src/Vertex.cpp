//
// Created by Danial Dervovic on 31/03/2017.
//

#include "Vertex.h"
#include <iostream>
#include <algorithm>
#include <exception>
#include <string>

Vertex::Vertex(int label) {
    v_label = label;
}

void Vertex::add_neighbour(Vertex& v) {

    auto it = std::find(neighbours.begin(), neighbours.end(), v);
    if(it != neighbours.end()){
        throw std::runtime_error("Vertex::add_neighbour - vertex is already a neighbour.\n");
    }

    std::shared_ptr<Vertex> v_ptr(&v, [](Vertex*){});
    neighbours.push_back(v_ptr);
}



void Vertex::remove_neighbour(Vertex& v) {

    auto it = std::find(neighbours.begin(), neighbours.end(), v);
    if (it != neighbours.end()){
        neighbours.erase(it);
    }
    else {
        throw std::runtime_error("Vertex::remove_neighbour - vertex is not a neighbour.\n");
    }
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

void Vertex::add_edge(Vertex &v1, Vertex &v2) {
    
    try { v1.add_neighbour(v2);}
    catch( std::runtime_error& e ){
        std::string err_str = "Vertex::add_edge - " + std::to_string(v2.v_label) + " is already a neighbour of " + std::to_string(v1.v_label);
        throw std::runtime_error(err_str);
    }

    try { v2.add_neighbour(v1);}
    catch( std::runtime_error& e ){
        std::string err_str = "Vertex::add_edge - " + std::to_string(v1.v_label) + " is already a neighbour of " + std::to_string(v2.v_label);
        throw std::runtime_error(err_str);
    }
}

void Vertex::remove_edge(Vertex &v1, Vertex &v2) {

    try { v1.remove_neighbour(v2);}
    catch( std::runtime_error& e ){
        std::string err_str = "Vertex::remove_edge - " + std::to_string(v2.v_label) + " is not a neighbour of " + std::to_string(v1.v_label);
        throw std::runtime_error(err_str);
    }

    try { v2.remove_neighbour(v1);}
    catch( std::runtime_error& e ){
        std::string err_str = "Vertex::remove_edge - " + std::to_string(v1.v_label) + " is not a neighbour of " + std::to_string(v2.v_label);
        throw std::runtime_error(err_str);
    }
};

inline bool operator==(const std::shared_ptr<Vertex>& lhs, const Vertex rhs) {
    return *lhs == rhs;
}

inline bool operator==(const Vertex lhs, const std::shared_ptr<Vertex>& rhs) {
    return lhs == *rhs;

}

void Vertex::print_neighbours() {
    for (int i = 0; i < neighbours.size(); i++) {
        Vertex& v = *neighbours[i];
        std::cout << v.v_label;
    }
    std::cout << std::endl;
}