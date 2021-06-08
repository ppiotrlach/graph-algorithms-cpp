#include <iostream>
#include <fstream>
#include "../lib/graph.h"
#include "../lib/mst.h"
#include "../lib/path.h"

using namespace std;

static int get_input_from_user()
{

    bool isInputCorrect = false;
    bool minus = false;
    string input;

    while (!isInputCorrect)
    {
        isInputCorrect = true;
        cin >> input;
        for (char const &c : input)
        {
            if (std::isdigit(c) == 0)
            {
                if (c == '-' && !minus)
                {
                    minus = true;
                }
                else
                {
                    isInputCorrect = false;
                    cout << "incorrect input, try again" << endl
                         << ">";
                    break;
                }
            }
        }
    }

    return stoi(input); //parse string to int
}

static void main_menu()
{
    cout << endl;
    cout << "SELECT THE NUMBER OF THE OPERATION YOU ARE INTERESTED IN" << endl;
    cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_" << endl
         << endl;

    cout << "1. Read graph from file" << endl;
    cout << "2. Print weight graph and adjency list" << endl;
    cout << "3. MST - Prim's algorithm" << endl;
    cout << "4. Shortest Path - Bellman-Ford algorithm" << endl;
    cout << "5. End program" << endl;
    cout << endl
         << ">";
}

static void no_graph_loaded()
{
    cout << "ERR0R - load the graph first" << endl;
}

int main()
{
    Graph undirected_graph, directed_graph;
    MST mst;
    Path path;

    int choice;
    bool stay_in_loop = true;

    string filename = "graph.txt";

    int amount_of_edges, amount_of_vertices, start_vertex, end_vertex, edge_weight, v1, v2;

    while (stay_in_loop)
    {
        main_menu();
        choice = get_input_from_user();
        switch (choice)
        {
        case 1:
            while (stay_in_loop)
            {
                bool read_graph = true;

                if (undirected_graph.get_size() > 0)
                    cout << "0. THIS ACTION WILL OVERWRITE THE OLD GRAPH (type 0 to go back)" << endl;
                cout << "1.Load own data" << endl;
                cout << "2.Load creator data (you can just edit graph.txt, its attached to the project)" << endl
                     << ">";

                choice = get_input_from_user();
                switch (choice)
                {
                case 0:
                    stay_in_loop = false;
                    read_graph = false;
                    break;

                case 1:
                    cout << "Drag and drop your file with data into project folder and enter your filename.txt" << endl
                         << ">";
                    cin >> filename;
                    stay_in_loop = false;
                    break;
                case 2:
                    stay_in_loop = false;
                    break;
                default:
                    cout << "incorrect input, enter 1 or 2" << endl;
                    break;
                }
                if (read_graph)
                {
                    ifstream file(filename);
                    string line;

                    if (file.is_open())
                    {
                        file >> amount_of_edges;
                        file >> amount_of_vertices;
                        file >> start_vertex;
                        file >> end_vertex;

                        undirected_graph.set_amount_of_vertices(amount_of_vertices);
                        directed_graph.set_amount_of_vertices(amount_of_vertices);

                        for (int i = 0; i < amount_of_edges; i++)
                        {
                            file >> v1;
                            file >> v2;
                            file >> edge_weight;

                            undirected_graph.add_edge_to_adjency_list(v1, v2, edge_weight);
                            undirected_graph.add_edge_to_matrix(v1, v2, edge_weight);

                            undirected_graph.add_edge_to_adjency_list(v2, v1, edge_weight);
                            undirected_graph.add_edge_to_matrix(v2, v1, edge_weight);

                            directed_graph.add_edge_to_adjency_list(v1, v2, edge_weight);
                            directed_graph.add_edge_to_matrix(v1, v2, edge_weight);
                        }

                        cout << "Graph loaded" << endl
                             << endl;
                    }
                    else
                    {
                        cout << "Can not open file, restart the program and try again" << endl;
                        return -1;
                    }
                    file.close();
                }
                stay_in_loop = false;
            }
            stay_in_loop = true;
            break;
        case 2:
            cout << "Directed graph" << endl
                 << "-----------"
                 << endl;
            directed_graph.print_adjency_list();
            cout << endl;
            directed_graph.print_weight_matrix();
            cout << endl
                 << endl;
            cout << "Undirected graph" << endl
                 << "-----------" << endl;
            undirected_graph.print_adjency_list();
            cout << endl;
            undirected_graph.print_weight_matrix();
            cout << endl;

            break;
        case 3:
            if (undirected_graph.get_size() == 0)
                no_graph_loaded();
            else
            {
                stay_in_loop = true;
                while (stay_in_loop)
                {
                    cout << "1.Weight matrix" << endl;
                    cout << "2.Adjency list" << endl
                         << ">";
                    choice = get_input_from_user();
                    switch (choice)
                    {
                    case 1:
                        mst.Prim(undirected_graph.get_weight_matrix(), amount_of_vertices);
                        stay_in_loop = false;
                        break;
                    case 2:
                        mst.Prim(undirected_graph.get_adjency_list(), amount_of_vertices);
                        stay_in_loop = false;
                        break;
                    default:
                        cout << "incorrect input, enter 1 or 2" << endl;
                        break;
                    }
                }
                stay_in_loop = true;
            }
            break;
        case 4:
            if (undirected_graph.get_size() == 0)
                no_graph_loaded();
            else
            {
                stay_in_loop = true;
                while (stay_in_loop)
                {
                    cout << "1.Weight matrix" << endl;
                    cout << "2.Adjency list" << endl
                         << ">";
                    choice = get_input_from_user();
                    switch (choice)
                    {
                    case 1:
                        path.BellmanFord(undirected_graph.get_weight_matrix(), amount_of_vertices, start_vertex);
                        stay_in_loop = false;
                        break;
                    case 2:
                        path.BellmanFord(undirected_graph.get_adjency_list(), amount_of_vertices, start_vertex);
                        stay_in_loop = false;
                        break;
                    default:
                        cout << "incorrect input, enter 1 or 2" << endl;
                        break;
                    }
                }
                stay_in_loop = true;
            }
            break;
        case 5:
            stay_in_loop = false;
            break;

        default:
            break;
        }
    }

    return 0;
}
