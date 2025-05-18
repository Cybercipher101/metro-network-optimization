#include "ford_fulkerson.h"
#include <queue>
#include <climits>
#include <unordered_map>
#include <vector>

bool bfs(const std::unordered_map<std::string, std::unordered_map<std::string, int>>& residual,
         const std::string& source, const std::string& sink,
         std::unordered_map<std::string, std::string>& parent) {
    std::queue<std::string> q;
    q.push(source);
    parent.clear();
    parent[source] = std::string();

    while (!q.empty()) {
        std::string u = q.front(); q.pop();
        for (const auto& [v, cap] : residual.at(u)) {
            if (!parent.count(v) && cap > 0) {
                parent[v] = u;
                if (v == sink) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int FordFulkerson::maxFlow(std::unordered_map<std::string, std::unordered_map<std::string, int>>& capacity,
                           const std::string& source, const std::string& sink) {
    auto residual = capacity;
    std::unordered_map<std::string, std::string> parent;
    int flow = 0;

    while (bfs(residual, source, sink, parent)) {
        int path_flow = INT_MAX;
        std::string s = sink;
        while (s != source) {
            std::string u = parent[s];
            path_flow = std::min(path_flow, residual[u][s]);
            s = u;
        }

        s = sink;
        while (s != source) {
            std::string u = parent[s];
            residual[u][s] -= path_flow;
            residual[s][u] += path_flow;
            s = u;
        }

        flow += path_flow;
    }

    return flow;
}
