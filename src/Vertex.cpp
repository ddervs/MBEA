//
// Created by Danial Dervovic on 31/03/2017.
//

#include "Vertex.h"
#include "VertexSet.h"
#include <iostream>
#include <algorithm>
#include <exception>
#include <string>

Vertex::Vertex(int label) {
    v_label_ = label;
}

void Vertex::add_neighbour(Vertex &v) {

    auto it = std::find(neighbours_.begin(), neighbours_.end(), v);
    if(it != neighbours_.end()){
        throw std::runtime_error("Vertex::add_neighbour - vertex is already a neighbour.\n");
    }

    std::shared_ptr<Vertex> v_ptr(&v, [](Vertex*){});
    neighbours_.push_back(v_ptr);
}



void Vertex::remove_neighbour(Vertex& v) {

    auto it = std::find(neighbours_.begin(), neighbours_.end(), v);
    if (it != neighbours_.end()){
        neighbours_.erase(it);
    }
    else {
        throw std::runtime_error("Vertex::remove_neighbour - vertex is not a neighbour.\n");
    }
}

bool Vertex::operator==(const Vertex &other) const {
    return v_label_ == other.v_label_;
}
bool Vertex::operator!=(const Vertex &other) const {
    return !(*this == other);
}

void Vertex::add_edge(Vertex &v1, Vertex &v2) {
    
    try { v1.add_neighbour(v2);}
    catch( std::runtime_error& e ){
        std::string err_str = "Vertex::add_edge - " + std::to_string(v2.v_label_) + " is already a neighbour of " + std::to_string(v1.v_label_);
        throw std::runtime_error(err_str);
    }

    try { v2.add_neighbour(v1);}
    catch( std::runtime_error& e ){
        std::string err_str = "Vertex::add_edge - " + std::to_string(v1.v_label_) + " is already a neighbour of " + std::to_string(v2.v_label_);
        throw std::runtime_error(err_str);
    }
}

void Vertex::remove_edge(Vertex &v1, Vertex &v2) {

    try { v1.remove_neighbour(v2);}
    catch( std::runtime_error& e ){
        std::string err_str = "Vertex::remove_edge - " + std::to_string(v2.v_label_) + " is not a neighbour of " + std::to_string(v1.v_label_);
        throw std::runtime_error(err_str);
    }

    try { v2.remove_neighbour(v1);}
    catch( std::runtime_error& e ){
        std::string err_str = "Vertex::remove_edge - " + std::to_string(v1.v_label_) + " is not a neighbour of " + std::to_string(v2.v_label_);
        throw std::runtime_error(err_str);
    }
};

inline bool operator==(const std::shared_ptr<Vertex>& lhs, const Vertex rhs) {
    return *lhs == rhs;
}

inline bool operator==(const Vertex lhs, const std::shared_ptr<Vertex>& rhs) {
    return lhs == *rhs;

}

bool Vertex::operator>(const Vertex &other) const {
    Vertex & rhs = const_cast<Vertex&>(other);
    return this->v_label_ > rhs.get_label();
}

bool Vertex::operator<(const Vertex &other) const {
    Vertex & rhs = const_cast<Vertex&>(other);
    return this->v_label_ < rhs.get_label();
}

std::string Vertex::get_neighbours_string() {

    std::string out;

    for (int i = 0; i < neighbours_.size(); i++) {
        Vertex& v = *neighbours_[i];
        std::string label_str = std::to_string(v.v_label_);
        out += label_str + " ";
    }
    return out;
}

const std::vector<std::shared_ptr<Vertex>> & Vertex::get_neighbours() {
    return neighbours_;
}

const int & Vertex::get_label() {
    return v_label_;
}

int Vertex::num_neighbours() const {
    return (int) neighbours_.size();
}

bool Vertex::is_neighbour(const Vertex &other) const {
    return std::find(neighbours_.begin(), neighbours_.end(), other) != neighbours_.end();
}

int Vertex::num_neighbours_of_v_in_set(const std::vector<std::shared_ptr<Vertex>> &set) {
    int out = 0;
    for (int i = 0; i < set.size(); i++) {
        if(is_neighbour(*set[i])) {
            out += 1;
        }
    }
    return out;
}

bool Vertex::is_member(const std::vector<Vertex> &set) const {
    bool out = false;
    for (int i = 0; i < set.size(); i++) {
        if ((*this) == set[i]) {
            out = true;
        }
    }
    return out;
}



