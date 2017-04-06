//
// Created by Danial Dervovic on 05/04/2017.
//

#ifndef MBEA_BICLIQUEFINDER_H
#define MBEA_BICLIQUEFINDER_H

#include "BipartiteGraph.h"
#include "Biclique.h"
#include <vector>

class BicliqueFinder {

public:

    BicliqueFinder(const BipartiteGraph & graph_in);
    std::vector<Biclique>& get_maximal_bicliques();

    std::string get_LRPQ_initial();


    void find_maximal_bicliques(std::string algorithm);


private:

    void biclique_find(std::vector<Vertex> L, std::vector<Vertex> R, std::vector<Vertex> P, std::vector<Vertex>Q);

    void biclique_find_improved(std::vector<Vertex> L, std::vector<Vertex> R, std::vector<Vertex> P, std::vector<Vertex>Q);

    std::vector<Vertex> L_initial_;
    std::vector<Vertex> R_initial_;
    std::vector<Vertex> P_initial_;
    std::vector<Vertex> Q_initial_;

    int i_ = -1;

    BipartiteGraph graph;

    std::vector<Biclique> maximal_bicliques;

    bool found_all = false;
};


#endif //MBEA_BICLIQUEFINDER_H
