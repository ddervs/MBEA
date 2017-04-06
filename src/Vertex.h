//
// Created by Danial Dervovic on 31/03/2017.
//

#ifndef MBEA_VERTEX_H
#define MBEA_VERTEX_H

#include <memory>
#include <vector>

class Vertex {
public:
    Vertex(int label);

    std::string get_neighbours_string();
    const int& get_label();

    bool operator==(const Vertex &other) const;
    bool operator!=(const Vertex &other) const;
    bool operator>(const Vertex &other) const;
    bool operator<(const Vertex &other) const;

    bool is_neighbour(const Vertex &other) const;

    static void add_edge(Vertex& v1, Vertex& v2);
    static void remove_edge(Vertex& v1, Vertex& v2);
    const std::vector<std::shared_ptr<Vertex>>& get_neighbours();
    int num_neighbours() const;
    int num_neighbours_of_v_in_set(const std::vector<Vertex>& set);
    bool is_member(const std::vector<Vertex>& set) const;


private:
    std::vector<std::shared_ptr<Vertex>> neighbours_;
    void add_neighbour(Vertex& v);
    void remove_neighbour(Vertex& v);
    int v_label_;
};

struct num_neighbours_cmp
{
    inline bool operator() (const Vertex& v1, const Vertex& v2)
    {
        return (v1.num_neighbours() < v2.num_neighbours());
    }
};// comparator function by number of neighbours - overrides default of label

#endif //MBEA_VERTEX_H
