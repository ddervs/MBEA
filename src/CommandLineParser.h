//
// Created by Danial Dervovic on 08/04/2017.
//

#ifndef MBEA_COMMANDLINEPARSER_H
#define MBEA_COMMANDLINEPARSER_H


class CommandLineParser {

public:
    CommandLineParser(int argc, char* argv[]);

    std::vector<std::vector<int>> read_file_to_matrix(std::string filename);

    std::string get_output();
    std::string get_usage();
    std::string get_too_many_args_str();
    std::string get_not_file_str();
    std::string get_bad_input_str();
    std::string get_alg_error();
    std::string get_algorithm();
    std::vector<std::vector<int>> get_matrix_in();

private:
    std::string too_many_args_str = std::string("MBEA Error: too many arguments.");
    std::string not_file_str;
    std::string bad_input_str = "MBEA Error: bad input file";

    std::string err_string = "MBEA Error: Invalid input";
    std::string alg_error = "MBEA Error: Invalid algorithm specified.";
    std::string algorithm;

    std::string output;

    void append_to_output(std::string to_append);
    void parse_filename(std::string filename);

    unsigned long read_numbers(const std::string &s, std::vector<int> &v);

    std::vector<std::vector<int>> matrix_in;

    std::string usage =
            "MBEA default usage:\n"
                    "```\n"
                    "    ./MBEA location/of/graph_file.txt algorithm\n"
                    "```\n"
                    "\n"
                    "- `algorithm`: either `standard` for MBEA or `improved` for iMBEA.\n"
                    "\n\n"
                    "- `graph_file.txt` is the 0-1 biadjacency matrix of a bipartite graph, where the rows index the left vertex partition and the columns index the right partition.\n"
                    "Example: the matrix\n"
                    "```\n"
                    "0 1\n"
                    "1 1\n"
                    "1 0\n"
                    "\n"
                    "```\n"
                    "encodes the adjacency relations `1->5`, `2->4`, `2->5`, `3->4`, where the left vertices have labels `{1,2,3}` and the right vertices have labels `{4,5}`. \n"
                    "\n"
                    "__ NOTE: elements must be space separated, one and only one newline should be at the end of the file. __\n\n"
                    " The output to `stderr` employs this vertex labelling when describing the maximal bicliques.";

};


#endif //MBEA_COMMANDLINEPARSER_H
