#include "../include/graph.h"

void Graph::addEdge(const std::string& from, const std::string& to, int weight) {
    adjList[from].push_back({to, weight});
    adjList[to].push_back({from, weight});
}

const std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>& Graph::getAdjList() const {
    return adjList;
}

void Graph::printStations() const {
    std::cout << "Stations in the network:\n";
    for (const auto& pair : adjList) {
        std::cout << "- " << pair.first << std::endl;
    }
}
