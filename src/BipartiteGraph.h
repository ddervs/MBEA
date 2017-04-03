//
// Created by Danial Dervovic on 30/03/2017.
//

#ifndef MBEA_BIPARTITEGRAPH_H
#define MBEA_BIPARTITEGRAPH_H

#include <vector>
#include <iostream>
#include "Vertex.h"

class BipartiteGraph {
public:

    BipartiteGraph(const std::vector<std::vector<int>>& incidence_matrix);
    void print_matrices();
    std::vector<std::vector<int>> get_incidence_matrix();
    void print_neighbourhoods();
    const std::vector<std::vector<std::shared_ptr<Vertex>>>& get_left_neighbours();
    const std::vector<std::vector<std::shared_ptr<Vertex>>>& get_right_neighbours();
    const std::vector<Vertex>& get_left_nodes();
    const std::vector<Vertex>& get_right_nodes();

private:

    std::vector<Vertex> left_nodes_;
    std::vector<Vertex> right_nodes_;

    std::vector<std::vector<std::shared_ptr<Vertex>>> left_neighbours_;
    std::vector<std::vector<std::shared_ptr<Vertex>>> right_neighbours_;

    std::vector<std::vector<int>> inc_mat_;

    void print_matrix(const std::vector<std::vector<int>>& mat);
    void print_vector(const std::vector<int>& vec);

    void print_set_neighbourhood(const std::vector<std::vector<std::shared_ptr<Vertex>>>& neighbours);

    std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>>& mat);

};


#endif //MBEA_BIPARTITEGRAPH_H
