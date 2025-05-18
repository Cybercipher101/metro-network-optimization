#include "mst.h"
#include <queue>
#include <set>

void MST::primMST(const std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>& graph) {
    if (graph.empty()) return;

    std::set<std::string> visited;
    auto comp = [](auto& a, auto& b) { return a.second > b.second; };
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, decltype(comp)> pq(comp);

    std::string start = graph.begin()->first;
    pq.push({start, 0});
    int totalCost = 0;

    while (!pq.empty()) {
        auto node = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if (visited.find(node) != visited.end()) continue;

        visited.insert(node);
        std::cout << "Visited: " << node << " (Cost: " << cost << ")\n";
        totalCost += cost;

        for (const auto& neighbor : graph.at(node)) {
            if (visited.find(neighbor.first) == visited.end()) {
                pq.push({neighbor.first, neighbor.second});
            }
        }
    }

    std::cout << "Total cost of MST: " << totalCost << "\n";
}
