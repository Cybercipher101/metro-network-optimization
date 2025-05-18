#include "csv_reader.h"
#include <fstream>
#include <sstream>
#include <iostream>

void loadMetroMap(const std::string& filename, Graph& graph, bool useTime) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open " << filename << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // skip header
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string from, to, distanceStr, timeStr, route;

        std::getline(ss, from, ',');
        std::getline(ss, to, ',');
        std::getline(ss, distanceStr, ',');
        std::getline(ss, timeStr, ',');
        std::getline(ss, route, ',');

        int weight = useTime ? std::stoi(timeStr) : static_cast<int>(std::stof(distanceStr));
        graph.addEdge(from, to, weight);
    }
}