#include "dijkstra.h"
#include <queue>
#include <set>
#include <climits>
#include <unordered_map>
#include <vector>
#include <algorithm> // Required for std::reverse

PathResult Dijkstra::findShortestPath(
    const std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>& graph,
    const std::string& start,
    const std::string& end
) {
    if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
        return { {}, -1 };
    }
    
    std::unordered_map<std::string, int> dist;
    std::unordered_map<std::string, std::string> prev;
    std::set<std::pair<int, std::string>> pq;
    
    // Initialize distances for all nodes in the graph
    for (const auto& node : graph) {
        dist[node.first] = INT_MAX;
    }
    dist[start] = 0;
    pq.insert({0, start});
    
    while (!pq.empty()) {
        // Get the node with the smallest distance
        auto current = *pq.begin();
        int curDist = current.first;
        std::string u = current.second;
        pq.erase(pq.begin());
        
        if (u == end) break;
        
        // Process neighbors
        if (graph.find(u) != graph.end()) {  // Check if the node exists in the graph
            const auto& neighbors = graph.at(u);
            for (const auto& neighbor : neighbors) {
                std::string v = neighbor.first;
                int weight = neighbor.second;
                
                int alt = curDist + weight;
                if (alt < dist[v]) {
                    // Remove old distance entry if it exists
                    auto it = pq.find({dist[v], v});
                    if (it != pq.end()) {
                        pq.erase(it);
                    }
                    
                    // Update distance and previous node
                    dist[v] = alt;
                    prev[v] = u;
                    pq.insert({alt, v});
                }
            }
        }
    }
    
    // Construct the path
    std::vector<std::string> path;
    if (dist[end] == INT_MAX) {
        return { {}, -1 };  // No path found
    }
    
    // Reconstruct path from end to start
    std::string u = end;
    while (u != start) {
        path.push_back(u);
        if (prev.find(u) == prev.end()) {
            // This shouldn't happen if we verified a path exists
            return { {}, -1 };
        }
        u = prev[u];
    }
    path.push_back(start);
    
    // Reverse to get path from start to end
    std::reverse(path.begin(), path.end());
    
    return { path, dist[end] };
}