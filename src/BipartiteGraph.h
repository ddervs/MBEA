//
// Created by Danial Dervovic on 30/03/2017.
//

#ifndef MBEA_BIPARTITEGRAPH_H
#define MBEA_BIPARTITEGRAPH_H

#include <vector>
#include <iostream>

class BipartiteGraph {
public:
    BipartiteGraph(const std::vector<std::vector<int>>& incidence_matrix);
    void print_matrices();
    std::vector<std::vector<int>> get_incidence_matrix();
private:
    std::vector<int> left_nodes;
    std::vector<int> right_nodes;
    std::vector<std::vector<int>> left_neighbours;
    std::vector<std::vector<int>> right_neighbours;
    std::vector<std::vector<int>> inc_mat;
    void print_matrix(const std::vector<std::vector<int>>& mat);
    void print_vector(const std::vector<int>& vec);
    std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>>& mat);
};


#endif //MBEA_BIPARTITEGRAPH_H
