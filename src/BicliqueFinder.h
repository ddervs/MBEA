//
// Created by Danial Dervovic on 05/04/2017.
//

#ifndef MBEA_BICLIQUEFINDER_H
#define MBEA_BICLIQUEFINDER_H

#include "BipartiteGraph.h"
#include <vector>

class BicliqueFinder {

public:

    BicliqueFinder(const BipartiteGraph & graph_in);

    //std::vector<Biclique>

private:

    std::vector<Vertex> L;
    std::vector<Vertex> R;
    std::vector<Vertex> P;
    std::vector<Vertex> Q;

};


#endif //MBEA_BICLIQUEFINDER_H
