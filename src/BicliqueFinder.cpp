//
// Created by Danial Dervovic on 05/04/2017.
//

#include "BicliqueFinder.h"

BicliqueFinder::BicliqueFinder(const BipartiteGraph & graph_in) {

    BipartiteGraph graph = const_cast<BipartiteGraph&>(graph_in);

    L = graph.get_left_nodes();
    P = graph.get_right_nodes();

}
