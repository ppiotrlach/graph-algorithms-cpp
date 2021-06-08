#pragma once
#include <vector>
#include "graph.h"
#include <list>

class MST
{
private:
    std::list<std::pair<int, int>> edges_list;

public:
    void Prim(std::vector<std::vector<int>> weight_matrix, int amount_of_vertices);
    void Prim(std::vector<std::vector<Edge>> adjency_list, int amount_of_vertices);
};
