//
// Created by Danial Dervovic on 05/04/2017.
//

#include "BicliqueFinder.h"
#include <string>
#include <algorithm>
#include<vector>
#include "Vertex.h"
#include "VertexSet.h"

BicliqueFinder::BicliqueFinder(const BipartiteGraph & graph_in) {

    graph = graph_in;
    L_initial_ = VertexSet(graph.get_left_nodes());
    P_initial_ = VertexSet(graph.get_right_nodes());

    // R, Q initially empty

}

void BicliqueFinder::find_maximal_bicliques(std::string algorithm) {

    if (algorithm == "standard") {
        biclique_find(L_initial_, R_initial_, P_initial_, Q_initial_, i_);
        found_all = true;
    }
    else if (algorithm == "improved") {
        P_initial_.sort_by_num_neighbours();
        biclique_find_improved(L_initial_, R_initial_, P_initial_, Q_initial_, i_);
        found_all = true;
    }
    else {
        throw std::runtime_error("BicliqueFinder::find_maximal_bicliques - call with option standard or improved.");
    }
}

const std::vector<Biclique>& BicliqueFinder::get_maximal_bicliques() {
    if (found_all) {
        return maximal_bicliques;
    }
    else {
        throw std::runtime_error("Need to run find_maximal_bicliques first");
    }
}

std::string BicliqueFinder::get_LRPQ_initial() {

    std::string out;

    for (int i = 0; i < L_initial_.size(); i++){
        out += std::to_string(L_initial_.get_vertex(i).get_label()) + " ";
    }
    out += "\n";
    for (int i = 0; i < R_initial_.size(); i++){
        out += std::to_string(R_initial_.get_vertex(i).get_label()) + " ";
    }
    out += "\n";
    for (int i = 0; i < P_initial_.size(); i++){
        out += std::to_string(P_initial_.get_vertex(i).get_label()) + " ";
    }
    out += "\n";
    for (int i = 0; i < Q_initial_.size(); i++){
        out += std::to_string(Q_initial_.get_vertex(i).get_label()) + " ";
    }
    out += "\n";

    return out;
}

void BicliqueFinder::biclique_find(const VertexSet &L_in, const VertexSet &R_in, const VertexSet &P_in,
                                   const VertexSet &Q_in, int i) {

}

void BicliqueFinder::biclique_find_improved(const VertexSet &L_in, const VertexSet &R_in, const VertexSet &P_in,
                                            const VertexSet Q_in, int i) {

    VertexSet L = L_in;
    VertexSet R = R_in;
    VertexSet P = P_in;
    VertexSet Q = Q_in;


    while(not P.empty()) {
        i++;
        std::cout << "\n----------------\nIteration: i = " + std::to_string(i) + "\n----------------\n" << std::endl;

        std::cout << "P = ";
        print_set(P);

        Vertex x = P.get_vertex(i);
        std::cout << "x = " + std::to_string(x.get_label()) << std::endl;
        VertexSet R_prime = R;
        R_prime.add_vertex(x);
        std::cout << "R\' = ";
        print_set(R_prime);

        VertexSet L_prime;
        VertexSet overline_L_prime;
        VertexSet C;

        for (int j = 0; j < L.size(); j++) {
            Vertex u = L.get_vertex(j);
            if (u.is_neighbour(x)) {
                L_prime.add_vertex(u);
            }
            else {
                overline_L_prime.add_vertex(u);
            }
        }
        C.add_vertex(x);

        std::cout << "L\' = ";
        print_set(L_prime);
        std::cout << "\\overline{L\'} = ";
        print_set(overline_L_prime);
        std::cout << "C = ";
        print_set(C);


        VertexSet P_prime;
        VertexSet Q_prime;

        bool is_maximal = true;

        std::cout << "Q = ";
        print_set(Q);

        for (int j = 0; j < Q.size(); j++) {
            Vertex v = Q.get_vertex(j);
            std::cout << "v = " + std::to_string(v.get_label()) << std::endl;
            int num_L_prime_neighbours = v.num_neighbours_of_v_in_set(L_prime.get_set());

            if (num_L_prime_neighbours == L_prime.size()) {
                is_maximal = false;
                break;
            }
            else if (num_L_prime_neighbours > 0) {
                Q_prime.add_vertex(v);
            }
        }

        std::cout << "Q\' = ";
        print_set(Q_prime);

        std::cout << "is_maximal: " + std::to_string(is_maximal) << std::endl;
    //TODO: More print statements
        if (is_maximal) {
            for (int j = 0; j < P.size(); j++) {
                Vertex v = P.get_vertex(j);
                if(v == x) {
                    continue;
                }

                int num_L_prime_neighbours = v.num_neighbours_of_v_in_set(L_prime.get_set());
                if (num_L_prime_neighbours == L_prime.size()) {
                    R_prime.add_vertex(v);
                    int num_overline_L_prime_neighbours = v.num_neighbours_of_v_in_set(overline_L_prime.get_set());
                    if(num_overline_L_prime_neighbours == 0) {
                        C.add_vertex(v);
                    }
                }
                else if (num_L_prime_neighbours > 0) {
                    P_prime.add_vertex(v);
                }
            }

            Biclique bicliq = Biclique(L_prime.get_set(), R_prime.get_set());
            bicliq.is_maximal = true;
            maximal_bicliques.push_back(bicliq);

            if (not P_prime.empty()) {
                biclique_find(L_prime, R_prime, P_prime, Q_prime, i_);
            }
        }
        for (int j = 0; j < C.size(); j++) {

            Vertex v = C.get_vertex(j);
            Q.add_vertex(v);
            P.remove_vertex(v);

        }
        std::cout << std::endl;
    }
}

int BicliqueFinder::get_num_bicliques() {
    if (found_all) {
        return (int) maximal_bicliques.size();
    }
    else {
        throw std::runtime_error("Need to run find_maximal_bicliques first");
    }
}

void BicliqueFinder::print_set(const VertexSet &set) {
    VertexSet new_set = const_cast<VertexSet&>(set);
    std::cout << new_set.to_string() << std::endl;
}

