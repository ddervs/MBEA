//
// Created by Danial Dervovic on 05/04/2017.
//

#include "BicliqueFinder.h"
#include <algorithm>


int ipow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

BicliqueFinder::BicliqueFinder(const BipartiteGraph & graph_in) {

    graph = graph_in;
    L_initial_ = VertexSet(graph.get_left_nodes());
    P_initial_ = VertexSet(graph.get_right_nodes());

    // R, Q initially empty

    int n = (int) std::min(L_initial_.size(), P_initial_.size());
    max_number_possible = ipow(2, n) - 2;
}

void BicliqueFinder::find_maximal_bicliques(std::string algorithm) {

    if (algorithm == "standard") {
        biclique_find(L_initial_, R_initial_, P_initial_, Q_initial_);
        found_all = true;
    }
    else if (algorithm == "improved") {
        P_initial_.sort_by_num_neighbours();
        biclique_find_improved(L_initial_, R_initial_, P_initial_, Q_initial_);
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
        out += std::to_string((*L_initial_.get_vertex(i)).get_label()) + " ";
    }
    out += "\n";
    for (int i = 0; i < R_initial_.size(); i++){
        out += std::to_string((*R_initial_.get_vertex(i)).get_label()) + " ";
    }
    out += "\n";
    for (int i = 0; i < P_initial_.size(); i++){
        out += std::to_string((*P_initial_.get_vertex(i)).get_label()) + " ";
    }
    out += "\n";
    for (int i = 0; i < Q_initial_.size(); i++){
        out += std::to_string((*Q_initial_.get_vertex(i)).get_label()) + " ";
    }
    out += "\n";

    return out;
}

void BicliqueFinder::biclique_find(const VertexSet &L_in, const VertexSet &R_in, const VertexSet &P_in, const VertexSet &Q_in) {

    VertexSet L = L_in;
    VertexSet R = R_in;
    VertexSet P = P_in;
    VertexSet Q = Q_in;

    while(not P.empty()) {
        std::shared_ptr<Vertex> x = P.get_vertex(0);
        VertexSet R_prime = R;
        R_prime.add_vertex(x);

        VertexSet L_prime;

        for (int j = 0; j < L.size(); j++) {
            std::shared_ptr<Vertex> u = L.get_vertex(j);
            if ((*u).is_neighbour(*x)) {
                L_prime.add_vertex(u);
            }

        }


        VertexSet P_prime;
        VertexSet Q_prime;

        bool is_maximal = true;

        for (int j = 0; j < Q.size(); j++) {
            std::shared_ptr<Vertex> v = Q.get_vertex(j);
            int num_L_prime_neighbours = (*v).num_neighbours_of_v_in_set(L_prime.get_set());

            if (num_L_prime_neighbours == L_prime.size()) {
                is_maximal = false;
                break;
            }
            else if (num_L_prime_neighbours > 0) {
                Q_prime.add_vertex(v);
            }
        }

        if (is_maximal) {
            for (int j = 0; j < P.size(); j++) {
                std::shared_ptr<Vertex> v = P.get_vertex(j);
                if(v == x) {
                    continue;
                }

                int num_L_prime_neighbours = (*v).num_neighbours_of_v_in_set(L_prime.get_set());
                if (num_L_prime_neighbours == L_prime.size()) {
                    R_prime.add_vertex(v);
                }
                else if (num_L_prime_neighbours > 0) {
                    P_prime.add_vertex(v);
                }
            }

            Biclique bicliq = Biclique(L_prime.get_set(), R_prime.get_set());
            bicliq.is_maximal = true;
            maximal_bicliques.push_back(bicliq);

            //std::cout << "Found " + std::to_string(maximal_bicliques.size()) + " out of a possible " + std::to_string(max_number_possible) + " maximal bicliques." << std::endl;

            if (not P_prime.empty()) {
                biclique_find(L_prime, R_prime, P_prime, Q_prime);
            }

        }
        P.remove_vertex(x);
        Q.add_vertex(x);
    }

}

void BicliqueFinder::biclique_find_improved(const VertexSet &L_in, const VertexSet &R_in, const VertexSet &P_in, const VertexSet Q_in) {

    VertexSet L = L_in;
    VertexSet R = R_in;
    VertexSet P = P_in;
    VertexSet Q = Q_in;

    while(not P.empty()) {

        std::shared_ptr<Vertex> x = P.get_vertex(0);
        VertexSet R_prime = R;
        R_prime.add_vertex(x);

        VertexSet L_prime;
        VertexSet overline_L_prime = L;
        VertexSet C;

        for (int j = 0; j < L.size(); j++) {
            std::shared_ptr<Vertex> u = L.get_vertex(j);
            if ((*u).is_neighbour(*x)) {
                L_prime.add_vertex(u);
                overline_L_prime.remove_vertex(u);
            }

        }

        C.add_vertex(x);

        VertexSet P_prime;
        VertexSet Q_prime;

        bool is_maximal = true;

        for (int j = 0; j < Q.size(); j++) {
            std::shared_ptr<Vertex> v = Q.get_vertex(j);
            int num_L_prime_neighbours = (*v).num_neighbours_of_v_in_set(L_prime.get_set());

            if (num_L_prime_neighbours == L_prime.size()) {
                is_maximal = false;
                break;
            }
            else if (num_L_prime_neighbours > 0) {
                Q_prime.add_vertex(v);
            }
        }

        if (is_maximal) {
            for (int j = 0; j < P.size(); j++) {
                std::shared_ptr<Vertex> v = P.get_vertex(j);
                if(v == x) {
                    continue;
                }

                int num_L_prime_neighbours = (*v).num_neighbours_of_v_in_set(L_prime.get_set());
                if (num_L_prime_neighbours == L_prime.size()) {
                    R_prime.add_vertex(v);
                    int num_overline_L_prime_neighbours = (*v).num_neighbours_of_v_in_set(overline_L_prime.get_set());
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

            //std::cout << "Found " + std::to_string(maximal_bicliques.size()) + " out of a possible " + std::to_string(max_number_possible) + " maximal bicliques." << std::endl;

            if (not P_prime.empty()) {
                biclique_find_improved(L_prime, R_prime, P_prime, Q_prime);
            }

        }
        for (int j = 0; j < C.size(); j++) {

            std::shared_ptr<Vertex> v = C.get_vertex(j);
            Q.add_vertex(v);
            P.remove_vertex(v);

        }
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

std::string BicliqueFinder::to_string() {
    if (found_all) {
        std::string out;
        for (int i = 0; i < maximal_bicliques.size(); i++) {
            auto biclique = maximal_bicliques[i];
            out += biclique.to_string();
            out += "\n";
        }
        return out;
    }
    else {
        throw std::runtime_error("Need to run find_maximal_bicliques first");
    }
}

