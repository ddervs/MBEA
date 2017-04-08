#include <iostream>
#include <string>
#include "BipartiteGraph.h"
#include <vector>
#include "Vertex.h"
#include "BicliqueFinder.h"
#include <algorithm>
#include <sys/resource.h>
#include <fstream>
#include "CommandLineParser.h"

void print(std::string in_string) {
    std::cout << in_string << std::endl;
}

int main(int argc, char* argv[]) {

    /*
     * Increase stack size
     *
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

    CommandLineParser CLP = CommandLineParser(argc, argv);
    print(CLP.output);

    return 0;
}