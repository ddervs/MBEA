#include <iostream>
#include "src/BipartiteGraph.h"
#include <vector>


int main() {

    std::vector<std::vector<int>> mat = {{0,1,1}, {1,0,0}, {0,1,0}};
    BipartiteGraph graph = BipartiteGraph(mat);
    graph.print_matrices();
    return 0;
}