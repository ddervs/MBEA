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

    VertexSet(const std::vector<std::shared_ptr<Vertex>> &nodes_in);

    void add_vertex(std::shared_ptr<Vertex> v);
    void remove_vertex(std::shared_ptr<Vertex> v);
    std::string to_string();

    bool operator==(const VertexSet &other) const;
    void sort_by_num_neighbours();
    unsigned long size() const;
    bool empty() const;

    std::shared_ptr<Vertex> get_vertex(int i) const;
    std::vector<std::shared_ptr<Vertex>> get_set() const;
private:
    std::vector<std::shared_ptr<Vertex>> set_of_vertices_;
};


#endif //MBEA_VERTEXSET_H
