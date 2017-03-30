//
// Created by Danial Dervovic on 30/03/2017.
//

#include "BipartiteGraph.h"

BipartiteGraph::BipartiteGraph(const std::vector<std::vector<int>>& incidence_matrix) {

    inc_mat = incidence_matrix;

    const int left_start = 1;
    const int right_start = incidence_matrix.size() + 1;

    for (int i = 0; i < incidence_matrix.size(); i++) {
        left_nodes.push_back(left_start + i);
        std::vector<int> left_neighbour;
        for (int j = 0; j < incidence_matrix[i].size(); j++) {

            if (incidence_matrix[i][j] == 1) {
                left_neighbour.push_back(right_start + j);
            }

        }
        left_neighbours.push_back(left_neighbour);
    }

    const std::vector<std::vector<int>> transposed = transpose(incidence_matrix);

    for (int i = 0; i < transposed.size(); i++) {
        right_nodes.push_back(right_start + i);
        std::vector<int> right_neighbour;
        for (int j = 0; j < transposed[i].size(); j++) {

            if (transposed[i][j] == 1) {
                right_neighbour.push_back(left_start + j);
            }

        }
        right_neighbours.push_back(right_neighbour);
    }
}

std::vector<std::vector<int>> BipartiteGraph::get_incidence_matrix(){
    return inc_mat;
}

void BipartiteGraph::print_matrices() {
    print_matrix(inc_mat);
    std::cout << std::endl;
    print_matrix(left_neighbours);
    std::cout << std::endl;
    print_matrix(right_neighbours);
}

void BipartiteGraph::print_matrix(const std::vector<std::vector<int>>& mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            std::cout << mat[i][j];
        }
        std::cout << std::endl;
    }
}

void BipartiteGraph::print_vector(const std::vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
    }
    std::cout << std::endl;
}

std::vector<std::vector<int>> BipartiteGraph::transpose(const std::vector<std::vector<int>> &mat) {
        // this assumes that all inner vectors have the same size and
        // allocates space for the complete result in advance
        std::vector<std::vector<int> > result(mat[0].size(),
                                              std::vector<int>(mat.size()));
        for (std::vector<int>::size_type i = 0; i < mat[0].size(); i++)
            for (std::vector<int>::size_type j = 0; j < mat.size(); j++) {
                result[i][j] = mat[j][i];
            }
        return result;
}
