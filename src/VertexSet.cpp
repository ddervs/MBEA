//
// Created by Danial Dervovic on 06/04/2017.
//

#include "VertexSet.h"
#include <algorithm>
#include <string>

void VertexSet::add_vertex(const Vertex &v) {

    if(std::find(set_of_vertices_.begin(), set_of_vertices_.end(), v) == set_of_vertices_.end()) {
        set_of_vertices_.push_back(v);
    }
}

void VertexSet::remove_vertex(const Vertex &v) {
    set_of_vertices_.erase(std::remove_if(set_of_vertices_.begin(), set_of_vertices_.end(), [&](Vertex& u) {
                               return u == v;
                           }),
            set_of_vertices_.end());

}

std::string VertexSet::to_string() {

    std::string out;
    for (int i = 0; i < set_of_vertices_.size(); i++) {
        out += set_of_vertices_[i].get_label() + " ";
    }

    return out;
}

bool VertexSet::operator==(const VertexSet &other) const {

    std::vector<Vertex> lhs = set_of_vertices_;
    std::vector<Vertex> rhs = other.set_of_vertices_;
    std::sort(lhs.begin(), lhs.end());
    std::sort(rhs.begin(), rhs.end());
    return lhs == rhs;

}

VertexSet::VertexSet() {

}

