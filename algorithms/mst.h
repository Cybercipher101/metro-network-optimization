#ifndef MST_H
#define MST_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class MST {
public:
    void primMST(const std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>& graph);
};

#endif
