#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>
#include <string>
#include <utility> // for std::pair

class Graph {
private:
    // Correctly declared adjacency list
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adjList;

public:
    // Add edge between two stations
    void addEdge(const std::string& from, const std::string& to, int weight);

    // Get the adjacency list (for read-only use)
    const std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>& getAdjList() const;

    // Print all stations
    void printStations() const;
};

#endif // GRAPH_H
