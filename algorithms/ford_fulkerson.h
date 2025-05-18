#ifndef FORD_FULKERSON_H
#define FORD_FULKERSON_H

#include <unordered_map>
#include <string>

class FordFulkerson {
public:
    int maxFlow(std::unordered_map<std::string, std::unordered_map<std::string, int>>& capacity,
                const std::string& source, const std::string& sink);
};

#endif
