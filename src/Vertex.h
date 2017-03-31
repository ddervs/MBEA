//
// Created by Danial Dervovic on 31/03/2017.
//

#ifndef MBEA_VERTEX_H
#define MBEA_VERTEX_H

#include <memory>
#include <vector>

class Vertex {
public:
    Vertex(int label);

    void add_neighbour(Vertex& v);
    void remove_neighbour(Vertex& v);

    void print_neighbours();

    bool operator==(const Vertex &other) const;
    bool operator!=(const Vertex &other) const;

    static void add_edge(Vertex &v1, Vertex &v2);
    static void remove_edge(Vertex& v1, Vertex& v2);

private:
    std::vector<std::shared_ptr<Vertex>> neighbours;
    int v_label;
};

#endif //MBEA_VERTEX_H
