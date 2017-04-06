//
// Created by Danial Dervovic on 05/04/2017.
//

#include "BicliqueFinder.h"
#include <string>
#include <algorithm>
#include "Vertex.h"

BicliqueFinder::BicliqueFinder(const BipartiteGraph & graph_in) {

    graph = graph_in;
    L_initial_ = graph.get_left_nodes();
    P_initial_ = graph.get_right_nodes();

    // R, Q initially empty

}

void BicliqueFinder::find_maximal_bicliques(std::string algorithm) {

    if (algorithm == "standard") {
        biclique_find(L_initial_, R_initial_, P_initial_, Q_initial_);
        found_all = true;
    }
    else if (algorithm == "improved") {
        // sort initial P in non-decreasing order of neighbourhood size
        std::sort(P_initial_.begin(), P_initial_.end(), num_neighbours_cmp());
        biclique_find_improved(L_initial_, R_initial_, P_initial_, Q_initial_);
        found_all = true;
    }
    else {
        throw std::runtime_error("BicliqueFinder::find_maximal_bicliques - call with option standard or improved.");
    }
}

std::vector<Biclique> &BicliqueFinder::get_maximal_bicliques() {
    if (found_all) {
        return maximal_bicliques;
    }
    else {
        throw std::runtime_error("Need to run find_maximal_bicliques first");
    }
}

void BicliqueFinder::biclique_find(std::vector<Vertex> L, std::vector<Vertex> R, std::vector<Vertex> P, std::vector<Vertex> Q) {

}

void BicliqueFinder::biclique_find_improved(std::vector<Vertex> L, std::vector<Vertex> R, std::vector<Vertex> P,
                                            std::vector<Vertex> Q) {

}

std::string BicliqueFinder::get_LRPQ_initial() {

    std::string out;

    for (int i = 0; i < L_initial_.size(); i++){
        out += std::to_string(L_initial_[i].get_label()) + " ";
    }
    out += "\n";
    for (int i = 0; i < R_initial_.size(); i++){
        out += std::to_string(R_initial_[i].get_label()) + " ";
    }
    out += "\n";
    for (int i = 0; i < P_initial_.size(); i++){
        out += std::to_string(P_initial_[i].get_label()) + " ";
    }
    out += "\n";
    for (int i = 0; i < Q_initial_.size(); i++){
        out += std::to_string(Q_initial_[i].get_label()) + " ";
    }
    out += "\n";

    return out;
}
