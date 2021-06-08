#pragma once
#include <vector>
#include "graph.h"
#include <list>

class Path
{
private:
    std::list<std::pair<int, int>> edges_list;

public:
    void BellmanFord(std::vector<std::vector<int>> weight_matrix, int amount_of_vertices, int start_vertex);
    void BellmanFord(std::vector<std::vector<Edge>> adjency_list, int amount_of_vertices, int start_vertex);
};
