#ifndef CSV_READER_H
#define CSV_READER_H

#include "../include/graph.h"
#include <string>

void loadMetroMap(const std::string& filename, Graph& graph, bool useTime);

#endif