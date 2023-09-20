#ifndef ADJACENCY_MATRIX_HPP
#define ADJACENCY_MATRIX_HPP

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> edge;

class AdjacencyMatrix
{
private:
    int num_vertices;
    int num_edges;
    int **matrix;
    int is_directed;

public:
    AdjacencyMatrix(int num_vertices, int is_directed);
    ~AdjacencyMatrix();

    void add_edge(int from, int to, int weight);
    void remove_edge(int from, int to);
    bool has_edge(int from, int to) const;
    int get_degree(int vertex) const;
    int get_vertices_count() const;
    int get_edges_count() const;
    int get_weight(int from, int to) const;
    void set_weight(int from, int to, int weight);
    vector<pair<int,edge>> get_edges() const;
    vector<int> get_vertices() const;
    void print() const;
};

#endif // ADJACENCY_MATRIX_HPP

