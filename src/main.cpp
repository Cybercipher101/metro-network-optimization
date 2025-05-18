#include <iostream>
#include <string>
#include <limits>
#include "../include/graph.h"
#include "utils/csv_reader.h"
// Ensure the CSVReader class is defined in the included header file.
#include "../algorithms/dijkstra.h"
#include "../algorithms/mst.h"
#include "../algorithms/ford_fulkerson.h"

void displayMenu()
{
    std::cout << "\n==== Dehradun Metro Network Optimization System ====\n";
    std::cout << "1. Find Shortest Path (Dijkstra's Algorithm)\n";
    std::cout << "2. Show All Stations\n";
    std::cout << "3. Show MST (Prim's Algorithm)\n";
    std::cout << "4. Show Max Flow (Ford-Fulkerson)\n";
    std::cout << "0. Exit\n";
    std::cout << "Select an option: ";
}

int main()
{
    Graph graph;
    CSVReader reader;
    std::string filename = "data/dehradun_public_transport_data.csv";

    // Load graph from CSV
    if (!reader.loadCSV(filename, graph))
    {
        std::cerr << "Error loading metro data.\n";
        return 1;
    }

    Dijkstra dijkstra;
    MST mst;
    FordFulkerson ff;

    int option;
    do
    {
        displayMenu();
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (option == 1)
        {
            std::string source, destination;
            std::cout << "Enter source station: ";
            std::getline(std::cin, source);
            std::cout << "Enter destination station: ";
            std::getline(std::cin, destination);
            dijkstra.findShortestPath(graph.getAdjList(), source, destination);
        }
        else if (option == 2)
        {
            graph.printStations();
        }
        else if (option == 3)
        {
            mst.primMST(graph.getAdjList());
        }
        else if (option == 4)
        {
            std::string source, sink;
            std::cout << "Enter source station: ";
            std::getline(std::cin, source);
            std::cout << "Enter sink station: ";
            std::getline(std::cin, sink);

            // Construct unit capacity graph
            std::unordered_map<std::string, std::unordered_map<std::string, int>> capacity;

            const auto &adj = graph.getAdjList();
            for (auto it = adj.begin(); it != adj.end(); ++it)
            {
                const std::string &u = it->first;
                const std::vector<std::pair<std::string, int>> &neighbors = it->second;
                for (size_t i = 0; i < neighbors.size(); ++i)
                {
                    const std::string &v = neighbors[i].first;
                    capacity[u][v] = 1;
                }
            }

            int maxflow = ff.maxFlow(capacity, source, sink);
            std::cout << "Maximum flow from " << source << " to " << sink << " is " << maxflow << "\n";
        }
        else if (option != 0)
        {
            std::cout << "Invalid option! Please try again.\n";
        }
    } while (option != 0);

    std::cout << "Thank you for using the Metro Optimization System.\n";
    return 0;
}
