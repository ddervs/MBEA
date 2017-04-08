//
// Created by Danial Dervovic on 05/04/2017.
//

#ifndef MBEA_BICLIQUEFINDER_H
#define MBEA_BICLIQUEFINDER_H

#include "BipartiteGraph.h"
#include "Biclique.h"
#include "VertexSet.h"
#include <vector>

class BicliqueFinder {

public:

    BicliqueFinder(const BipartiteGraph & graph_in);
    const std::vector<Biclique>& get_maximal_bicliques();
    int get_num_bicliques();

    std::string get_LRPQ_initial();

    std::string to_string();

    void find_maximal_bicliques(std::string algorithm);

    void print_set(const VertexSet &set);

    int max_number_possible;

private:

    void biclique_find(const VertexSet &L_in, const VertexSet &R_in, const VertexSet &P_in, const VertexSet &Q_in);

    void biclique_find_improved(const VertexSet &L_in, const VertexSet &R_in,
                                const VertexSet &P_in, const VertexSet Q_in);


    VertexSet L_initial_;
    VertexSet R_initial_;
    VertexSet P_initial_;
    VertexSet Q_initial_;

    int i_ = -1;

    BipartiteGraph graph;

    std::vector<Biclique> maximal_bicliques;

    bool found_all = false;
};


#endif //MBEA_BICLIQUEFINDER_H
