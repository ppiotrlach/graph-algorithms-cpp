#include "../lib/mst.h"
#include "../lib/graph.h"
#include <iostream>
#include <queue>

using namespace std;

void MST::Prim(vector<vector<int>> weight_matrix, int amount_of_vertices)
{

    bool visited[amount_of_vertices];

    for (int i = 0; i < amount_of_vertices; i++)
    {
        visited[i] = false;
    }

    priority_queue<Edge, vector<Edge>, CompareWeight> min_edges_heap;

    int in_vertex = 0;

    int min_cost = 0;
    int infinity = INT32_MAX;

    Edge temp_edge;

    std::cout << "Minimum Spanning Tree - Prim's Algorithm [on weight matrix]:" << endl
              << endl
              << "List of edges:" << endl;

    for (int i = 0; i < amount_of_vertices - 1; i++)
    {
        visited[in_vertex] = true;

        for (int j = 0; j < amount_of_vertices; j++)
        {

            if (weight_matrix[in_vertex][j] < infinity && visited[j] == false)
            {
                temp_edge.v1 = in_vertex;
                temp_edge.v2 = j;
                temp_edge.weight = weight_matrix[in_vertex][j];
                min_edges_heap.push(temp_edge);
            }
        }
        do
        {
            temp_edge = min_edges_heap.top();
            min_edges_heap.pop();
        } while (visited[temp_edge.v2] = false && !min_edges_heap.empty());

        visited[temp_edge.v2] = true;
        in_vertex = temp_edge.v2;

        printf("%d - %d : %d \n", temp_edge.v1, temp_edge.v2, temp_edge.weight);
        min_cost += temp_edge.weight;
    }
    visited[in_vertex] = true;
    std::cout << endl
              << "total edge weight = " << min_cost << endl;

    for (int i = 0; i < amount_of_vertices; i++)
    {
        if (visited[i] == false)
        {
            std::cout << "ERR0R - there is no mst for this graph" << endl;
            break;
        }
    }
}

void MST::Prim(vector<vector<Edge>> adjency_list, int amount_of_vertices)
{

    bool visited[amount_of_vertices];

    for (int i = 0; i < amount_of_vertices; i++)
    {
        visited[i] = false;
    }

    priority_queue<Edge, vector<Edge>, CompareWeight> min_edges_heap;

    int in_vertex = 0;

    int min_cost = 0;
    int infinity = INT32_MAX;

    Edge temp_edge;

    std::cout << "Minimum Spanning Tree - Prim's Algorithm [on adjency list]:" << endl
              << endl
              << "List of edges:" << endl;

    for (int i = 0; i < amount_of_vertices - 1; i++)
    {
        visited[in_vertex] = true;

        for (int j = 0; j < adjency_list[in_vertex].size(); j++)
        {

            if (visited[adjency_list[in_vertex][j].v2] == false)
            {
                temp_edge.v1 = in_vertex;
                temp_edge.v2 = adjency_list[in_vertex][j].v2;
                temp_edge.weight = adjency_list[in_vertex][j].weight;
                min_edges_heap.push(temp_edge);
            }
        }
        do
        {
            temp_edge = min_edges_heap.top();
            min_edges_heap.pop();
        } while (visited[temp_edge.v2] = false && !min_edges_heap.empty());

        visited[temp_edge.v2] = true;
        in_vertex = temp_edge.v2;

        printf("%d - %d : %d \n", temp_edge.v1, temp_edge.v2, temp_edge.weight);
        min_cost += temp_edge.weight;
    }
    visited[in_vertex] = true;
    std::cout << endl
              << "total edge weight = " << min_cost << endl;

    for (int i = 0; i < amount_of_vertices; i++)
    {
        if (visited[i] == false)
        {
            std::cout << "ERR0R - there is no mst for this graph" << endl;
            break;
        }
    }
}