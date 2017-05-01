#pragma once

#include "Graph.h"

class GraphFileData {
	Graph* graph;
	int firstVerticle;
public:
	GraphFileData(Graph* graph, int firstVerticle) : graph(graph), firstVerticle(firstVerticle) { }

	Graph* getGraph() { return graph; }
	int getFirstVerticle() { return firstVerticle; }
};