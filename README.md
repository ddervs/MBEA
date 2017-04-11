MBEA: Maximal Biclique Enumeration Algorithm
=================

C++ Implementation of the algorithm presented in the paper:

[ On finding bicliques in bipartite graphs: a novel algorithm and its application to the integration of diverse biological data types. Y Zhang et al. BMC Bioinformatics 2014 15:110 ](http://bmcbioinformatics.biomedcentral.com/articles/10.1186/1471-2105-15-110 "MBEA paper")

Usage Instructions
----------
Default usage:
```
    ./MBEA location/of/graph_file.txt algorithm
```

- `algorithm`: either `standard` for MBEA or `improved` for iMBEA.

- `graph_file.txt` is the 0-1 biadjacency matrix of a bipartite graph, where the rows index the left vertex partition and the columns index the right partition.
Example: the matrix
```
0 1
1 1
1 0

```
encodes the adjacency relations `1->5`, `2->4`, `2->5`, `3->4`, where the left vertices have labels `{1,2,3}` and the right vertices have labels `{4,5}`. 

_NOTE: elements must be space separated, one and only one newline should be at the end of the file_.

The output to `stderr` employs this vertex labelling when describing the maximal bicliques.


Build Instructions
----------
Tested on Mac OSX 10.12.2 with clang-802.0.41 and gcc 6.3.0.

Make sure you have [CMake](https://cmake.org) 3.6 or higher installed.
From the main `MBEA` directory:
- `mdkdir cmake-build-debug; cd cmake-build-debug`
- `ccmake ..` Configure your build options. If you're happy with default, simply do `cmake..`.
- `make` After your build completes, move the `MBEA` executable to wherever is most convenient to you.
