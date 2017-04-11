//
// Created by Danial Dervovic on 08/04/2017.
//

#include <iostream>
#include <string>
#include "BipartiteGraph.h"
#include <vector>
#include "Vertex.h"
#include "BicliqueFinder.h"
#include <algorithm>
#include <sys/resource.h>
#include <fstream>
#include <sstream>
#include "CommandLineParser.h"


CommandLineParser::CommandLineParser(int argc, char **argv) {

    if (argc == 1) {
        append_to_output(usage);
    }
    else if (argc == 2) {

        std::string arg = argv[1];

        if ((arg == "-h") or (arg == "--help")) {
            append_to_output(usage);
        }

        else {

            not_file_str = std::string("MBEA error: " + arg + " is not a file.");
            algorithm = "improved";
            parse_filename(arg);

        }

    }

    else if (argc == 3) {

        std::string arg1 = argv[1];
        std::string arg2 = argv[2];
        not_file_str = std::string("MBEA error: " + arg1 + " is not a file.");

        if ((arg2 == "improved") or (arg2 == "standard")) {

            algorithm = arg2;
            parse_filename(arg1);

        }
        else {
            append_to_output(bad_input_str);
            append_to_output(alg_error);
            append_to_output(usage);
        }
    }

    else {

        append_to_output(bad_input_str);
        append_to_output(too_many_args_str);
        append_to_output(usage);

    }

}

void CommandLineParser::parse_filename(std::string filename) {

    std::ifstream file(filename);

    if (file.good()) {

        try {

            /* Is a file */

            // Read in file
            matrix_in = read_file_to_matrix(filename);

            // Find Bicliques
            BicliqueFinder finder = BicliqueFinder(BipartiteGraph(matrix_in));
            finder.find_maximal_bicliques(algorithm);

            // Print to stderr
            append_to_output("\nNumber of maximal bicliques:\n" + std::to_string(finder.get_num_bicliques()) + "\n");
            append_to_output("List of maximal bicliques:\n" + finder.to_string());

        }

        catch (const std::exception& e) {
            append_to_output(bad_input_str);
            append_to_output (e.what());
            append_to_output(usage);
        }
    }
    else {
        append_to_output(bad_input_str);
        append_to_output(not_file_str);
        append_to_output(usage);
    }
}

void CommandLineParser::append_to_output(std::string to_append) {
    output += to_append + "\n";
}

std::vector<std::vector<int>> CommandLineParser::read_file_to_matrix(std::string filename) {

    std::ifstream file;
    std::vector<int> v;
    std::string line;

    file.open(filename, std::ifstream::in);

    if (file.is_open())
    {
        getline(file, line);

        unsigned long cols = read_numbers(line, v);

        unsigned long rows = 0;

        for (unsigned long i = 1; i < 2147483647; i++){

            if ( not getline(file, line) ) {
                rows = i;
                break;
            }

            read_numbers(line, v);

        }

        if (rows > 	2147483647) {
            append_to_output("N must be smaller than MAX_UNSIGNED_LONG");
        }

        file.close();
        std::vector<std::vector<int>> mat(rows, std::vector<int>(cols, 0));

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                mat[i][j] = v[i * cols + j];
            }
        }

        return mat;
    }

    else{
         append_to_output("file open failed");
    }

}

unsigned long CommandLineParser::read_numbers(const std::string &s, std::vector<int> &v) {
    std::istringstream is( s );
    int n;
    while( is >> n ) {
        v.push_back( n );
    }
    return v.size();
}

std::string CommandLineParser::get_output() {
    return output;
}

std::string CommandLineParser::get_usage() {
    return usage;
}

std::string CommandLineParser::get_too_many_args_str() {
    return too_many_args_str;
}

std::string CommandLineParser::get_not_file_str() {
    return not_file_str;
}

std::string CommandLineParser::get_bad_input_str() {
    return bad_input_str;
}

std::string CommandLineParser::get_alg_error() {
    return alg_error;
}

std::vector<std::vector<int>> CommandLineParser::get_matrix_in() {
    return matrix_in;
}

std::string CommandLineParser::get_algorithm() {
    return algorithm;
}

