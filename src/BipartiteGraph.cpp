//
// Created by Danial Dervovic on 30/03/2017.
//

#include "BipartiteGraph.h"
#include <memory>

BipartiteGraph::BipartiteGraph(const std::vector<std::vector<int>>& incidence_matrix) {

    inc_mat_ = incidence_matrix;

    const int left_start = 1;
    const int right_start = (const int) (incidence_matrix.size() + 1);
    const std::vector<std::vector<int>> transposed = transpose(incidence_matrix);

    // Left vertices
    for (int i = 0; i < incidence_matrix.size(); i++) {
        Vertex left_v = Vertex(left_start + i);
        left_nodes_.push_back(left_v);
    }

    // Right vertices
    for (int i = 0; i < transposed.size(); i++) {
        Vertex right_v = Vertex(right_start + i);
        right_nodes_.push_back(right_v);
    }

    // Make edges
    for (int i = 0; i < incidence_matrix.size(); i++) {
        Vertex left_v = left_nodes_[i];
        std::vector<int> row = incidence_matrix[i];

        for (int j = 0; j < row.size(); j++){
            if (incidence_matrix[i][j] == 1){
                Vertex& left = left_nodes_[i];
                Vertex& right = right_nodes_[j];
                Vertex::add_edge(left, right);
            }
        }
    }

    // Left neighbours_
    for (int i = 0; i < incidence_matrix.size(); i++) {
        Vertex left_v = left_nodes_[i];
        left_neighbours_.push_back(left_v.get_neighbours());
    }

    // Right neighbours_
    for (int i = 0; i < transposed.size(); i++) {
        Vertex right_v = right_nodes_[i];
        right_neighbours_.push_back(right_v.get_neighbours());

    }

}

std::vector<std::vector<int>> BipartiteGraph::get_incidence_matrix(){
    return inc_mat_;
}

void BipartiteGraph::print_matrices() {
    print_matrix(inc_mat_);
    std::cout << std::endl;
    //print_matrix(left_neighbours);
    std::cout << std::endl;
    //print_matrix(right_neighbours);
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

void BipartiteGraph::print_set_neighbourhood(const std::vector<std::vector<std::shared_ptr<Vertex>>> &neighbours) {
    for (int i = 0; i < neighbours.size(); i++){
        std::vector<std::shared_ptr<Vertex>> Nv_list = neighbours[i];
        for (int j = 0; j < Nv_list.size(); j++){
            Vertex v = (*Nv_list[j]);
            int label = v.get_label();
            std::cout << label;
        }
        std::cout << std::endl;
    }
}

void BipartiteGraph::print_neighbourhoods() {
    print_set_neighbourhood(left_neighbours_);
    print_set_neighbourhood(right_neighbours_);

}

const std::vector<std::vector<std::shared_ptr<Vertex>>> & BipartiteGraph::get_right_neighbours() {
    return right_neighbours_;
}

const std::vector<std::vector<std::shared_ptr<Vertex>>> & BipartiteGraph::get_left_neighbours() {
    return left_neighbours_;
}

const std::vector<Vertex> & BipartiteGraph::get_left_nodes() {
    return left_nodes_;
}

const std::vector<Vertex> & BipartiteGraph::get_right_nodes() {
    return right_nodes_;
}
