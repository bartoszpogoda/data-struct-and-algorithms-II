#pragma once

#include "ListGraph.h"
#include "GraphFileData.h"

class ListGraphFileData : public GraphFileData {
	ListGraph* graph;
public:
	ListGraphFileData(ListGraph* graph, int firstVerticle) : graph(graph), GraphFileData(firstVerticle) {}
	ListGraphFileData(std::string errorMessage) : GraphFileData(errorMessage) {}

	ListGraph* getGraph() { return graph; }
};