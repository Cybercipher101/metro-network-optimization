#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <string>
#include <vector>
#include <unordered_map>
#include <utility> // for std::pair

struct PathResult {
    std::vector<std::string> path;
    int distance;
};

class Dijkstra {
public:
    PathResult findShortestPath(
        const std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>& graph,
        const std::string& start,
        const std::string& end
    );
};

#endif
