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

    std::string get_neighbours_string();
    const int& get_label();

    bool operator==(const Vertex &other) const;
    bool operator!=(const Vertex &other) const;

    static void add_edge(Vertex& v1, Vertex& v2);
    static void remove_edge(Vertex& v1, Vertex& v2);
    const std::vector<std::shared_ptr<Vertex>>& get_neighbours();

private:
    std::vector<std::shared_ptr<Vertex>> neighbours_;
    void add_neighbour(Vertex& v);
    void remove_neighbour(Vertex& v);
    int v_label_;

};

#endif //MBEA_VERTEX_H
