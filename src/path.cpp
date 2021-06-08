#include "../lib/path.h"
#include <iostream>

using namespace std;

void Path::BellmanFord(vector<vector<int>> weight_matrix, int amount_of_vertices, int start_vertex)
{
    //-1 represents no parent
    vector<int> ancestors(amount_of_vertices, -1);

    int infinity = INT32_MAX;

    vector<int> path_cost(amount_of_vertices, infinity);

    path_cost[start_vertex] = 0;

    for (int i = 0; i < amount_of_vertices - 1; i++)
    {
        for (int j = 0; j < amount_of_vertices; j++)
        {
            for (int x = 0; x < amount_of_vertices; x++)
            {
                if (j != x && weight_matrix[j][x] != infinity)
                {

                    int v1 = j;
                    int v2 = x;
                    int weight = weight_matrix[j][x];

                    if (path_cost[v1] != infinity && path_cost[v1] + weight < path_cost[v2])
                    {
                        path_cost[v2] = path_cost[v1] + weight;
                        ancestors[v2] = v1;
                    }
                }
            }
        }
    }

    bool negative_cycle = false;

    // detecting negative cycle
    for (int j = 0; j < amount_of_vertices; j++)
    {
        for (int x = 0; x < amount_of_vertices; x++)
        {

            if (j != x && weight_matrix[j][x] != infinity)
            {
                int v1 = j;
                int v2 = x;
                int weight = weight_matrix[j][x];

                if (path_cost[v1] != infinity && path_cost[v1] + weight < path_cost[v2])
                {
                    negative_cycle = true;
                }
            }
        }
    }

    if (negative_cycle)
        cout << "ERR0R - detected negative cycle!" << endl;

    cout << "Bellman-Ford algorithm - weight matrix" << endl;
    cout << "Path from source [" << start_vertex << "] to " << endl;
    for (int i = 0; i < amount_of_vertices; i++)
    {

        string path_to_vertex_str = "";
        cout << "dest [" << i << "] : cost = " << path_cost[i] << " : path : ";
        int ancestor = i;

        do
        {
            path_to_vertex_str = " -> " + to_string(ancestor) + path_to_vertex_str;
            ancestor = ancestors[ancestor];
        } while (ancestor != -1);

        cout
            << path_to_vertex_str << endl;
    }

    return;
}

void Path::BellmanFord(vector<vector<Edge>> adjency_list, int amount_of_vertices, int start_vertex)
{
    //-1 represents no parent
    vector<int> ancestors(amount_of_vertices, -1);

    int infinity = INT32_MAX;

    vector<int> path_cost(amount_of_vertices, infinity);

    path_cost[start_vertex] = 0;

    for (int i = 0; i < amount_of_vertices - 1; i++)
    {
        for (int j = 0; j < amount_of_vertices; j++)
        {
            for (int x = 0; x < adjency_list[j].size(); x++)
            {

                int v1 = j;
                int v2 = adjency_list[j][x].v2;
                int weight = adjency_list[j][x].weight;

                if (path_cost[v1] != infinity && path_cost[v1] + weight < path_cost[v2])
                {
                    path_cost[v2] = path_cost[v1] + weight;
                    ancestors[v2] = v1;
                }
            }
        }
    }

    bool negative_cycle = false;

    //detecting negative cycle
    for (int j = 0; j < amount_of_vertices; j++)
    {
        for (int x = 0; x < adjency_list[j].size(); x++)
        {

            int v1 = j;
            int v2 = adjency_list[j][x].v2;
            int weight = adjency_list[j][x].weight;

            if (path_cost[v1] != infinity && path_cost[v1] + weight < path_cost[v2])
            {
                negative_cycle = true;
            }
        }
    }

    if (negative_cycle)
        cout << "ERR0R - detected negative cycle!" << endl;

    cout << "Bellman-Ford algorithm - adjency list" << endl;
    cout << "Path from source [" << start_vertex << "] to " << endl;
    for (int i = 0; i < amount_of_vertices; i++)
    {

        string path_to_vertex_str = "";
        cout << "dest [" << i << "] : cost = " << path_cost[i] << " : path : ";
        int ancestor = i;

        do
        {
            path_to_vertex_str = " -> " + to_string(ancestor) + path_to_vertex_str;
            ancestor = ancestors[ancestor];
        } while (ancestor != -1);

        cout
            << path_to_vertex_str << endl;
    }

    return;
}
