//
// Created by Danial Dervovic on 06/04/2017.
//

#ifndef MBEA_VERTEXSET_H
#define MBEA_VERTEXSET_H

#include "Vertex.h"
#include <vector>

class VertexSet {

public:
    VertexSet();
    VertexSet(const std::vector<Vertex>& nodes_in);

    void add_vertex(const Vertex& v);
    void remove_vertex(const Vertex& v);
    std::string to_string();

    bool operator==(const VertexSet &other) const;
    void sort_by_num_neighbours();
    int size() const;
    bool empty() const;

    Vertex get_vertex(int i) const;
    std::vector<Vertex> get_set() const;
private:
    std::vector<Vertex> set_of_vertices_;
};


#endif //MBEA_VERTEXSET_H
