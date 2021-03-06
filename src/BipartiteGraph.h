//
// Created by Danial Dervovic on 30/03/2017.
//

#ifndef MBEA_BIPARTITEGRAPH_H
#define MBEA_BIPARTITEGRAPH_H

#include <vector>
#include <iostream>
#include "Vertex.h"
#include <string>

class BipartiteGraph {

public:

    BipartiteGraph(const std::vector<std::vector<int>>& incidence_matrix);
    BipartiteGraph();

    void print_matrices();
    std::string print_neighbourhoods();

    std::vector<std::vector<int>> get_incidence_matrix();
    const std::vector<std::vector<std::shared_ptr<Vertex>>>& get_left_neighbours();
    const std::vector<std::vector<std::shared_ptr<Vertex>>>& get_right_neighbours();
    std::vector<std::shared_ptr<Vertex>> get_left_nodes();
    std::vector<std::shared_ptr<Vertex>> get_right_nodes();

protected:

    std::vector<std::vector<int>> inc_mat_;

    std::vector<std::shared_ptr<Vertex>> left_nodes_;
    std::vector<std::shared_ptr<Vertex>> right_nodes_;

    std::vector<std::vector<std::shared_ptr<Vertex>>> left_neighbours_;
    std::vector<std::vector<std::shared_ptr<Vertex>>> right_neighbours_;

    std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>>& mat);

    void check_input(const std::vector<std::vector<int>>& incidence_matrix);

    void print_matrix(const std::vector<std::vector<int>>& mat);
    void print_vector(const std::vector<int>& vec);

    std::string get_neighbourhood_string(const std::vector<std::vector<std::shared_ptr<Vertex>>>& neighbours);

};
#endif //MBEA_BIPARTITEGRAPH_H
