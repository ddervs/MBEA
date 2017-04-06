//
// Created by Danial Dervovic on 06/04/2017.
//

#ifndef MBEA_BICLIQUE_H
#define MBEA_BICLIQUE_H


#include "BipartiteGraph.h"

class Biclique : public BipartiteGraph{

public:

    Biclique(const std::vector<std::vector<int>> &incidence_matrix);
    Biclique(const std::vector<Vertex>& left_vertices, const std::vector<Vertex>& right_vertices);

    bool is_maximal;

private:

};


#endif //MBEA_BICLIQUE_H
