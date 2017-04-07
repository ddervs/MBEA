#include <iostream>
#include "BipartiteGraph.h"
#include <vector>
#include "Vertex.h"
#include "BicliqueFinder.h"
#include <algorithm>
#include <sys/resource.h>


int main() {

    /*
    const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }

    */

    //const std::vector<std::vector<int>> & mat = {{0,1,1}, {1,0,0}, {0,1,0}, {1,1,1}};
    const std::vector<std::vector<int>> & mat = {{0,1,1}, {1,0,0}, {1,0,1}};
    BipartiteGraph graph = BipartiteGraph(mat);
    BicliqueFinder finder = BicliqueFinder(graph);
    std::string algorithm = "improved";

    finder.find_maximal_bicliques(algorithm);

    const std::vector<Biclique>& bicliques = finder.get_maximal_bicliques();
    int num_bicliques = finder.get_num_bicliques();

    std::cout << std::to_string(num_bicliques) << std::endl;



    /*


    Vertex v1 = Vertex(1);
    Vertex v2 = Vertex(2);
    Vertex v3 = Vertex(3);
    Vertex v4 = Vertex(4);

    std::vector<Vertex> P = {1,2,3,4};



    P.erase(std::remove_if(P.begin(), P.end(),
                           [&](Vertex& u) {
                               return v1 == u;
                           }),
            P.end());


    std::cout << std::to_string(P.size()) << std::endl;

     */

    return 0;
}