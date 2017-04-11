//
// Created by Danial Dervovic on 08/04/2017.
//
#include <fstream>
#include "gtest/gtest.h"
#include <string>
#include "CommandLineParser.h"
#include <fstream>
#include <streambuf>


TEST(command_line_parser, help_message) {

    int argc_1 = 1;
    const char *argv_1[] = {"./MBEA", NULL};
    CommandLineParser CLP_1 = CommandLineParser(argc_1, (char **) argv_1);
    ASSERT_EQ(CLP_1.get_output(), CLP_1.get_usage() + "\n");

    int argc_2 = 2;
    const char *argv_2[] = {"./MBEA", "-h", NULL};
    CommandLineParser CLP_2 = CommandLineParser(argc_2, (char **) argv_2);
    ASSERT_EQ(CLP_2.get_output(), CLP_2.get_usage() + "\n");

    int argc_3 = 2;
    const char *argv_3[] = {"./MBEA", "--help", NULL};
    CommandLineParser CLP_3 = CommandLineParser(argc_3, (char **) argv_3);
    ASSERT_EQ(CLP_3.get_output(), CLP_3.get_usage() + "\n");


}

TEST(command_line_parser, correct_algorithm_called) {

    int argc_5 = 3;
    const char *argv_5[] = {"./MBEA", "dummy_input.txt", "improved", NULL};
    CommandLineParser CLP_5 = CommandLineParser(argc_5, (char **) argv_5);
    ASSERT_EQ(CLP_5.get_algorithm(), "improved");

    int argc_6 = 3;
    const char *argv_6[] = {"./MBEA", "dummy_input.txt", "standard", NULL};
    CommandLineParser CLP_6 = CommandLineParser(argc_6, (char **) argv_6);
    ASSERT_EQ(CLP_6.get_algorithm(), "standard");

    int argc_7 = 2;
    const char *argv_7[] = {"./MBEA", "dummy_input.txt", NULL};
    CommandLineParser CLP_7 = CommandLineParser(argc_7, (char **) argv_7);
    ASSERT_EQ(CLP_7.get_algorithm(), "improved");

}

TEST(command_line_parser, bad_inputs) {

    // Not a file
    int argc_4 = 2;
    const char *argv_4[] = {"./MBEA", "not_a_file.txt", NULL};
    CommandLineParser CLP_4 = CommandLineParser(argc_4, (char **) argv_4);
    ASSERT_EQ(CLP_4.get_output(), CLP_4.get_bad_input_str() + "\n" + CLP_4.get_not_file_str() + "\n" + CLP_4.get_usage() + "\n");

    //Not an algorithm
    int argc_5 = 3;
    const char *argv_5[] = {"./MBEA", "dummy_input.txt", "not_algorithm", NULL};
    CommandLineParser CLP_5 = CommandLineParser(argc_5, (char **) argv_5);
    ASSERT_EQ(CLP_5.get_output(), CLP_5.get_bad_input_str() + "\n" + CLP_5.get_alg_error() + "\n" + CLP_5.get_usage() + "\n");

    // Too many args

    int argc_6 = 4;
    const char *argv_6[] = {"./MBEA", "../../tests/files/crown_5_5.txt", "standard", "more_stuff", NULL};
    CommandLineParser CLP_6 = CommandLineParser(argc_6, (char **) argv_6);
    ASSERT_EQ(CLP_6.get_output(), CLP_6.get_bad_input_str() + "\n" + CLP_6.get_too_many_args_str() + "\n" + CLP_6.get_usage() + "\n");

}

TEST(command_line_parser, read_file_to_matrix) {

    int argc = 2;
    const char *argv[] = {"./MBEA", "../../tests/files/random_matrix.txt", NULL};

    CommandLineParser CLP = CommandLineParser(argc, (char **) argv);

    std::vector<std::vector<int>> test_mat = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};

    auto from_class = CLP.read_file_to_matrix(std::string("../../tests/files/random_matrix.txt"));
    ASSERT_EQ(from_class, test_mat);

}


TEST(command_line_parser, full_alg) {

    // Test crown graph as input with correct output

    int argc = 3;
    const char *argv[] = {"./MBEA", "../../tests/files/crown_5_5.txt", "standard", NULL};

    CommandLineParser CLP = CommandLineParser(argc, (char **) argv);

    std::ifstream t("../../tests/files/crown_5_5_output.txt");
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string out_str = buffer.str();

    ASSERT_EQ(out_str, CLP.get_output());
}