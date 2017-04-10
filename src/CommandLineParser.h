//
// Created by Danial Dervovic on 08/04/2017.
//

#ifndef MBEA_COMMANDLINEPARSER_H
#define MBEA_COMMANDLINEPARSER_H


struct CommandLineParser {

    CommandLineParser(int argc, char* argv[]);

    std::string too_may_args_str = std::string("MBEA Error: too many arguments.");
    std::string not_file_str;
    std::string bad_input_str = "MBEA Error: bad input file";

    std::string usage = "MBEA Usage instructions...";
    std::string err_string = "MBEA Error: Invalid input";
    std::string alg_error = "MBEA Error: Invalid algorithm specified.";

    std::string output;

    void append_to_output(std::string to_append);
    void parse_filename(std::string filename, std::string algorithm);

    std::vector<std::vector<int>> read_file_to_matrix(std::string filename);

    unsigned long ReadNumbers( const std::string & s, std::vector<int> & v );

    std::vector<std::vector<int>> matrix_in;

};


#endif //MBEA_COMMANDLINEPARSER_H
