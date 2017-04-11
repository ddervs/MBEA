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

    // TODO: proper usage string - add to README.md
    std::string usage = "MBEA Usage instructions...";
    std::string err_string = "MBEA Error: Invalid input";
    std::string alg_error = "MBEA Error: Invalid algorithm specified.";
    std::string algorithm;

    std::string output;

    void append_to_output(std::string to_append);
    void parse_filename(std::string filename);

    unsigned long read_numbers(const std::string &s, std::vector<int> &v);

    std::vector<std::vector<int>> matrix_in;


};


#endif //MBEA_COMMANDLINEPARSER_H
