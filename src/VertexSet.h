//
// Created by Danial Dervovic on 06/04/2017.
//

#ifndef MBEA_VERTEXSET_H
#define MBEA_VERTEXSET_H

#include "Vertex.h"

class VertexSet {

public:
    VertexSet();
    void add_vertex(const Vertex& v);
    void remove_vertex(const Vertex& v);
    std::string to_string();

    bool operator==(const VertexSet &other) const;

private:
    std::vector<Vertex> set_of_vertices_;
};


#endif //MBEA_VERTEXSET_H
