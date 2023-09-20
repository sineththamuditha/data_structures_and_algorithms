#include "adjacency_matrix.hpp"
#include <iostream>

using namespace std;

AdjacencyMatrix::AdjacencyMatrix(int num_vertices, int is_directed)
{
    this->num_vertices = num_vertices;
    num_edges = 0;
    this->is_directed = is_directed;

    matrix = new int *[num_vertices];
    for (int i = 0; i < num_vertices; i++)
    {
        matrix[i] = new int[num_vertices];
        for (int j = 0; j < num_vertices; j++)
        {
            matrix[i][j] = -1;
        }
    }
}

AdjacencyMatrix::~AdjacencyMatrix()
{
    for (int i = 0; i < num_vertices; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void AdjacencyMatrix::add_edge(int from, int to, int weight)
{
    if (from < 0 || from >= num_vertices || to < 0 || to >=  num_vertices)
    {
        cerr << "Invalid vertex" << endl;
        return;
    }

    if (matrix[from][to] == -1)
    {
        num_edges++;
    }

    matrix[from][to] = weight;

    if (!is_directed)
    {
        matrix[to][from] = weight;
    }
}

void AdjacencyMatrix::remove_edge(int from, int to)
{
    if (from < 0 || from >= num_vertices || to < 0 || to >=  num_vertices)
    {
        cerr << "Invalid vertex" << endl;
        return;
    }

    if (matrix[from][to] != -1)
    {
        num_edges--;
    }

    matrix[from][to] = -1;

    if (!is_directed)
    {
        matrix[to][from] = -1;
    }
}

bool AdjacencyMatrix::has_edge(int from, int to) const
{
    if (from < 0 || from >= num_vertices || to < 0 || to >=  num_vertices)
    {
        cerr << "Invalid vertex" << endl;
        return false;
    }

    return matrix[from][to] != -1;
}

int AdjacencyMatrix::get_degree(int vertex) const
{
    if (vertex < 0 || vertex >= num_vertices)
    {
        cerr << "Invalid vertex" << endl;
        return -1;
    }

    int degree = 0;
    for (int i = 0; i < num_vertices; i++)
    {
        if (matrix[vertex][i] != -1)
        {
            degree++;
        }
    }

    return degree;
}

int AdjacencyMatrix::get_vertices_count() const
{
    return  num_vertices;
}

int AdjacencyMatrix::get_edges_count() const
{
    return num_edges;
}

int AdjacencyMatrix::get_weight(int from, int to) const
{
    if (from < 0 || from >= num_vertices || to < 0 || to >=  num_vertices)
    {
        cerr << "Invalid vertex" << endl;
        return -1;
    }

    return matrix[from][to];
}

void AdjacencyMatrix::set_weight(int from, int to, int weight)
{
    if (from < 0 || from >= num_vertices || to < 0 || to >=  num_vertices)
    {
        cerr << "Invalid vertex" << endl;
        return;
    }

    matrix[from][to] = weight;

    if (!is_directed)
    {
        matrix[to][from] = weight;
    }
}

vector<pair<int,edge>> AdjacencyMatrix::get_edges() const
{
    vector<pair<int,edge>> edges;
    
    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = !is_directed ? i + 1 : 0; j <  num_vertices; j++)
        {
            if (matrix[i][j] != -1)
            {
                edges.push_back(make_pair(matrix[i][j], make_pair(i, j)));
            }
        }
    }

    return edges;
}

vector<int> AdjacencyMatrix::get_vertices() const
{
    vector<int> vertices;

    for (int i = 0; i < num_vertices; i++)
    {
        vertices.push_back(i);
    }

    return vertices;
}

void AdjacencyMatrix::print() const
{
    cout << "Adjacency Matrix:" << endl;
    cout << "-----------------" << endl;
    cout << "Number of vertices: " <<   num_vertices << endl;
    cout << "Number of edges: " << num_edges << endl;
    cout << "Directed: " << (is_directed ? "Yes" : "No") << endl;
    cout << endl;

    cout << "( from, to) weight" << endl;
    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = !is_directed ? i + 1 : 0; j <  num_vertices; j++)
        {
            if (matrix[i][j] != -1)
            {
                cout << "( " << i << ", " << j << " ) " << matrix[i][j] << endl;
            }
        }
    }
}
